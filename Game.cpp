#include "Game.h"

Game::Game()
	:
	window(std::make_unique<sf::RenderWindow>(sf::VideoMode(900, 600), "Snake")),
	board(*window, (int)window->getSize().x / 30, (int)window->getSize().y / 30), // TODO: Refactor
	mt(std::random_device{}()),
	fruit_manager(mt, { (int)window->getSize().x / 30, (int)window->getSize().y / 30 }) // TODO: Refactor
{
	window->setFramerateLimit(60);
	//load_config_window();
}


void Game::run()
{
	while (window->isOpen())
	{
		poll_events();
		update();
		render();
	}
}

void Game::render()
{
	window->clear();
	board.render_contents();
	snake.render(board);
	window->display();
}

void Game::update()
{
	if (current_time <= 0.f)
	{
		current_time = pause;
		snake.update(0.0f);
	}
	current_time -= .5f;
	fruit_manager.update(board);
}

void Game::poll_events()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::load_config_window()
{
	std::ifstream stream("Config/window.config");
	stream >> config;
}