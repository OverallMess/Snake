#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"

class Board
{
public:
	Board() = default;
	Board(sf::RenderTarget& target);
	void render(const Position& pos, sf::Color color);
private:
	sf::RectangleShape rect;
	sf::RenderTarget& target;
	static constexpr float cell_size = 30.f;
};