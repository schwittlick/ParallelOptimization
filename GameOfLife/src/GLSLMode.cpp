#include "GLSLMode.h"


GLSLMode::GLSLMode(void) : dimension( 1000 ), running( true ), file( ofToDataPath("benchmark_glslmode.csv"), ofFile::WriteOnly), elapsedFrames(0)
{
	//ofDisableArbTex();
	std::cout << "GLSLMode konstruktor" << std::endl;
}


GLSLMode::~GLSLMode(void)
{
	std::cout << "GLSLMode destruktor" << std::endl;

}

void GLSLMode::stateEnter( void )
{
	colony = new gol::Colony(dimension);

	// creates a new gui and adds several sliders and buttons
	gui = new ofxUICanvas(0, 0, 350, 300);
	gui->setAutoDraw(false);
	gui->setColorBack(ofColor(0, 200));  
	gui->addWidgetDown(new ofxUILabel("Game of Life (GLSL)", OFX_UI_FONT_LARGE)); 
	gui->addWidgetDown(new ofxUISlider(300,20,0,6144,dimension,"RESOLUTION")); 
	gui->addWidgetDown(new ofxUIButton(32, 32, false, "REINIT"));
	gui->addWidgetDown(new ofxUISlider(300,20,0,1,0.0,"RANDOMCHANCE")); 
	gui->addWidgetDown(new ofxUIToggle(32, 32, true, "RUNNING"));
	gui->addWidgetRight(new ofxUIButton(32, 32, false, "RANDOM"));
	gui->addWidgetDown(new ofxUILabel("AVERAGE TIME", OFX_UI_FONT_LARGE));
	ofAddListener(gui->newGUIEvent, this, &GLSLMode::guiEvent); 
	//gui->loadSettings("GUI/guiSettings.xml"); 

	drawTimer = new Timer(); // starts the timer for the elapsed time during drawing the game of life.
	updateTimer = new Timer();

	conway = new ofxFXObject();
	
	conway->allocate( dimension, dimension );
	fbo.allocate( dimension, dimension );

	conway->setPasses(1);
	//
	// Created by kalwalt alias Walter Perdan on 24/12/11
	// Copyright 2011 http://www.kalwaltart.it/ All rights reserved.
	conway->setCode( "#version 120\n \
					#extension GL_ARB_texture_rectangle : enable\n \
					\
					uniform sampler2DRect tex0; \
					\
					vec4 dead = vec4(0.0,0.0,0.0,1.0); \
					vec4 alive = vec4(1.0,1.0,1.0,1.0); \
					\
					void main(void) { \
					vec2  st = gl_TexCoord[0].st;\
					int sum = 0; \
					vec4 y = texture2DRect(tex0, st); \
					\
					if (texture2DRect(tex0, st + vec2(-1.0, -1.0)) == alive) ++sum; \
					if (texture2DRect(tex0, st + vec2(0.0, -1.0)) == alive) ++sum; \
					if (texture2DRect(tex0, st + vec2(1.0, -1.0)) == alive) ++sum; \
					\
					if (texture2DRect(tex0, st + vec2(-1.0, 0.0)) == alive) ++sum; \
					if (texture2DRect(tex0, st + vec2(1.0, 0.0)) == alive) ++sum; \
					\
					if (texture2DRect(tex0, st + vec2(-1.0, 1.0)) == alive) ++sum; \
					if (texture2DRect(tex0, st + vec2(0.0, 1.0)) == alive) ++sum; \
					if (texture2DRect(tex0, st + vec2(1.0, 1.0)) == alive) ++sum; \
					\
					if (sum < 2) gl_FragColor = dead; \
					else if (sum > 3) gl_FragColor = dead; \
					else if (sum == 3) gl_FragColor = alive; \
					else gl_FragColor = y; \
					}");

	restart(); // restarts the entire animation

}

void GLSLMode::stateExit( void )
{
	clean();
}

void GLSLMode::update( void )
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
		updateTimer->start();
		conway->begin();
		conway->draw();
		conway->end();

		conway->update();
		updateTimer->stop();
		updateTimer->store();
		elapsedFrames++;
	}
	else if( getSharedData().isBenchmarkMode && dimension < 4100 )
	{

		std::cout << dimension << std::endl;
		dimension += 50;
		elapsedFrames = 0;
		float elapsed = updateTimer->getAverageTime();
		file << dimension << "," << elapsed << std::endl;
		if(dimension == 4000)
		{
			file.close();
			std::cout << "Finished Benchmark for GLSL mode." << std::endl;

		}
		restart();
	}
}

void GLSLMode::draw( void )
{
	drawTimer->start();
	fbo.begin();
	conway->draw();
	fbo.end();
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight() );
	drawTimer->stop();
	drawTimer->store();
	gui->draw(); // draws the gui on top of the game of life

	// draws some statistics of the elapsed times to the screen.
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 20, 250);
	ofDrawBitmapString("update average: "+ofToString(updateTimer->getAverageTime())+" ms", 20, 265);
	//ofDrawBitmapString("advance average: "+ofToString(colony->getAdvanceTimer()->getAverageTime())+" ms", 20, 280);

	// stoping the timer for the draw method


	// drawing statistics about the draw timer to the screen. (should be included into the timer, but well, what was first, the hen or the egg?)
	ofDrawBitmapString("drawing average: "+ofToString(drawTimer->getAverageTime())+" ms", 20, 295);
	ofDrawBitmapString("elapsed time: " +ofToString( ofGetElapsedTimef() - elapsedTimeSinceLastReset )+" s", 20, 310 );
}

void GLSLMode::keyPressed( int key )
{
	switch(key)
	{
		// 'c' switches to the sequential state
	case 'c':
		changeState(getSharedData().SEQUENTIAL);
		break;
	case 'r':
		restart();
		break;
	default:
		break;
	}
}

void GLSLMode::mousePressed( int x, int y, int button )
{

}

std::string GLSLMode::getName( void )
{
	return getSharedData().GLSL;
}

void GLSLMode::restart( void )
{
	delete colony;
	colony = new gol::Colony(dimension);
	colony->randomize();

	delete drawTimer;
	drawTimer = new Timer();

	delete updateTimer;
	updateTimer = new Timer();

	elapsedTimeSinceLastReset = ofGetElapsedTimef();
	running = true;
	

	init();
}

void GLSLMode::clean( void )
{

}

void GLSLMode::guiEvent( ofxUIEventArgs &e )
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
		restart();
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

void GLSLMode::init()
{
	delete conway;
	conway = new ofxFXObject();
	conway->allocate( dimension, dimension );
	//conway.set()
	//conway->setPasses(1);

	fbo.allocate( dimension, dimension );

	conway->setPasses(1);
	conway->setCode( "#version 120\n \
					 #extension GL_ARB_texture_rectangle : enable\n \
					 \
					 uniform sampler2DRect tex0; \
					 \
					 vec4 dead = vec4(0.0,0.0,0.0,1.0); \
					 vec4 alive = vec4(1.0,1.0,1.0,1.0); \
					 \
					 void main(void) { \
					 vec2  st = gl_TexCoord[0].st;\
					 int sum = 0; \
					 vec4 y = texture2DRect(tex0, st); \
					 \
					 if (texture2DRect(tex0, st + vec2(-1.0, -1.0)) == alive) ++sum; \
					 if (texture2DRect(tex0, st + vec2(0.0, -1.0)) == alive) ++sum; \
					 if (texture2DRect(tex0, st + vec2(1.0, -1.0)) == alive) ++sum; \
					 \
					 if (texture2DRect(tex0, st + vec2(-1.0, 0.0)) == alive) ++sum; \
					 if (texture2DRect(tex0, st + vec2(1.0, 0.0)) == alive) ++sum; \
					 \
					 if (texture2DRect(tex0, st + vec2(-1.0, 1.0)) == alive) ++sum; \
					 if (texture2DRect(tex0, st + vec2(0.0, 1.0)) == alive) ++sum; \
					 if (texture2DRect(tex0, st + vec2(1.0, 1.0)) == alive) ++sum; \
					 \
					 if (sum < 2) gl_FragColor = dead; \
					 else if (sum > 3) gl_FragColor = dead; \
					 else if (sum == 3) gl_FragColor = alive; \
					 else gl_FragColor = y; \
					 }");

	int w = dimension;
	int h = dimension;
	conway->begin();
	ofClear(0, 255);
	conway->draw();
	ofSetColor(255,255);
	for( int y = 0; y < h; y++ ) 
	{
		for( int x = 0; x < w; x++ ) 
		{
			bool rnd = ofRandomf() > 0.0 ? true : false;
			if( rnd ) 
			{
				ofSetColor( 0.0, 255.0 );
			} 
			else
			{
				ofSetColor( 255.0, 255.0 );
			}
			ofRect( x, y, 1, 1);
		}
	}

	conway->end();
	conway->update();

	// second time for some unknown reason :-)
	conway->begin();
	ofClear(0, 255);
	conway->draw();
	ofSetColor(255,255);
	for( int y = 0; y < h; y++ ) 
	{
		for( int x = 0; x < w; x++ ) 
		{
			bool rnd = ofRandomf() > 0.0 ? true : false;
			if( rnd ) 
			{
				ofSetColor( 0.0, 255.0 );
			} 
			else
			{
				ofSetColor( 255.0, 255.0 );
			}
			ofRect( x, y, 1, 1);
		}
	}

	conway->end();
	conway->update();
}
