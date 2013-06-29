#include "Colony.h"
#include <omp.h>

/*
 * the constructor initializes the entire colony and starts the timer neccessary to evaluate the elapsed time of different concurrency algorithms.
*/
gol::Colony::Colony(int dim)
{
	dimension = dim;
	randomChance = 0.2;

	for(int i = 0; i < dimension * dimension; i++)
	{
		cells.push_back(new gol::Cell());
	}

	updateNeighboursTimer = new  Timer();
	advanceTimer = new Timer();
}

/*
 * the destructor of the colony. this deletes used objects from the heap.
*/
gol::Colony::~Colony(void)
{
	delete updateNeighboursTimer;
	delete advanceTimer;
	for(auto it = cells.begin(); it != cells.end(); ++it)
	{
		delete *it;
	}
}

/*
 * develops a new step according to the game of life rules. this only uses one thread for the entire workload of the animation. 
*/
void gol::Colony::populate(void)
{
	updateNeighboursSequential();
	advanceSequential();
}

/*
 * develops a new step according to the game of life rules. this uses openmp with the passed nr of cores/threads. 
*/
void gol::Colony::populateOpenMP(int nrOfCores)
{
	updateNeighboursOpenMP(nrOfCores);
	advanceOpenMP(nrOfCores);
}

/*
 * updates the neighbour count for each cell by using only one thread/core
*/
void gol::Colony::updateNeighboursSequential(void)
{
	updateNeighbours(1);
}

/*
 * advances the game of live by using only one core/thread
*/
void gol::Colony::advanceSequential(void)
{
	advance(1);
}

/*
 * updates the neighbour count for each cell by using multiple cores
*/
void gol::Colony::updateNeighboursOpenMP(int nrOfCores)
{
	updateNeighbours(nrOfCores);
}

/*
 * advances the game by using multiple cores
*/
void gol::Colony::advanceOpenMP(int nrOfCores)
{
	advance(nrOfCores);
}

/*
 * advances the evolution of the game of life by one step. it utilizes openmp to split the workload on different threads working on different cpus.
*/
void gol::Colony::advance(int nrOfCores)
{
	advanceTimer->start();
#pragma omp parallel num_threads(nrOfCores)
	{
		int currentThread = omp_get_thread_num();
		int maxThreads = omp_get_num_threads();
		int per_thread = dimension * dimension / maxThreads;
		int start = per_thread * currentThread;
		int end = per_thread * (currentThread + 1);

		//std::cout << "Advance: ThreadNr: " << currentThread << " MaxThreads: " << maxThreads << " Todo: " << per_thread << " start: " << start << " end: " << end <<std::endl; 

		for(int i = start; i < end; i++)
		{
			if(cells[i]->isAlive())
			{
				if (cells[i]->getNeighbourCount() != 2 && cells[i]->getNeighbourCount() != 3) 
				{
					cells[i]->setAlive(false);
				} 
				else 
				{
					cells[i]->setAlive(true);
				}
			} 
			else 
			{
				if (cells[i]->getNeighbourCount() == 3) 
				{
					cells[i]->setAlive(true);
				}
			}
		}
	}
	advanceTimer->stop();
	advanceTimer->store();
}

/*
 * updates the neighbour count for each cell. utilizes openmp to spread the work to different threads on different cpus.
*/
void gol::Colony::updateNeighbours(int nrOfCores)
{
	updateNeighboursTimer->start();
#pragma omp parallel num_threads(nrOfCores)
	{
		int currentThread = omp_get_thread_num();
		int maxThreads = omp_get_num_threads();
		int per_thread = dimension / maxThreads;
		int start = per_thread * currentThread;
		int end = per_thread * (currentThread + 1);

		if(currentThread == 0)
		{
			start++;
		}

		if(currentThread == maxThreads - 1)
		{
			end--;
		}

		//std::cout << "updateNeighbours: ThreadNr: " << currentThread << " MaxThreads: " << maxThreads << " Todo: " << per_thread << " start: " << start << " end: " << end <<std::endl; 
		for(int y = start ; y < end ; y++)
		{
			for(int x = 1; x < dimension - 1; x++)
			{
				int loc = x + y * dimension;
				int n = getNeighboursForCell(x, y);
				getCell(x, y)->setNeighbourCount(n);
			}
		}
	}
	updateNeighboursTimer->stop();
	updateNeighboursTimer->store();
}

/*
 * returns the number of alive cells surrounding the cell indicated by the x and y parameter.
*/
int gol::Colony::getNeighboursForCell(int x, int y)
{
	int nei = 0;

	if (getCell(x - 1, y - 1)->isAlive()) {
      nei++;
    }
    if (getCell(x - 1, y)->isAlive()) {
      nei++;
    }
    if (getCell(x, y - 1)->isAlive()) {
      nei++;
    }
    if (getCell(x - 1, y + 1)->isAlive()) {
      nei++;
    }
    if (getCell(x + 1, y - 1)->isAlive()) {
      nei++;
    }
    if (getCell(x + 1, y + 1)->isAlive()) {
      nei++;
    }
    if (getCell(x, y + 1)->isAlive()) {
      nei++;
    }
    if (getCell(x + 1, y)->isAlive()) {
      nei++;
    }

	return nei;
}

/*
 * clears the field and sets all as dead.
*/
void gol::Colony::clear(void)
{
	for(int i = 0; i < dimension * dimension; i++)
	{
		cells[i]->setAlive(false);
	}
}

/*
 * randomizes the field indicated by the parameter for the chance for each cell to be dead/alive
*/ 
void gol::Colony::randomize(void)
{
	for(auto it = cells.begin(); it != cells.end(); ++it)
	{
		delete *it;
	}

	for(int i = 0; i < dimension * dimension; i++)
	{
		Cell *c = new gol::Cell();
		if(ofRandom(0, 1) < randomChance)
		{
			c->setAlive(true);
		}
		cells[i] = c;
	}
}

/************************************************************************/
/* GETTERS & SETTERS                                                    */
/************************************************************************/

int gol::Colony::getDimension(void)
{
	return dimension;
}

gol::Cell* gol::Colony::getCell(int x, int y)
{
	return cells[x+y*dimension];
}

void gol::Colony::setCell(int x, int y, Cell* c)
{
	cells[x+y*dimension] = c;
}

int gol::Colony::getWidth(void)
{
	return dimension;
}

int gol::Colony::getHeight(void)
{
	return dimension;
}

void gol::Colony::setRandomChance(float chance)
{
	randomChance = chance;
}

Timer* gol::Colony::getUpdateNeighbourTimer(void)
{
	return updateNeighboursTimer;
}

Timer* gol::Colony::getAdvanceTimer(void)
{
	return advanceTimer;
}

