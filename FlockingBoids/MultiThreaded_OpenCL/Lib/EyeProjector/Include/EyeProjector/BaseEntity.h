/**
 * EyeProjector - Base Entity Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/BaseEntity.h
 * @version 	1.0.0 23-Jun-13
 * @version		1.0.1 27-Jun-13
 * @version		1.1.0 10-Aug-13
 * @version		1.2.0 15-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_BASE_ENTITY_H__
#define __EYE_PROJECTOR_BASE_ENTITY_H__

#include <EyeProjector/Platform.h>
#include <EyeProjector/Vector2D.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Abstract Base Entity Class.
	 */
	class BaseEntity
	{
		public:
			/**
			 * Creates new instance of this class.
			 */
			BaseEntity(void);
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param position - new position for this entity
			 */
			BaseEntity(const Vector2D position, const TF32 width=0.0f, const TF32 height=0.0f);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			BaseEntity(const BaseEntity &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~BaseEntity(void);
			
			/**
			 * Renders this entity.
			 */
			void render(void);
			
			/**
			 * Assigns new position to this entity.
			 *
			 * @param position - new position for this entity as a 2D vector
			 */
			void setPosition(const Vector2D position)
			{
				this->_position = position;
			}
			
			/**
			 * Returns current position of this entity.
			 *
			 * @return 2D vector including the current position of this entity
			 */
			Vector2D getPosition(void) const
			{
				return this->_position;
			}
			
			/**
			 * Assigns new width to this entity.
			 *
			 * @param width - new width value for this entity
			 */
			void setWidth(const TF32 width)
			{
				this->_width = width;
			}
			
			/**
			 * Returns current width of this entity.
			 *
			 * @return float value including the current width of this entity.
			 */
			TF32 getWidth(void) const
			{
				return this->_width;
			}
			
			/**
			 * Assigns new height to this entity.
			 *
			 * @param height - new height value for this entity
			 */
			void setHeight(const TF32 height)
			{
				this->_height = height;
			}
			
			/**
			 * Returns current height of this entity.
			 *
			 * @return float value including the current height of this entity.
			 */
			TF32 getHeight(void) const
			{
				return this->_height;
			}
			
			/**
			 * Assigns new angle for rotation to this entity.
			 *
			 * @param angle - new angle value
			 */
			void setAngle(const TF32 angle)
			{
				this->_angle = angle;
			}
			
		protected:
			virtual void _render(void) = 0;	
			
		protected:
			/**
			 * Stores position of this entity.
			 */
			Vector2D _position;
			
			/**
			 * Stores width of this entity.
			 */
			TF32 _width;
			
			/**
			 * Stores height of this entity.
			 */
			TF32 _height;
			
			/**
			 * Stores angle of this entity.
			 */
			TF32 _angle;
	};
}

#endif