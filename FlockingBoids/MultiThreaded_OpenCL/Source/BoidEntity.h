/**
 * FlockingBoids - Boid Entity Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/BoidEntity.h
 * @version 	1.0.0 23-Jun-13
 * @version 	1.1.0 27-Jun-13
 * @version		1.2.0 29-Jun-13
 * @version		1.3.0 30-Jun-13
 * @version		1.4.0 11-Jul-13
 * @version		1.5.0 12-Jul-13
 * @version		1.6.0 15-Sep-13
 * @version		1.7.0 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __BOID_ENTITY_H__
#define __BOID_ENTITY_H__

#include <EyeProjector/TriangleEntity.h>
#include <EyeProjector/Vector2D.h>
#include <EyeProjector/MathUtil.h>
#include <EyeProjector/LabelEntity.h>

class BoidEntity : public EP::TriangleEntity
{
	public:
		BoidEntity(const EP::TUInt32 width, const EP::TUInt32 height);
		BoidEntity(const BoidEntity &src);
		virtual ~BoidEntity(void);
		
		BoidEntity& operator = (const BoidEntity &src);
		
		void update(void);
		
		EP::Vector2D getDirection(void) const
		{
			return this->_direction;
		}
		
		void setDirection(const EP::Vector2D direction)
		{
			this->_direction = direction;
			this->_direction.normalize();
		}
		
		void setVolcity(const EP::TF32 volcity)
		{
			this->_volcity = volcity;
		}
		
		EP::TF32 getVolcity(void) const
		{
			return this->_volcity;
		}
		
		void setAngle(const EP::TF32 angle)
		{
			this->_angle = angle;
			this->_direction.rotate(EP::MathUtil::convDegToRad(angle));
			this->_direction.normalize();
		}
		
		void render(void);
		
	private:
		EP::Vector2D _direction;
		EP::TF32 _volcity;
};

#endif