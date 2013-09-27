/**
 * FlockingBoids - Base Behavior Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/BaseBehavior.h
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __BASE_BEHAVIOR_H__
#define __BASE_BEHAVIOR_H__

#include <BoidGroup.h>

class BaseBehavior
{
	public:
		BaseBehavior(void);
		BaseBehavior(const BaseBehavior &src);
		virtual ~BaseBehavior(void);
		
		BaseBehavior& operator = (const BaseBehavior &src);
		
		virtual void update(void) = 0;
	
		void setBoidGroup(BoidGroup* group)
		{
			this->_group = group;
		}
		
	protected:
		BoidGroup* _group;
};

#endif