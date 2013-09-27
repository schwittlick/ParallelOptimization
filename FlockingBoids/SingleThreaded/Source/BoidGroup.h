/**
 * @version 	1.0.0 27-Jun-13
 * @version		1.1.0 30-Jun-13
 * @version		1.2.0 11-Jul-13
 * @version		1.3.0 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __BOID_GROUP_H__
#define __BOID_GROUP_H__

#include <EyeProjector/EyeProjector.h>
#include <vector>

class BoidEntity;
class BaseBehavior;

typedef std::vector<BoidEntity*> TListBoids;

class BoidGroup
{
	public:
		BoidGroup(void);
		BoidGroup(const BoidGroup &src);
		virtual ~BoidGroup(void);
		
		BoidGroup& operator = (const BoidGroup &src);
		
		void update(void);
		void render(void);
		void release(void);
		void add(BoidEntity* boid);
		void setBehavior(BaseBehavior* behavior);
		
		TListBoids* getList(void)
		{
			return this->_listBoids;
		}
		
		EP::TInt32 getCount()
		{
			return this->_listBoids->size();
		}
		
		BaseBehavior* getBehavior(void) const
		{
			return this->_behavior;
		}
		
	private:
		TListBoids* _listBoids;
		BaseBehavior* _behavior;
};

#endif