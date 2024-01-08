#include "Animation.h"

void Animation::init(const sf::Texture& texture, sf::Vector2i frameSize, float frameDuration, int framesInAnim) {
	_texture = &texture;
	_frame = { 0, (int)_direction * frameSize.y, frameSize.x, frameSize.y };
	_frameDuration = frameDuration;
	_maxIndex = framesInAnim;
}

void Animation::applyFrame(sf::Sprite& sprite) const {
	sprite.setTextureRect(_frame);
}

void Animation::applyTexture(sf::Sprite& sprite) const {
	sprite.setTexture(*_texture);
}

void Animation::update(Direction direction, float dt) {
	_currentTime += dt;

	if (_direction != direction) {
		_direction = direction;
		_frame.top = (int)direction * _frame.height;
	}

	while (_currentTime >= _frameDuration) {
		_frameIndex += 1;
		_frameIndex = _frameIndex % _maxIndex;

		_frame.left = _frameIndex * _frame.width;

		_currentTime -= _frameDuration;
	}
}
