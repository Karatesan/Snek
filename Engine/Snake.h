#pragma once
#include "Board.h"

class Snake {
private:
	class Segment {
	
	public:
		void initHead(const Location& iloc);
		void initBody(const Segment& previous, const Color& cc);
		void Follow(const Segment& next);
		void MoveBy(const Location& dloc);
		void Draw(Board& brd) const;
		Location get_loc() const { return loc; }
		
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);

	enum direction { left, right, up, down };

	void MoveByLoc(const Location& dloc);
	void MoveByDir(const direction& ddir);

	void Grow(const Color& cc);
	void Draw(Board& brd) const;

	bool is_fruit_eaten(const Location& fruit_loc);
	bool check_board_collision( const Board& brd, const direction& next);
	bool check_body_collision(const direction& next);
	bool check_body_collision_for_fruit(const Location& next);
	bool check_obstacle_collision(const direction& next, const Location& obstacle);
	bool move_backwards(const direction& d);
	
	Location get_loc() const { return segments[0].get_loc(); }
	direction get_direction() const { return dir; }

	void change_direction(direction d) { dir = d; }

	void update();

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	direction dir = right;
};

Location direction_to_loc(const Snake::direction& d);
Snake::direction get_opposite_direction(const Snake::direction& d);
