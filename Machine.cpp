#include "Machine.h"
#include "TextureHolder.h"

Machine::Machine() {
	_animation.init(TextureHolder::getTexture("graphics/assembling.png"), 0.1f, 8, 4, _sprite);
}

void Machine::update(float dt) {
	_animation.update(dt, _sprite);
}

void Machine::toggle() {
	_running = !_running;

	if (_running) {
		_animation.start(true);
	} else {
		_animation.pause();
	}
}

void Machine::init(sf::Vector2f position) {
	_position = position;
	_sprite.setPosition(_position);
}

sf::Vector2f Machine::getCenter() const {
	return sf::Vector2f(_position.x, _position.y);
}

void Machine::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite);
}
