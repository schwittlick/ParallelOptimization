/**
 * @version 	1.0.0 26-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#include <FlockOpenCLBehavior.h>
#include <BoidEntity.h>
#include <EyeProjector/EyeProjector.h>
#include <EyeProjector/Vector2D.h>

/**
 * Creates new instance of this class.
 *
 * @param areaWidth 	- area width
 * @param areaHeight	- area height
 */
FlockOpenCLBehavior::FlockOpenCLBehavior(const EP::TF32 areaWidth, const EP::TF32 areaHeight) :
	_program(new SimpleConcurrencyLib::Program())
{
	this->_program->loadFromFile("Kernel/FlockBehavior.cl", "runKernel");
}

/**
 * Creates new instance by copying another instance of this class.
 *
 * @param src - reference to the other instance of this class
 */
FlockOpenCLBehavior::FlockOpenCLBehavior(const FlockOpenCLBehavior &src)
{
}

/**
 * Releases this instance of this class.
 */
FlockOpenCLBehavior::~FlockOpenCLBehavior(void)
{
	MEMORY_RELEASE(this->_program);
}

/**
 * Assigns data by another instance of this class.
 *
 * @param src - reference to the other instance of this class
 * @return reference to this instance of this class
 */
FlockOpenCLBehavior& FlockOpenCLBehavior::operator = (const FlockOpenCLBehavior &src)
{
}

/**
 * Updates this behavior process.
 */
void FlockOpenCLBehavior::update(void)
{
	TListBoids* list = this->_group->getList();
	
	EP::TInt32 listSize 		= list->size();
	EP::TUInt32 sizeUpdateList 	= 2 * listSize;
	EP::TF32* dataStream 		= new EP::TF32[5 * listSize];
	EP::TF32* updateDataStream 	= new EP::TF32[sizeUpdateList];
	EP::TInt32 itemCounter 		= 0;
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		EP::Vector2D position = (*it)->getPosition();
		EP::Vector2D direction = (*it)->getDirection();
		
		dataStream[itemCounter] 	= position.getX();
		dataStream[itemCounter + 1] = position.getY();
		dataStream[itemCounter + 2] = direction.getX();
		dataStream[itemCounter + 3] = direction.getY();
		dataStream[itemCounter + 4] = (*it)->getVolcity();
		
		itemCounter += 5;
	}
	
	this->_program->addParameter(&listSize, (int)sizeof(EP::TInt32), CL_MEM_READ_ONLY);
	this->_program->addParameter(dataStream, 5 * listSize, CL_MEM_READ_ONLY);
	
	delete[] dataStream;
	dataStream = NULL;
	
	this->_program->execute(updateDataStream, sizeUpdateList);
	
	itemCounter = 0;
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		(*it)->setDirection(EP::Vector2D(updateDataStream[itemCounter], updateDataStream[itemCounter + 1]));
		itemCounter += 2;
	}
}