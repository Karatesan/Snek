#include "Board.h"

Board::Board(Graphics& gfx, int w, int h)
	: gfx(gfx), board_width(w), board_height(h)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	gfx.draw_filled_rect(loc.x * cell_square_size + getBoardScreenDistance(), loc.y * cell_square_size + getBoardScreenDistance(), 
						 cell_square_size - getSquareSpacing() * 2, cell_square_size - getSquareSpacing() * 2, c);

	gfx.draw_rect(loc.x * cell_square_size + getBoardScreenDistance(), loc.y * cell_square_size + getBoardScreenDistance(), 
				  cell_square_size - getSquareSpacing() * 2, cell_square_size - getSquareSpacing() * 2, getSquareSpacing(), Colors::Black);
}

void Board::draw( Graphics& g)
{
	gfx.draw_rect(getBoardScreenDistance() * cell_square_size, getBoardScreenDistance() * cell_square_size, board_width * cell_square_size, board_height * cell_square_size, 5);

	//for (int y = getBoardScreenDistance() * cell_square_size; y < (getBoardScreenDistance() + getGridHeight()) * cell_square_size; ++y)
	//	for(int x=getBoardScreenDistance() * cell_square_size; x < (getBoardScreenDistance() + getGridWidth()) * cell_square_size; ++x)
	//	if(x % cell_square_size == 0 || y % cell_square_size == 0) gfx.PutPixel(x, y, Colors::Yellow);
}

