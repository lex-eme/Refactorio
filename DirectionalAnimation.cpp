#include "DirectionalAnimation.h"

void DirectionalAnimation::init(const sf::Texture& texture, float frameDuration, unsigned int x, unsigned int y, sf::Sprite& sprite) {
	_texture = &texture;
	_frameDuration = frameDuration;

	sf::Vector2u size = texture.getSize();
	sf::Vector2i frameSize(size.x / x, size.y / y);

	_maxIndex = x;

	_frames.resize(x * y);

	for (unsigned int i = 0; i < _frames.size(); ++i) {
		int _x = i % x;
		int _y = i / x;
		_frames[i].left = _x * frameSize.x;
		_frames[i].top = _y * frameSize.y;
		_frames[i].width = frameSize.x;
		_frames[i].height = frameSize.y;
	}

	_frameIndex = (int)_direction * _maxIndex;

	sprite.setTexture(texture);
	sprite.setTextureRect(_frames[_frameIndex]);
	sprite.setOrigin(frameSize.x / 2.0f, frameSize.y / 2.0f);
}

void DirectionalAnimation::applyFrame(sf::Sprite& sprite) const {
	sprite.setOrigin(_frames[_frameIndex].width / 2.0f, _frames[_frameIndex].height / 2.0f);
	sprite.setTextureRect(_frames[_frameIndex]);
}

void DirectionalAnimation::applyTexture(sf::Sprite& sprite) const {
	sprite.setTexture(*_texture);
}

void DirectionalAnimation::update(Direction direction, float dt, sf::Sprite& sprite) {
	if (_direction != direction) {
		_direction = direction;
		_frameIndex = (int)direction * _maxIndex;
		_currentTime = 0.0f;
		sprite.setTextureRect(_frames[_frameIndex]);
		return;
	}

	_currentTime += dt;
	while (_currentTime >= _frameDuration) {
		_frameIndex += 1;

		if (_frameIndex >= ((int)direction * _maxIndex) + _maxIndex) {
			_frameIndex = (int)direction * _maxIndex;
		}

		_currentTime -= _frameDuration;
		sprite.setTextureRect(_frames[_frameIndex]);
	}
}
