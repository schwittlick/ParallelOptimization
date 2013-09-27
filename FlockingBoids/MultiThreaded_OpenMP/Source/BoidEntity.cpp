/**
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */ 
#include <EyeProjector/Platform.h> 
#include <BoidEntity.h>
#include <BoidGroup.h>
#include <math.h>

BoidEntity::BoidEntity(const EP::TUInt32 width, const EP::TUInt32 height) :
	TriangleEntity(width, height),
	_direction(0.0f, 1.0f),
	_volcity(0.0f)
{
}

BoidEntity::BoidEntity(const BoidEntity &src) :
	TriangleEntity(src),
	_direction(src._direction),
	_volcity(src._volcity)
{
}
	
BoidEntity::~BoidEntity(void)
{
}

BoidEntity& BoidEntity::operator = (const BoidEntity &src)
{
	this->_direction = src._direction;
	this->_volcity = src._volcity;
	
	return *this;
}

void BoidEntity::update(void)
{
	EP::Vector2D nextStep = this->_direction * this->_volcity;
	
	this->_position += nextStep;
	this->_angle = -EP::MathUtil::convRadToDeg(this->_direction.determineAngle(EP::Vector2D(0.0f, 1.0f)));	
}

void BoidEntity::render(void)
{
	glColor3f(0.2f, 0.2f, 0.2f);
	
	TriangleEntity::render();
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex3f(this->_position.getX(), this->_position.getY(), 0.0f);
		glVertex3f(this->_position.getX() + (this->_direction.getX()* (this->_width / 2)), this->_position.getY() + (this->_direction.getY()*(this->_height / 2)), 0);
	glEnd();
}