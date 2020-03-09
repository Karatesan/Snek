#include "Fruit.h"

Fruit::Fruit(int xx, int yy)
	: loc{ Location{xx, yy} }
{
}

void Fruit::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Fruit::update()
{
	static unsigned int increment = 5;
	get_color().SetG(get_color().GetG() + increment);
	get_color().SetB(get_color().GetB() + increment);
	if (get_color().GetG() == 255 || get_color().GetG() == 0) increment = -increment;
}

void Fruit::reset_position(Rand_int& rnd, Snake& snake, const Board& brd, std::vector<Obstacle>o)
{
	Location next_loc;

	bool check = false;
	do {
		check = false;
		next_loc.x = rnd.get_rand_numb(brd.getBoardScreenDistance(), brd.getBoardScreenDistance() + brd.getGridWidth() - 1 );
		next_loc.y = rnd.get_rand_numb(brd.getBoardScreenDistance(), brd.getBoardScreenDistance() + brd.getGridHeight() - 1 );
		for (auto& i : o) if (next_loc == i.get_loc()) check = true;
	} while (snake.check_body_collision_for_fruit(next_loc) || check);
	loc = next_loc;
}

Color Fruit::c = Colors::Red;