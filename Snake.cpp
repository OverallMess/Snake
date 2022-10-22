#include "Snake.h"

Snake::Snake()
{
    segments.push_back(Segment{ head_pos });
    segments.push_back(Segment{ head_pos });
    segments.push_back(Segment{ head_pos });
    segments.push_back(Segment{ head_pos });
    segments.push_back(Segment{ head_pos });
}

const Position& Snake::get_position() const
{
    return head_pos;
}
void Snake::render(Board& brd) const
{
    brd.render(head_pos, head_color);
    segments_render(brd);
}

void Snake::update(float dt)
{
    update_input();
    segments_follow();
    head_pos += dir;
}

void Snake::update_input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        dir = { -1, 0 };
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        dir = { 1, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        dir = { 0, -1 };
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        dir = { 0, 1 };
}

void Snake::segments_render(Board& brd) const
{
    for (const auto& seg : segments)
    {
        seg.render(brd);
    }
}

Snake::Segment::Segment(const Position& position)
    :
    segment_pos(position)
{

}

void Snake::segments_follow()
{
    int size = segments.size() - 1;
    for (int i = size; i > 0; --i)
    {
        segments[i].segment_pos = segments[i - 1].segment_pos;
    }
    segments[0].segment_pos = head_pos;
}

void Snake::Segment::render(Board& brd) const
{
    brd.render(segment_pos, segment_color);
}