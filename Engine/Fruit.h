#pragma once
#include "Keyboard.h"
#include "Colors.h"
#include "Board.h"
#include "Location.h"
#include "Snake.h"
#include "Rand_generator.h"
#include "Obstacles.h"
#include <vector>

class Fruit
{
public:
	Fruit(int xx, int yy);
	void Draw(Board& brd) const;
	void update();
	void reset_position(Rand_int& rnd,  Snake& snake, const Board& brd, std::vector<Obstacle>o);
	Location get_loc() const { return loc; }
	Color& get_color() { return c; }

	void set_color(Color cc) { c = cc; }

private:
	Location loc;
	static Color c;
};