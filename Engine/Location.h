#pragma once

struct Location {

	void add(const Location& val) {
		x += val.x;
		y += val.y;
}
	
	int x;
	int y;

};

inline bool operator==(const Location& loc1, const Location& loc2) {
	return
		loc1.x == loc2.x &&
		loc1.y == loc2.y;
}