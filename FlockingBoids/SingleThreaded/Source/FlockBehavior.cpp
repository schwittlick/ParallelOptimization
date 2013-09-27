/**
 * FlockingBoids - Flock Behavior Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/FlockBehavior.cpp
 * @version 	1.0.0 30-Jun-13
 * @version		1.1.0 11-Jul-13
 * @version		1.2.0 15-Sep-13
 * @version		1.2.1 21-Sep-13
 * @version		1.2.2 22-Sep-13
 * @version		1.2.3 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */ 
#include <EyeProjector/Vector2D.h> 
#include <FlockBehavior.h>
#include <BoidEntity.h>

/**
 * Creates new instance of this class.
 *
 * @param areaWidth 	- area width
 * @param areaHeight	- area height
 */
FlockBehavior::FlockBehavior(const EP::TF32 areaWidth, const EP::TF32 areaHeight) : 
	BaseBehavior(),
	_neighborArea(40.0f),
	_areaWidth(areaWidth),
	_areaHeight(areaHeight)
{
}

/**
 * Creates new instance by copying another instance of this class.
 *
 * @param src - reference to the other instance of this class
 */
FlockBehavior::FlockBehavior(const FlockBehavior &src) :
	BaseBehavior(src),
	_neighborArea(src._neighborArea),
	_areaWidth(src._areaWidth),
	_areaHeight(src._areaHeight)
{
}

/**
 * Releases this instance of this class.
 */
FlockBehavior::~FlockBehavior(void)
{
}

/**
 * Assigns data by another instance of this class.
 *
 * @param src - reference to the other instance of this class
 * @return reference to this instance of this class
 */
FlockBehavior& FlockBehavior::operator = (const FlockBehavior &src)
{
	this->_neighborArea = src._neighborArea;
	this->_areaWidth = src._areaWidth;
	this->_areaHeight = src._areaHeight;
	
	return *this;
}

/**
 * Updates this behavior process.
 */
void FlockBehavior::update(void)
{
	TListBoids* list = this->_group->getList();
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		EP::Vector2D alignment 		= this->_alignment((*it));
		EP::Vector2D separation 	= this->_separation((*it));
		EP::Vector2D cohesion 		= this->_cohesion((*it));
		EP::Vector2D areaDirection	= this->_keepInsideArea((*it));
		
		(*it)->setDirection((*it)->getDirection() + alignment + separation + cohesion + areaDirection);
		(*it)->update();
	}
}

/**
 * Calculates the alignment for a particular boid.
 *
 * @param currBoid - boid this alignment has to be calculated
 * @return direction vector
 */
EP::Vector2D FlockBehavior::_alignment(BoidEntity* currBoid)
{
	TListBoids* list = this->_group->getList();
	EP::Vector2D avgDirection(0.0f, 0.0f);
	EP::Vector2D currPosition = currBoid->getPosition();
	EP::TF32 avgVolcity = 0;
	EP::TInt32 count = 0;
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		if((*it) != currBoid)
		{
			EP::Vector2D diff = (*it)->getPosition() - currPosition;
		
			if(diff.length() < this->_neighborArea)
			{
				avgDirection += (*it)->getDirection();
				avgVolcity += (*it)->getVolcity();
				
				++count;
			}
		}
	}
	
	if(count > 0)
	{
		avgVolcity /= (float)count;
		avgDirection /= (float)count;
		avgDirection.normalize();
		
		currBoid->setVolcity(avgVolcity);
	}
	
	return avgDirection;
}

/**
 * Calculates the separation for a particular boid.
 *
 * @param currBoid - boid this separation has to be calculated
 * @return direction vector
 */
EP::Vector2D FlockBehavior::_separation(BoidEntity* currBoid)
{
	TListBoids* list = this->_group->getList();
	EP::Vector2D avgPosition(0.0f, 0.0f);
	EP::Vector2D currPosition = currBoid->getPosition();
	
	EP::TInt32 count = 0;
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		if((*it) != currBoid)
		{
			EP::Vector2D diff = (*it)->getPosition() - currPosition;
		
			if(diff.length() < 30.0f)
			{
				avgPosition += diff;
				++count;
			}
		}
	}
	
	if(count > 0)
	{
		avgPosition /= (float)count;
		avgPosition.negate();
		avgPosition.normalize();
	}
	
	return avgPosition;
}

/**
 * Calculates the cohesion for a particular boid.
 *
 * @param currBoid - boid this cohesion has to be calculated
 * @return direction vector
 */
EP::Vector2D FlockBehavior::_cohesion(BoidEntity* currBoid)
{
	TListBoids* list = this->_group->getList();
	EP::Vector2D avgPosition(0.0f, 0.0f);
	EP::Vector2D currPosition = currBoid->getPosition();
	
	EP::TInt32 count = 0;
	
	for(TListBoids::iterator it=list->begin();it != list->end();++it)
	{
		if((*it) != currBoid)
		{
			EP::Vector2D diff = (*it)->getPosition() - currPosition;
		
			if(diff.length() < this->_neighborArea)
			{
				avgPosition += (*it)->getPosition();
				++count;
			}
		}
	}
	
	if(count > 0)
	{
		avgPosition /= (float)count;
		avgPosition = avgPosition - currPosition;
		avgPosition.normalize();
	}
	
	return avgPosition;
}

/**
 * Calculates new direction to keep a particular boid within scene area.
 *
 * @param currBoid - boid this cohesion has to be calculated
 * @return direction vector
 */
EP::Vector2D FlockBehavior::_keepInsideArea(BoidEntity* currBoid)
{
	EP::Vector2D currDirection = currBoid->getDirection();
	EP::Vector2D nextPosition = currBoid->getPosition() + (currDirection * currBoid->getVolcity());
	
	if((nextPosition.getX() + currBoid->getWidth() > this->_areaWidth) || (nextPosition.getX() < 0.0f)){
		currDirection.setX(-currDirection.getX());
	}
	
	if((nextPosition.getY() + currBoid->getHeight() > this->_areaHeight) || (nextPosition.getY() < 0.0f)){
		currDirection.setY(-currDirection.getY());
	}
	
	return currDirection;
}
