/**
 * @version 	1.0.0 26-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#include <FlockOpenCLBehavior.h>
#include <EyeProjector/EyeProjector.h>

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
}