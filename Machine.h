#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.h"

class Machine : public sf::Drawable {
public:
	Machine();
	void update(float dt);
	void toggle();
	void init(sf::Vector2f position);
	sf::Vector2f getCenter() const;

private:
	sf::Sprite _sprite;
	sf::Vector2f _position;
	Animation _animation;

	bool _running = false;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

