#pragma once

namespace gol
{
	class Cell;
}

class gol::Cell
{
public:
	Cell(void);
	~Cell(void);

	void setAlive(bool a);
	bool isAlive(void);
	void setNeighbourCount(int n);
	int getNeighbourCount(void);
	bool alive; // status indicating if the cells is dead or alive

private:
	
	int neighbours; // the nr of alive cells next to this cell
};

