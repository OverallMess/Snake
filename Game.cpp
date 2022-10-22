#include "Game.h"

Game::Game()
    :
    window(std::make_unique<sf::RenderWindow>(sf::VideoMode(900, 600), "snake")),
    board(*window),
    mt(std::random_device{}())
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