#pragma once
#include "Fruit.h"
#include <vector>
#include <random>

class FruitManager
{
public:
	FruitManager(std::mt19937& mt, const Position& bounds);
	void update();
	void render(Board& brd);
private:
	Position bounds;
	std::mt19937& mt;
	std::uniform_int_distribution<int> x_dist;
	std::uniform_int_distribution<int> y_dist;

	static constexpr float fruit_spawn_timer = 100.f;
	static constexpr float fruit_spawn_speed = 1.f;
	float fruit_current_timer = fruit_spawn_timer;

	std::vector<Fruit> fruits;
};