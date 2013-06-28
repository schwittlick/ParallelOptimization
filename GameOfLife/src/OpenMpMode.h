#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "Colony.h"
#include "ofxUI.h"
#include "Timer.h"
#include <string>

class OpenMpMode : public itg::ofxState<SharedData>
{
public:
	OpenMpMode(void);
	~OpenMpMode(void);

	void stateEnter(void);
	void stateExit(void);

	void update(void);
	void draw(void);

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	string getName(void); // returns the name of the class. important for switching between states

private:
	ofxUICanvas *gui; // the graphical user interface
	gol::Colony* colony; // the game of life colony
	bool running; // determining if the animation is running
	int dimension; // determining the size of the colony. neccessary for the reinitialization.
	Timer *drawTimer; // timer timing the elapsed time during drawing the game of life.
	void restart(void); // restarts the entire animation
	void clean(void); // cleans some objects
	void guiEvent(ofxUIEventArgs &e); // callback method for gui events
};

