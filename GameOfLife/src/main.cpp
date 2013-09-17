#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include <ctime>

//========================================================================
int main( ){

	int amount = 10000000;
	clock_t time = clock();

	for( int i = 0; i < amount; ++i )
	{
		clock();
	}

	clock_t elapsed = clock() - time;

	std::cout << "Running clock() once takes " << std::fixed << ( float )( elapsed ) / ( float )( amount ) << "ms." << std::endl;
	
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1000, 1000, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
