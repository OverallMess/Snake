#include "FruitManager.h"
#include <iostream>

FruitManager::FruitManager(std::mt19937& mt, const Position& bounds)
	:
	mt(mt),
	bounds(bounds)
{
	x_dist = std::uniform_int_distribution<int>(0, bounds.x);
	y_dist = std::uniform_int_distribution<int>(0, bounds.y);
}

void FruitManager::update(Board& brd)
{
	if (fruit_current_timer <= 0)
	{
		fruit_current_timer = fruit_spawn_timer;
		//std::cout << x_dist(mt) << " " << y_dist(mt) << std::endl;
		brd.set_content({ x_dist(mt), y_dist(mt) }, Board::ContentType::Fruit);
	}
	fruit_current_timer -= fruit_spawn_speed;
}
