#pragma once
#include "Location.h"
#include "Board.h"
#include "Colors.h"
#include "Snake.h"
#include "Rand_generator.h"

class Obstacle {

public:
	Obstacle(int xx, int yy) : loc({ xx,yy }) {}
	void Draw(Board& brd) const { brd.DrawCell(loc, c); }
	Location get_loc() const { return loc; }
	Obstacle new_obstacle(Rand_int& rnd, Snake& snake, const Location& fruit, const Board& brd);

private:
	Location loc;
	Color c { Colors::Magenta };
};
