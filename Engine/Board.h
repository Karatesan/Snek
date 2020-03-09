#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {

public:
	Board(Graphics& gfx, int w, int h);

	void DrawCell(const Location& loc, Color c);
	void draw(Graphics& g);
	int getGridWidth() const { return board_width; }
	int getGridHeight() const { return board_height; }
	int getCellSize() const { return cell_square_size; }
	int getBoardScreenDistance() const { return distance_from_window_borders; }
	int getSquareSpacing() const { return squares_spacing; }

private:
	int distance_from_window_borders = 2; // in square cells, not pixels
	int squares_spacing = 1;
	int board_width;
	int board_height;
	int cell_square_size = 20;  //pixels
	Graphics& gfx; 
};
