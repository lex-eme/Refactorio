#pragma once

#include <SFML/Graphics.hpp>

#include "DevelopState.h"

#ifdef debugging

class DebugScreen : public sf::Drawable {
public:
	DebugScreen();

	void setPlayerPosition(sf::Vector2f position);
	void setMouseWindowPosition(sf::Vector2i position);
	void setMouseWorldPosition(sf::Vector2f position);
	void setFPS(float fps);

private:
	sf::Font _font;

	sf::Text _playerPosition;
	sf::Text _mouseWindowPosition;
	sf::Text _mouseWorldPosition;
	sf::Text _fps;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif