#pragma once
#include <cstdint>

struct Position
{
	int32_t x;
	int32_t y;

	Position(int32_t x, int32_t y)
		: x(x), y(y) {}

	Position& operator+=(const Position& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Position& operator-=(const Position& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Position& operator=(const Position& other)
	{
		if (this == &other) return *this;
		x = other.x;
		y = other.y;
		return *this;
	}
};