#include "Obstacles.h"



Obstacle Obstacle::new_obstacle(Rand_int& rnd, Snake& snake, const Location& fruit, const Board& brd)
{
	Location next_loc;
 
 	do {
 		next_loc.x = rnd.get_rand_numb(brd.getBoardScreenDistance(), brd.getBoardScreenDistance() + brd.getGridWidth() - 1);
 		next_loc.y = rnd.get_rand_numb(brd.getBoardScreenDistance(), brd.getBoardScreenDistance() + brd.getGridHeight() -1);
 	} while (snake.check_body_collision_for_fruit(next_loc) || fruit == next_loc);
 	loc = next_loc;

	return Obstacle(next_loc.x, next_loc.y);
}
