#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"
#include "Board.h"

class Snake
{
public:
	Snake();
	void render(Board& brd) const;
	void update(float dt);
private:
	class Segment
	{
	public:
		Segment(const Position& position);
		void render(Board& brd) const;
	public:
		Position segment_pos{ 0, 0 };
		const sf::Color segment_color{ sf::Color::Green };
	};
	void update_input();
	void segments_follow();
	void segments_render(Board& brd) const;
private:
	std::vector<Segment> segments;
	Position head_pos{ 0, 0 };
	Position dir{ 1, 0 };
	const sf::Color head_color{ sf::Color::Yellow };
};