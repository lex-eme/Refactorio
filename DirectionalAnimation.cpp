#include "DirectionalAnimation.h"

void DirectionalAnimation::setDirection(Direction direction, sf::Sprite sprite) {
	if (_direction != direction) {
		_direction = direction;
		_frameIndex = (int)direction * _maxIndex;
		_timeSinceLastFrame = 0.0f;
		sprite.setTextureRect(_frames[_frameIndex]);
	}
}

void DirectionalAnimation::applyTexture(sf::Sprite& sprite) const {
	sprite.setTexture(*_texture);
	sprite.setTextureRect(_frames[_frameIndex]);
}

int DirectionalAnimation::endIndex() const {
	return ((int)_direction * _maxIndex) + _maxIndex;
}

int DirectionalAnimation::restartIndex() const {
	return (int)_direction * _maxIndex;
}
