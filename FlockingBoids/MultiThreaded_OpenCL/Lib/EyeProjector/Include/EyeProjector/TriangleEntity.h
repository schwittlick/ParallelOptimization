/**
 * EyeProjector - Triangle Entity Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/TriangleEntity.h
 * @version 	1.0.0 23-Jun-13
 * @version		1.1.0 10-Aug-13
 * @version		1.2.0 15-Sep-13
 * @version		1.3.0 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_TRIANGLE_ENTITY_H__
#define __EYE_PROJECTOR_TRIANGLE_ENTITY_H__

#include <EyeProjector/BaseStaticMeshEntity.h>
#include <EyeProjector/ColorRGBA.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Triangle Entity Class.
	 */
	class TriangleEntity : public BaseStaticMeshEntity
	{
		public:
			/**
			 * Creates new instance of this class.
			 *
			 * @param width 	- width of this triangle
			 * @param height	- height of this triangle
			 */
			TriangleEntity(const TUInt32 width, const TUInt32 height);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			TriangleEntity(const TriangleEntity &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~TriangleEntity(void);
			
			/**
			 * Assigns color to this triangle.
			 *
			 * @param r - Red Color Component
			 * @param g - Green Color Component
			 * @param b - Blue Color Component
			 */
			void setColor(const TF32 r, const TF32 g, const TF32 b)
			{
				this->_color.setRed(r);
				this->_color.setGreen(g);
				this->_color.setBlue(b);
			}
			
		protected:
			/**
			 * Creates a static mesh for this triangle.
			 */
			void _createStaticMesh(void);
			
		private:
			/**
			 * Stores color of this triangle.
			 */
			ColorRGBA _color;
	};
}

#endif