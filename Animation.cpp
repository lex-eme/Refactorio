#include "Animation.h"

void Animation::start(bool loop) {
	_loop = loop;
	_enabled = true;
}

void Animation::pause() {
	_enabled = false;
}

void Animation::stop() {
	_enabled = false;
	reset();
}

void Animation::reset() {
	_frameIndex = restartIndex();
	_timeSinceLastFrame = 0.0f;
}

void Animation::update(float dt, sf::Sprite& sprite) {
	if (!_enabled) {
		return;
	}

	_timeSinceLastFrame += dt;
	while (_timeSinceLastFrame >= _frameDuration) {
		_frameIndex += 1;
		_timeSinceLastFrame -= _frameDuration;

		if (_frameIndex >= endIndex()) {
			if (_loop) {
				_frameIndex = restartIndex();
			} else {
				stop();
				return;
			}
		}

		sprite.setTextureRect(_frames[_frameIndex]);
	}
}

void Animation::init(const sf::Texture& texture, float frameDuration, unsigned int x, unsigned int y, sf::Sprite& sprite) {
	_texture = &texture;
	_frameDuration = frameDuration;

	sf::Vector2u size = texture.getSize();
	sf::Vector2i frameSize(size.x / x, size.y / y);

	_frames.resize(x * y);

	for (unsigned int i = 0; i < _frames.size(); ++i) {
		int _x = i % x;
		int _y = i / x;
		_frames[i].left = _x * frameSize.x;
		_frames[i].top = _y * frameSize.y;
		_frames[i].width = frameSize.x;
		_frames[i].height = frameSize.y;
	}

	_frameIndex = restartIndex();
	sprite.setTexture(texture);
	sprite.setTextureRect(_frames[_frameIndex]);
	sprite.setOrigin(frameSize.x / 2.0f, frameSize.y / 2.0f);
}

int Animation::endIndex() const {
	return _frames.size();
}

int Animation::restartIndex() const {
	return 0;
}
