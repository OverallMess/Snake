#pragma once
#include <cstdint>
#include <fstream>

struct window_config
{
	std::string title;
	uint16_t width = 0;
	uint16_t height = 0;
};

static std::ifstream& operator>>(std::ifstream& in, window_config& config)
{
	in >> config.title >> config.width >> config.height;
	return in;
}