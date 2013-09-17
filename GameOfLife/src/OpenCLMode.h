#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "Colony.h"
#include "ofxUI.h"
#include "Timer.h"
#include <string>


#include <CL\opencl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Cell.h"

class OpenCLMode : public itg::ofxState<SharedData>
{
public:
	OpenCLMode(void);
	~OpenCLMode(void);

	void stateEnter(void);
	void stateExit(void);

	void update(void);
	void draw(void);

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	string getName(void); // returns the name of the class. important for switching between states

private:


	void initOpenCLBoolStuff();
	void updateOpenCLBoolStuff(cl_device_id device_id);
	cl_context context;
	cl_program program;
	cl_command_queue commandQueue;

	size_t roundUp( int groupSize, int globalSize);

	ofxUICanvas *gui; // the graphical user interface
	gol::Colony* colony; // the game of life colony
	bool running; // determining if the animation is running
	int dimension; // determining the size of the colony. neccessary for the reinitialization.
	Timer *drawTimer; // timer timing the elapsed time during drawing the game of life.
	Timer * calculationTimer;
	void restart(void); // restarts the entire animation
	void clean(void); // cleans some objects
	void guiEvent(ofxUIEventArgs &e); // callback method for gui events

	void startDeviceSelector( void );
	size_t choosenPlatform;
	cl_platform_id* platformIds;

	void createContext();
	cl_device_id createCommandQueue();
	void createKernel( cl_device_id device, cl_context _context );
	cl_kernel createKernelFromSource( cl_device_id device, cl_context context, const char * source, const char * name );

	void fail( std::string errorMsg );

	cl_sampler sampler;
	cl_kernel kernel;


	_Bool  * board;//[ 32*32];
	cl_mem input;
	cl_mem output;
	cl_device_id device_id;

	void printBoard();

	float elapsedTimeSinceLastReset;
	ofFile file;
	int elapsedFrames;
};

