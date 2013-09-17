#include "OpenMpMode.h"
#include <omp.h>

OpenMpMode::OpenMpMode(void):
	dimension(50),
	running(true),
	file(ofToDataPath("benchmark_openmp_mode.csv"), ofFile::WriteOnly ),
	elapsedFrames( 0 )
{
	std::cout << "OpenMpMode" << "\n";

}

OpenMpMode::~OpenMpMode(void)
{
	std::cout << "~OpenMpMode" << "\n";
}

/*
 * this is called, when this state is entered. this equivalent to the constructor.
*/
void OpenMpMode::stateEnter(void)
{
	colony = new gol::Colony(dimension);

	// creates a new gui and adds several sliders and buttons
	gui = new ofxUICanvas(0, 0, 350, 300);
	gui->setAutoDraw(false);
	gui->setColorBack(ofColor(0, 200));  
	gui->addWidgetDown(new ofxUILabel("Game of Life (OpenMP)", OFX_UI_FONT_LARGE)); 
	gui->addWidgetDown(new ofxUISlider(300,20,0,6144,dimension,"RESOLUTION")); 
	gui->addWidgetDown(new ofxUIButton(32, 32, false, "REINIT"));
	gui->addWidgetDown(new ofxUISlider(300,20,0,1,0.0,"RANDOMCHANCE")); 
	gui->addWidgetDown(new ofxUIToggle(32, 32, true, "RUNNING"));
	gui->addWidgetRight(new ofxUIButton(32, 32, false, "RANDOM"));
	gui->addWidgetDown(new ofxUILabel("AVERAGE TIME", OFX_UI_FONT_LARGE));
	ofAddListener(gui->newGUIEvent, this, &OpenMpMode::guiEvent); 
	//gui->loadSettings("GUI/guiSettings.xml"); 

	drawTimer = new Timer(); // starts the timer for the elapsed time during drawing the game of life.
	restart(); // restarts the entire animation
}

/*
 * called when the state is exited. this is equivalent to the destructor.
*/
void OpenMpMode::stateExit(void)
{
	clean(); // cleaning objects from the heap.
}

/*
 * update method. updateing values.
*/
void OpenMpMode::update()
{
	if( getSharedData().isBenchmarkMode )
	{
		if( elapsedFrames > 50) {
			running = false;
		} 
		else 
		{
			running = true;
		}
	}
	

	if(running)
	{
		colony->populateOpenMP(getSharedData().numberOfCores);
		elapsedFrames++;
	}
	else if( getSharedData().isBenchmarkMode && dimension < 4100 )
	{
		
		std::cout << "New dimension: " << dimension << std::endl;
		dimension += 50;
		elapsedFrames = 0;
		float elapsed = colony->getUpdateNeighbourTimer()->getAverageTime();
		elapsed += colony->getAdvanceTimer()->getAverageTime();
		file << dimension << "," << elapsed << std::endl;
		if(dimension == 4000)
		{
			file.close();
			std::cout << "Finished Benchmark for OpenMP mode." << std::endl;
		}
		restart();
	}
}

/*
 * draw method. drawing the game of life.
*/
void OpenMpMode::draw()
{
	drawTimer->start();
	ofBackground(0);
	ofSetColor(255);	
	ofFill();

	// determining width and height of each cell in relation to the size of the entire window
	float w = float(ofGetWidth()) / float(colony->getDimension());
	float h = float(ofGetHeight()) / float(colony->getDimension());
	// drawing all cells

	
		for(int y = 0; y < colony->getDimension(); y++)
		{
			for(int x = 0; x < colony->getDimension(); x++)
			{
				gol::Cell* c = colony->getCell(x, y);
				if(c->isAlive()){
						ofRect(x * w, y * h, w, h);
				}
			}
		}

		drawTimer->stop();
		drawTimer->store();
	gui->draw(); // draws the gui on top of the game of life

	// draws some statistics of the elapsed times to the screen.
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 20, 250);
	ofDrawBitmapString("neighbourCount average: "+ofToString(colony->getUpdateNeighbourTimer()->getAverageTime())+" ms", 20, 265);
	ofDrawBitmapString("advance average: "+ofToString(colony->getAdvanceTimer()->getAverageTime())+" ms", 20, 280);

	// stoping the timer for the draw method
	

	// drawing statistics about the draw timer to the screen. (should be included into the timer, but well, what was first, the hen or the egg?)
	ofDrawBitmapString("drawing average: "+ofToString(drawTimer->getAverageTime())+" ms", 20, 295);
	ofDrawBitmapString("elapsed time: " +ofToString( ofGetElapsedTimef() - elapsedTimeSinceLastReset )+" s", 20, 310 );

}

/*
 * callback method for mouse input
*/
void OpenMpMode::mousePressed(int x, int y, int button)
{
	
}

/*
 * returns the name of the state. important for state changes.
*/
string OpenMpMode::getName()
{
	return getSharedData().OPENMP;
}

/*
 * callback method for keyboard inputs
*/
void OpenMpMode::keyPressed(int key)
{
	switch(key)
	{
		// 'c' switches to the sequential state
		case 'c':
			changeState(getSharedData().OPENCL);
			break;
		default:
			break;
	}
}

/*
 * callback method for gui events
*/
void OpenMpMode::guiEvent(ofxUIEventArgs &e)
{
	// adjusts the resolution of the game of life colony
	if(e.widget->getName() == "RESOLUTION")	
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;    
		dimension = int(slider->getScaledValue());
	}   
	// adjusts the ratio between dead and alive cells when reinitializing the colony
	else if(e.widget->getName() == "RANDOMCHANCE")	
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;    
		colony->setRandomChance(slider->getScaledValue());
	}  
	// toggling if the animation is running or not
	else if(e.widget->getName() == "RUNNING")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		running = toggle->getValue(); 
	}   
	// reinits the game of life and starts from a randomly initialized colony
	else if(e.widget->getName() == "REINIT")	
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		if(toggle->getValue() == false)
		{
			restart();
		}
	}  
	// randomly kills/awakes cells
	else if(e.widget->getName() == "RANDOM")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		if(toggle->getValue() == false)
		{
			colony->randomize();
		}
	} 
}

/*
 * restarts the animataion entirely by creating new objects for the colony etc.
*/
void OpenMpMode::restart(void)
{
	delete colony;
	colony = new gol::Colony(dimension);
	colony->randomize();

	delete drawTimer;
	drawTimer = new Timer();

	elapsedTimeSinceLastReset = ofGetElapsedTimef();
}

/*
 * cleans some objects from the heap.
*/
void OpenMpMode::clean(void)
{
	delete drawTimer;
	delete colony;
	delete gui;
}