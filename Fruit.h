#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Board.h"

class Fruit
{
public:
	Fruit(const Position& bounds);
	const Position& get_position() const;
private:
	Position pos;
	const sf::Color color{ sf::Color::Red };
};