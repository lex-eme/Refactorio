#include "Engine.h"
#include "DevelopState.h"

void Engine::input() {
	sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
		}

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }

			if (event.key.code == sf::Keyboard::Space) {
				_machine.toggle();
			}
        }

		if (event.type == sf::Event::Resized) {
			_playerView.setSize((float)event.size.width, (float)event.size.height);
		}

		if (event.type == sf::Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.delta < 0) {
				_playerView.zoom(2.0f);
			} else {
				_playerView.zoom(0.5f);
			}
		}
    }

	_player.handleInput();
}

void Engine::update(float dt) {
	_machine.update(dt);
	_player.update(dt);
	_playerView.setCenter(_player.getCenter());

#ifdef debugging
	_window.setView(_playerView);
	_debugScreen.setPlayerPosition(_player.getCenter());
	_debugScreen.setMouseWindowPosition(sf::Mouse::getPosition(_window));
	_debugScreen.setMouseWorldPosition(_window.mapPixelToCoords(sf::Mouse::getPosition(_window)));
	_debugScreen.setFPS(1 / dt);
#endif
}

void Engine::draw() {
	_window.clear(sf::Color::Black);

	_window.setView(_playerView);
    _window.draw(_map);

	_window.draw(_machine);
	_window.draw(_player);

	_window.setView(_window.getDefaultView());
#ifdef debugging
	_window.draw(_debugScreen);
#endif
    _window.display();

}

Engine::Engine() {
	_window.create(sf::VideoMode(1920, 1080), "Refactorio");
    _window.setVerticalSyncEnabled(true);
	
	_map.load(sf::Vector2u(128, 128), 100, 100);

	auto size = _map.getSize();
	_machine.init(sf::Vector2f(size.x / 2, size.y / 2));
	_player.init(sf::Vector2f(size.x / 2, size.y / 2));
	
	_playerView.setSize(sf::Vector2f(1920, 1080));
	_playerView.setCenter(_player.getCenter());
}

void Engine::run() {
	sf::Clock clock;

	while (_window.isOpen()) {
		sf::Time dt = clock.restart();

		input();
		update(dt.asSeconds());
		draw();
	}
}
