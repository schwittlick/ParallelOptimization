/**
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __FLOCK_OPENCL_BEHAVIOR_H__
#define __FLOCK_OPENCL_BEHAVIOR_H__

#include <BaseBehavior.h>
#include <SimpleConcurrencyLib/Program.h>

/**
 * Flock Behavior Class.
 */
class FlockOpenCLBehavior : public BaseBehavior
{
	public:
		/**
		 * Creates new instance of this class.
		 *
		 * @param areaWidth 	- area width
		 * @param areaHeight	- area height
		 */
		FlockOpenCLBehavior(const EP::TF32 areaWidth, const EP::TF32 areaHeight);
		
		/**
		 * Creates new instance by copying another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 */
		FlockOpenCLBehavior(const FlockOpenCLBehavior &src);
		
		/**
		 * Releases this instance of this class.
		 */
		virtual ~FlockOpenCLBehavior(void);
		
		/**
		 * Assigns data by another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 * @return reference to this instance of this class
		 */
		FlockOpenCLBehavior& operator = (const FlockOpenCLBehavior &src);
		
		/**
		 * Updates this behavior process.
		 */
		void update(void);
		
	private:
		SimpleConcurrencyLib::Program* _program;
};

#endif