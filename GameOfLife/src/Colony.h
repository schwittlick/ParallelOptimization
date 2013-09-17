#pragma once

#include <ofMain.h>
#include "Cell.h"
#include "Timer.h"
#include <CL\opencl.h>
#include "FreeImage.h"

namespace gol
{
	class Colony;
}
class gol::Colony
{
public:
	Colony(int dim);
	~Colony(void);

	// advance to next generation of game of life
	void populate(void);
	void populateOpenMP(int nrOfCores);
	void populateOpenCL(  );

	// getters
	int getDimension(void);
	gol::Cell* getCell(int x, int y);
	int getWidth(void);
	int getHeight(void);

	// change the colony
	void setRandomChance(float chance);
	void clear(void);
	void randomize(void);

	// time evaluation stuff
	Timer* getUpdateNeighbourTimer(void);
	Timer* getAdvanceTimer(void);

	void draw();

	void setCell(int x, int y, Cell* c);
	void setCell( int x, int y, bool status );

private:
	vector<gol::Cell*> cells; // contains all cells
	int dimension; // the dimension of the colony. dimension*dimension
	float randomChance; // the percentage of alive cells when randomly initializing the colony

	void updateNeighboursSequential(void);
	void advanceSequential(void);

	void updateNeighboursOpenMP(int nrOfCores);
	void advanceOpenMP(int nrOfCores);

	void updateNeighboursOpenCL( void );
	void advanceOpenCL( void );

	void advance(int nrOfCores);
	void updateNeighbours(int nrOfCores);

	int getNeighboursForCell(int x, int y);

	Timer *updateNeighboursTimer;
	Timer *advanceTimer;

	

	
	void charArrayToOfImage( unsigned char* sourceBuffer, ofImage *dstImage, int w, int h );
	ofImage ima;

	FIBITMAP *image_bitmap;
	unsigned char *bmpBits;

	
};
