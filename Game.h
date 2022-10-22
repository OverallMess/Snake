#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <string>
#include <random>

#include "WindowConfig.h"
#include "Board.h"
#include "Position.h"

class Game
{
public:
	Game();
	void run();
private:
	void render();
	void update();
	void poll_events();
	void load_config_window();
private:
	window_config config;
	std::unique_ptr<sf::RenderWindow> window;
	Board board;

	std::mt19937 mt;

	Position pos{ 0, 0 };
	Position dir{ 1, 0 };
	static constexpr float pause = 1.f;
	float current_time = pause;
};

