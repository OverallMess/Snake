#include "Board.h"
#include <iostream>

Board::Board(sf::RenderTarget& target, int32_t width, int32_t height)
	: 
	target(target),
	width(width),
	height(height),
	contents(width * height, ContentType::Empty)
{
	rect.setSize(sf::Vector2f(cell_size, cell_size));
}

void Board::render(const Position& pos, sf::Color color)
{
	rect.setPosition(pos.x * cell_size, pos.y * cell_size);
	rect.setFillColor(color);
	target.draw(rect);
}

void Board::render_contents()
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			switch (contents[y * width + x])
			{
			case ContentType::Fruit:
				render({ x, y }, sf::Color::Red);
				break;
			}
		}
	}
}

void Board::add_content(const Position& pos, ContentType type)
{
	std::cout << pos.x << " " << pos.y << std::endl;
	if (pos.y >= 20 || pos.x >= 30) return;
	contents[pos.y * width + pos.x] = type;
}
bool Board::check_collision_with(const Position& pos, ContentType type)
{
	return contents[pos.y * width + pos.x] == type;
}
