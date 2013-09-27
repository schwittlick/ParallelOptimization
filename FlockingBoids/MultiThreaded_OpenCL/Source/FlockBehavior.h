/**
 * FlockingBoids - Flock Behavior Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/FlockBehavior.h
 * @version 	1.0.0 30-Jun-13
 * @version 	1.1.0 11-Jul-13
 * @version		1.2.0 21-Sep-13
 * @version		1.2.1 22-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://www.andysmiles4games.com)
 */
#ifndef __FLOCK_BEHAVIOR_H__
#define __FLOCK_BEHAVIOR_H__

#include <BaseBehavior.h>

/**
 * Flock Behavior Class.
 */
class FlockBehavior : public BaseBehavior
{
	public:
		/**
		 * Creates new instance of this class.
		 *
		 * @param areaWidth 	- area width
		 * @param areaHeight	- area height
		 */
		FlockBehavior(const EP::TF32 areaWidth, const EP::TF32 areaHeight);
		
		/**
		 * Creates new instance by copying another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 */
		FlockBehavior(const FlockBehavior &src);
		
		/**
		 * Releases this instance of this class.
		 */
		virtual ~FlockBehavior(void);
		
		/**
		 * Assigns data by another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 * @return reference to this instance of this class
		 */
		FlockBehavior& operator = (const FlockBehavior &src);
		
		/**
		 * Updates this behavior process.
		 */
		void update(void);
		
		/**
		 * Assigns area size to this behavior module.
		 *
		 * @param width 	- area width
		 * @param height	- area height
		 */
		void setAreaSize(const EP::TF32 width, const EP::TF32 height)
		{
			this->_areaWidth = width;
			this->_areaHeight = height;
		}
		
	private:
		/**
		 * Calculates the alignment for a particular boid.
		 *
		 * @param currBoid - boid this alignment has to be calculated
		 * @return direction vector
		 */
		EP::Vector2D _alignment(BoidEntity* currBoid);
		
		/**
		 * Calculates the separation for a particular boid.
		 *
		 * @param currBoid - boid this separation has to be calculated
		 * @return direction vector
		 */
		EP::Vector2D _separation(BoidEntity* currBoid);
		
		/**
		 * Calculates the cohesion for a particular boid.
		 *
		 * @param currBoid - boid this cohesion has to be calculated
		 * @return direction vector
		 */
		EP::Vector2D _cohesion(BoidEntity* currBoid);
		
		/**
		 * Calculates new direction to keep a particular boid within scene area.
		 *
		 * @param currBoid - boid this cohesion has to be calculated
		 * @return direction vector
		 */
		EP::Vector2D _keepInsideArea(BoidEntity* currBoid);
		
	private:
		/**
		 * Stores radius as neighbor area.
		 */
		EP::TF32 _neighborArea;
		
		/**
		 * Stores width of the environment area.
		 */
		EP::TF32 _areaWidth;
		
		/**
		 * Stores height of the environment area.
		 */
		EP::TF32 _areaHeight;
};

#endif