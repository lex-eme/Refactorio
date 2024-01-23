#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Direction.h"
#include "Animation.h"

class DirectionalAnimation : public Animation {
public:
	void setDirection(Direction direction, sf::Sprite sprite);
	void applyTexture(sf::Sprite& sprite) const;

private:
	Direction _direction = Direction::SOUTH;
	unsigned int _maxIndex = 22; // How to set this up?

	int endIndex() const override;
	int restartIndex() const override;
};
