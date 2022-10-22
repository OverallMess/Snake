#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <string>
#include <random>

#include "WindowConfig.h"
#include "Board.h"
#include "Position.h"
#include "Snake.h"
#include "FruitManager.h"

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
	std::mt19937 mt;
	window_config config;
	std::unique_ptr<sf::RenderWindow> window;
	Board board;
	Snake snake;
	FruitManager fruit_manager;


	static constexpr float pause = 2.f;
	float current_time = pause;
};

