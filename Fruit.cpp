#include "Fruit.h"

Fruit::Fruit(const Position& pos)
	:
	pos(pos)
{
}
const Position& Fruit::get_position() const
{
	return pos;
}