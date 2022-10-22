#include "Fruit.h"

Fruit::Fruit(const Position& pos)
	:
	pos(pos)
{
}

void Fruit::render(Board& brd) const
{
	brd.render(pos, color);
}