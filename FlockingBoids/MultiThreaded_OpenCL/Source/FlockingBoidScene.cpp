/**
 * FlockingBoids - Flocking Boid Application Scene Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/FlockingBoidScene.cpp
 * @version 	1.0.0 17-Jun-13
 * @version		1.1.0 23-Jun-13
 * @version		1.2.0 27-Jun-13
 * @version		1.3.0 29-Jun-13
 * @version		1.4.0 30-Jun-13
 * @version		1.5.0 11-Jul-13
 * @version		1.6.0 15-Sep-13
 * @version		1.7.0 21-Sep-13
 * @version		1.8.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <EyeProjector/EyeProjector.h> 
#include <EyeProjector/Random.h>
#include <EyeProjector/Window.h>
#include <EyeProjector/InputManager.h>
#include <FlockingBoidScene.h>
#include <BoidGroup.h>
#include <FlockOpenCLBehavior.h>
#include <SimpleConcurrencyLib/System.h>

/**
 * Creates new instance of this class.
 */
FlockingBoidScene::FlockingBoidScene(void) :
	_boidGroup(NULL),
	_countLabel(NULL),
	_profilerLabel(NULL)
{
}

/**
 * Creates new instance by copying another instance of this class.
 *
 * @param src - reference to the other instance of this class
 */
FlockingBoidScene::FlockingBoidScene(const FlockingBoidScene &src) :
	_boidGroup(NULL),
	_countLabel(NULL),
	_profilerLabel(NULL)
{
}

/**
 * Releases this instance of this class.
 */
FlockingBoidScene::~FlockingBoidScene(void)
{
}

/**
 * Assigns data by another instance of this class.
 *
 * @param src - reference to the other instance of this class
 * @return reference to this instance of this class
 */
FlockingBoidScene& FlockingBoidScene::operator = (const FlockingBoidScene &src)
{
	return *this;
}

/**
 * Initilizes this scene.
 */
void FlockingBoidScene::init(void)
{
	EP::InputManager::getInstance().addKeyboardReceiver(this);
	SimpleConcurrencyLib::System& clSystem = SimpleConcurrencyLib::System::getInstance();
	
	clSystem.init(CL_DEVICE_TYPE_CPU);
	
	this->_boidGroup = new BoidGroup();
	
	EP::TUInt32 screenWidth 	= EP::Window::getInstance().getScreenWidth();
	EP::TUInt32 screenHeight 	= EP::Window::getInstance().getScreenHeight();
	
	this->_boidGroup->setBehavior(new FlockOpenCLBehavior(screenWidth, screenHeight));
	
	for(EP::TUInt32 i=0;i < 600;++i){
		this->_addBoid();
	}
	
	this->_countLabel = new EP::LabelEntity();
	this->_profilerLabel = new EP::LabelEntity();
	this->_profilerLabel->setPosition(EP::Vector2D(0.0f, 25.0f));
}

/**
 * Updates all scene entities.
 */
void FlockingBoidScene::update(void)
{
	FlockBehavior* behavior = (FlockBehavior*)this->_boidGroup->getBehavior();
	
	behavior->setAreaSize(EP::Window::getInstance().getScreenWidth(), EP::Window::getInstance().getScreenHeight());
	
	clock_t profilerStart = clock();
	this->_boidGroup->update();

	this->_profilerLabel->setText("Update Time: %f sec", (float)(clock() - profilerStart) / CLOCKS_PER_SEC);
	this->_countLabel->setText("Boids Count: %d (Press + to add 20 more boids to this scene)", this->_boidGroup->getCount());
}

/**
 * Renders all scene entities.
 */
void FlockingBoidScene::render(void)
{
	this->_boidGroup->render();
	this->_countLabel->render();
	this->_profilerLabel->render();
}

/**
 * Releases all reserved memory.
 */
void FlockingBoidScene::release(void)
{
	MEMORY_RELEASE(this->_program);
	MEMORY_RELEASE(this->_boidGroup);
	MEMORY_DELETE(this->_countLabel);
	MEMORY_DELETE(this->_profilerLabel);
}

/**
 * Handles pressed key event from the keyboard.
 */
void FlockingBoidScene::handlePressedKey(const int keyCode)
{
	switch(keyCode)
	{
		case EP::KEY_ESC:{
			exit(0);
		}break;
		
		case '+':
		{
			for(EP::TUInt32 i=0;i < 20;++i){
				this->_addBoid();
			}
		}break;
	}
}

/**
 * Adds a boid to the scene.
 */
void FlockingBoidScene::_addBoid(void)
{
	static EP::Random& random 		= EP::Random::getInstance();
	static EP::Window& window		= EP::Window::getInstance();
	static EP::TUInt32 screenWidth 	= window.getScreenWidth();
	static EP::TUInt32 screenHeight = window.getScreenHeight();
	
	BoidEntity* boid = new BoidEntity(10, 20);
	boid->init();
	boid->setPosition(EP::Vector2D(random.getNextValue(0, screenWidth - 1), random.getNextValue(0, screenHeight - 1)));
	boid->setColor(random.getNextValue(0.0f, 1.0f), random.getNextValue(0.0f, 1.0f), random.getNextValue(0.0f, 1.0f));
	boid->setDirection(EP::Vector2D(random.getNextValue(-1.0f, 1.0f), random.getNextValue(-1.0f, 1.0f)));
	boid->setVolcity(random.getNextValue(0.1f, 10.0f));
	
	this->_boidGroup->add(boid);
}