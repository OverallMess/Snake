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

    //std::uniform_int_distribution<int> dist(0, 255);

    //for (uint32_t x = 0; x < 900 / 30; ++x)
    //{
    //    for (uint32_t y = 0; y < 600 / 30; ++y)
    //    {
    //        sf::Color color(dist(mt), dist(mt), dist(mt));
    //        board.render({ x, y }, color);
    //    }
    //}
    board.render(pos, sf::Color::Green);

    window->display();
}

void Game::update()
{
    if (current_time <= 0.f)
    {
        current_time = pause;
        pos.operator+=(dir);
    }
    current_time -= .5f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        dir = { -1, 0 };
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        dir = { 1, 0 };
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        dir = { 0, -1 };
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        dir = { 0, 1 };
    }
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