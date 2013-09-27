/**
 * FlockingBoids - Flocking Boid Application Scene Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/FlockingBoidScene.cpp
 * @version		1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <EyeProjector/EyeProjector.h> 
#include <EyeProjector/Random.h>
#include <EyeProjector/Window.h>
#include <EyeProjector/InputManager.h>
#include <FlockingBoidScene.h>
#include <BoidGroup.h>
#include <FlockBehavior.h>

#ifdef _OPENMP	
	#include <omp.h>
#endif

EP::TUInt32 FlockingBoidScene::_countBoids = 0;

/**
 * Creates new instance of this class.
 */
FlockingBoidScene::FlockingBoidScene(void) :
	_currBoidGroup(NULL),
	_countLabel(NULL),
	_profilerLabel(NULL),
	_countThreadsLabel(NULL),
	_listBoidGroups()
{
}

/**
 * Creates new instance by copying another instance of this class.
 *
 * @param src - reference to the other instance of this class
 */
FlockingBoidScene::FlockingBoidScene(const FlockingBoidScene &src) :
	_currBoidGroup(NULL),
	_countLabel(NULL),
	_profilerLabel(NULL),
	_countThreadsLabel(NULL),
	_listBoidGroups()
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
	
	for(EP::TUInt32 i=0;i < 50;++i){
		this->_addBoid();
	}
	
	this->_countLabel = new EP::LabelEntity();
	this->_profilerLabel = new EP::LabelEntity();
	this->_profilerLabel->setPosition(EP::Vector2D(0.0f, 25.0f));
	
	this->_countThreadsLabel = new EP::LabelEntity();
	this->_countThreadsLabel->setPosition(EP::Vector2D(0.0f, 50.0f));
}

/**
 * Updates all scene entities.
 */
void FlockingBoidScene::update(void)
{
	clock_t profilerStart = clock();
		
	#pragma omp parallel
	{
#ifdef _OPENMP			
			EP::TUInt32 threadId = omp_get_thread_num();
			
			printf("Perform thread with OpenMP #%d\n", threadId);
#else
			EP::TUInt32 threadId = 0;
			
			printf("Perform thread without OpenMP #%d\n", threadId);			
#endif
			if(threadId < this->_listBoidGroups.size())
			{
				BoidGroup* group = this->_listBoidGroups.at(threadId);
			
			
				group->update();
			}
			
#ifdef _OPENMP			
			this->_countThreadsLabel->setText("Current number of threads: %d", omp_get_num_threads());
#endif
	}
	
	
	this->_profilerLabel->setText("Update Time: %f sec", (float)(clock() - profilerStart) / CLOCKS_PER_SEC);
	this->_countLabel->setText("Boids Count: %d (Press + to add 20 more boids to this scene)", _countBoids);
}

/**
 * Renders all scene entities.
 */
void FlockingBoidScene::render(void)
{
	for(TListBoidGroups::iterator it=this->_listBoidGroups.begin();it != this->_listBoidGroups.end();++it){
		(*it)->render();
	}
	
	this->_countLabel->render();
	this->_profilerLabel->render();
	this->_countThreadsLabel->render();
}

/**
 * Releases all reserved memory.
 */
void FlockingBoidScene::release(void)
{
	for(TListBoidGroups::iterator it=this->_listBoidGroups.begin();it != this->_listBoidGroups.end();++it){
		MEMORY_RELEASE((*it));
	}
	
	MEMORY_DELETE(this->_countLabel);
	MEMORY_DELETE(this->_profilerLabel);
	
	this->_currBoidGroup = NULL;
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
	
	if(_countBoids == 0 || (_countBoids > 1 && _countBoids % 300 == 0))
	{
		BoidGroup* newGroup = new BoidGroup();
		newGroup->setBehavior(new FlockBehavior(screenWidth, screenHeight));
		
		this->_listBoidGroups.push_back(newGroup);
		
		this->_currBoidGroup = newGroup;
		
#ifdef _OPENMP		
		omp_set_num_threads(this->_listBoidGroups.size());
#endif
	}
	
	BoidEntity* boid = new BoidEntity(10, 20);
	boid->init();
	boid->setPosition(EP::Vector2D(random.getNextValue(0, screenWidth - 1), random.getNextValue(0, screenHeight - 1)));
	boid->setColor(random.getNextValue(0.0f, 1.0f), random.getNextValue(0.0f, 1.0f), random.getNextValue(0.0f, 1.0f));
	boid->setDirection(EP::Vector2D(random.getNextValue(-1.0f, 1.0f), random.getNextValue(-1.0f, 1.0f)));
	boid->setVolcity(random.getNextValue(0.8f, 2.0f));
	
	this->_currBoidGroup->add(boid);
	
	++_countBoids;
}