#include <sstream>

#include "DebugScreen.h"
#include "DevelopState.h"

#ifdef debugging

DebugScreen::DebugScreen() {
	_font.loadFromFile("fonts/BebasNeue-Regular.ttf");

	_playerPosition.setFont(_font);
	_playerPosition.setCharacterSize(20);
	_playerPosition.setFillColor(sf::Color::White);
	_playerPosition.setString("Player -> x: 0, y: 0");
	_playerPosition.setPosition(10.0f, 10.0f);

	_mouseWindowPosition.setFont(_font);
	_mouseWindowPosition.setCharacterSize(20);
	_mouseWindowPosition.setFillColor(sf::Color::White);
	_mouseWindowPosition.setString("Mouse window -> x: 0, y: 0");
	_mouseWindowPosition.setPosition(10.0f, 40.0f);

	_mouseWorldPosition.setFont(_font);
	_mouseWorldPosition.setCharacterSize(20);
	_mouseWorldPosition.setFillColor(sf::Color::White);
	_mouseWorldPosition.setString("Mouse world -> x: 0, y: 0");
	_mouseWorldPosition.setPosition(10.0f, 70.0f);

	_fps.setFont(_font);
	_fps.setCharacterSize(20);
	_fps.setFillColor(sf::Color::White);
	_fps.setString("FPS -> 0");
	_fps.setPosition(10.0f, 100.0f);
}

void DebugScreen::setPlayerPosition(sf::Vector2f position) {
	std::stringstream ss;
	ss << "Player -> x: " << position.x << " y: " << position.y;
	_playerPosition.setString(ss.str());
}

void DebugScreen::setMouseWindowPosition(sf::Vector2i position) {
	std::stringstream ss;
	ss << "Mouse window -> x: " << position.x << " y: " << position.y;
	_mouseWindowPosition.setString(ss.str());
}

void DebugScreen::setMouseWorldPosition(sf::Vector2f position) {
	std::stringstream ss;
	ss << "Mouse world -> x: " << position.x << " y: " << position.y;
	_mouseWorldPosition.setString(ss.str());
}

void DebugScreen::setFPS(float fps) {
	std::stringstream ss;
	ss << "FPS -> " << fps;
	_fps.setString(ss.str());
}

void DebugScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_playerPosition);
	target.draw(_mouseWindowPosition);
	target.draw(_mouseWorldPosition);
	target.draw(_fps);
}

#endif