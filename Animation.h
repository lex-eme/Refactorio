#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"

class Animation {
private:
	const sf::Texture* _texture = nullptr;
	Direction _direction = Direction::SOUTH;
	sf::IntRect _frame;

	float _frameDuration = 0.04f;
	float _currentTime = 0.0f;
	int _frameIndex = 0;
	int _maxIndex = 0;

public:
	Animation() = default;

	void init(const sf::Texture& texture, sf::Vector2i frameSize, float frameDuration, int framesInAnim);

	void applyFrame(sf::Sprite& sprite) const;
	void applyTexture(sf::Sprite& sprite) const;

	void update(Direction direction, float dt);
};

