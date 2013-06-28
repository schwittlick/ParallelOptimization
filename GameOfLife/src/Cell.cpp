#include "Cell.h"

/*
 * constructor initializes the cell.
*/
gol::Cell::Cell(void)
{
	alive = false;
	neighbours = 0;
}

/*
 * destructor does nothing so far.
*/
gol::Cell::~Cell(void)
{
}

/*
 * sets the cell alive/dead (true/false).
*/
void gol::Cell::setAlive(bool a)
{
	alive = a;
}

/*
 * sets the amount of neighbours of the cell.
*/
void gol::Cell::setNeighbourCount(int n)
{
	neighbours = n;
}

/*
 * returns if the cell is alive.
*/
bool gol::Cell::isAlive(void)
{
	return alive;
}

/*
 * returns the number of living neighbours next to this cell.
*/
int gol::Cell::getNeighbourCount(void)
{
	return neighbours;
}