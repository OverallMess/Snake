#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"

class Board
{
public:
	enum class ContentType
	{
		Empty, Fruit, Obstacle, Poison
	};
public:
	Board() = default;
	Board(sf::RenderTarget& target, int32_t width, int32_t height);
	void render_contents();
	void add_content(const Position& pos, ContentType type);
	bool check_collision_with(const Position& pos, ContentType type);
	void render(const Position& pos, sf::Color color);
private:
private:
	int32_t width;
	int32_t height;
	static constexpr float cell_size = 30.f;
	sf::RectangleShape rect;
	sf::RenderTarget& target;
	std::vector<ContentType> contents;
};