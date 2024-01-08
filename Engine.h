#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "TileMap.h"

class Engine {
private:
	sf::RenderWindow _window;
	sf::View _playerView;

	Player _player;
	TileMap _map;

	void input();
	void update(float dt);
	void draw();

public:
	Engine();
	void run();
};

