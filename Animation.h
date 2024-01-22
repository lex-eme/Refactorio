#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
	void start(bool loop = false);
	void pause();
	void stop();
	void reset();
	void update(float dt, sf::Sprite& sprite);
	void init(const sf::Texture& texture, float frameDuration, unsigned int x, unsigned int y, sf::Sprite& sprite);

private:
	bool _enabled = false;
	bool _loop = false;

	float _timeSinceLastFrame = 0.0f;
	float _frameDuration = 1.0f;
	unsigned int _frameIndex = 0;
	std::vector<sf::IntRect> _frames;
	
	const sf::Texture* _texture = nullptr;
};
