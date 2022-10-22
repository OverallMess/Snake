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

void FruitManager::update()
{
	if (fruit_current_timer <= 0)
	{
		fruit_current_timer = fruit_spawn_timer;
		std::cout << x_dist(mt) << " " << y_dist(mt) << std::endl;
		fruits.emplace_back(Position{ x_dist(mt), y_dist(mt) });
	}
	fruit_current_timer -= fruit_spawn_speed;
}
void FruitManager::render(Board& brd)
{
	for (const auto& fruit : fruits)
	{
		fruit.render(brd);
	}
}