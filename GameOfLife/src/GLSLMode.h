#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "Colony.h"
#include "ofxUI.h"
#include "Timer.h"
#include "ofxFX.h"

class GLSLMode : public itg::ofxState<SharedData>
{
public:
	GLSLMode(void);
	~GLSLMode(void);

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

	Timer * drawTimer;
	Timer * updateTimer;

	int dimension;
	bool running;
	float elapsedTimeSinceLastReset;

	void restart(void); // restarts the entire animation
	void clean(void); // cleans some objects
	void guiEvent(ofxUIEventArgs &e); // callback method for gui events

	ofxFXObject * conway;
	ofFbo fbo;

	ofFile file;
	int elapsedFrames;

	void init();
};

