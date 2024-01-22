#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Machine.h"
#include "TileMap.h"
#include "DebugScreen.h"

class Engine {
private:
	sf::RenderWindow _window;
#ifdef debugging
	DebugScreen _debugScreen;
#endif
	sf::View _playerView;

	Player _player;
	Machine _machine;
	TileMap _map;

	void input();
	void update(float dt);
	void draw();

public:
	Engine();
	void run();
};

