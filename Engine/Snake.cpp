#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].initHead(loc);
}

void Snake::MoveByLoc(const Location& dloc)
{
	for (int i = nSegments; i > 1; --i) {
		segments[i - 1].Follow(segments[i - 2]);
	}
	segments[0].MoveBy(dloc);
}

void Snake::MoveByDir(const direction& ddir)
{
	switch (ddir) {
	case left:
		MoveByLoc({ -1,0 });
		break;
	case right:
		MoveByLoc({ 1,0 });
		break;
	case up:
		MoveByLoc({ 0,-1 });
		break;
	case down:
		MoveByLoc({ 0,1 });
		break;
	}
}

void Snake::Grow(const Color& cc)
{
	if (nSegments < nSegmentsMax) nSegments++;	
		segments[nSegments - 1].initBody(segments[nSegments - 2], cc);
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i) {
		segments[i].Draw(brd);
	}
}

void Snake::Segment::initHead(const Location& iloc)
{
	loc = iloc;
	c = headColor;
}

void Snake::Segment::initBody(const Segment& previous, const Color& cc)
{
	c = cc;
	loc = previous.get_loc();
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& dloc)
{
	loc.add(dloc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

bool Snake::is_fruit_eaten(const Location& fruit_loc)
{
	return fruit_loc == segments[0].get_loc();
}

bool Snake::check_board_collision(const Board& brd, const direction& next)
{
	Location next_loc = direction_to_loc(next);
	next_loc.add(get_loc());

	if (next_loc.x < brd.getBoardScreenDistance() ||
		next_loc.x > brd.getGridWidth() + brd.getBoardScreenDistance() - 1 ||
		next_loc.y < brd.getBoardScreenDistance() ||
		next_loc.y > brd.getGridHeight() + brd.getBoardScreenDistance() - 1)
		return true;

	return false;
}

bool Snake::check_body_collision(const direction& next)
{
	Location next_loc = direction_to_loc(next);
	next_loc.add(get_loc());

	for (int i = 0; i < nSegments - 1; ++i)
		if (next_loc == segments[i].get_loc()) return true;
	return false;
}

bool Snake::check_body_collision_for_fruit(const Location& next)
{
	for (int i = 0; i < nSegments; ++i)
		if (next == segments[i].get_loc()) return true;
	return false;
}

bool Snake::check_obstacle_collision(const direction& next, const Location& obstacle)
{
	Location next_loc = direction_to_loc(next);
	next_loc.add(get_loc());

	if(next_loc == obstacle) return true;
		return false;
}

bool Snake::move_backwards(const direction& d)
{
	if (dir == get_opposite_direction(d)) return true;
	return false;
}

void Snake::update()
{

}

Location direction_to_loc(const Snake::direction& d)
{
	switch (d) {
	case Snake::left:
		return { -1,0 };
	case Snake::right:
		return { 1,0 };
	case Snake::up:
		return { 0,-1 };
	case Snake::down:
		return { 0,1 };
	}
}

Snake::direction get_opposite_direction(const Snake::direction& d) {
	switch (d) {
	case Snake::left:
		return Snake::right;
	case Snake::right:
		return Snake::left;
	case Snake::up:
		return Snake::down;
	case Snake::down:
		return Snake::up;
	}
}