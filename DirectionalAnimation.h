#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Direction.h"

class DirectionalAnimation {
private:
	const sf::Texture* _texture = nullptr;
	Direction _direction = Direction::SOUTH;

	float _frameDuration = 0.04f;
	float _currentTime = 0.0f;
	int _frameIndex = 0;
	int _maxIndex = 0;
	std::vector<sf::IntRect> _frames;

public:
	DirectionalAnimation() = default;

	void init(const sf::Texture& texture, float frameDuration, unsigned int x, unsigned int y, sf::Sprite& sprite);

	void applyFrame(sf::Sprite& sprite) const;
	void applyTexture(sf::Sprite& sprite) const;

	void update(Direction direction, float dt, sf::Sprite& sprite);
};
