#include "Board.h"

Board::Board(sf::RenderTarget& target)
	: target(target)
{
	rect.setFillColor(sf::Color::Blue);
	rect.setSize(sf::Vector2f(cell_size, cell_size));
}

void Board::render(const Position& pos, sf::Color color)
{
	rect.setPosition(pos.x * cell_size, pos.y * cell_size);
	rect.setFillColor(color);
	target.draw(rect);
}