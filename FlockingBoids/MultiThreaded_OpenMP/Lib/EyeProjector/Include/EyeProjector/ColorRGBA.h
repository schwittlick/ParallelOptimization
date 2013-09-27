/**
 * EyeProjector - Color Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/ColorRGBA.h
 * @version		1.0.0 10-Aug-13
 * @version		1.1.0 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_COLOR_RGBA_H__
#define __EYE_PROJECTOR_COLOR_RGBA_H__

#include <EyeProjector/Platform.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	class ColorRGBA
	{
		public:
			ColorRGBA(void);
			ColorRGBA(const TF32 r, const TF32 g, const TF32 b);
			ColorRGBA(const TF32 r, const TF32 g, const TF32 b, const TF32 a);
			ColorRGBA(const ColorRGBA &src);
			virtual ~ColorRGBA(void);
			
			TF32 getRed(void) const
			{
				return this->_r;
			}
			
			void setRed(const TF32 value)
			{
				this->_r = value;
			}
			
			TF32 getGreen(void) const
			{
				return this->_g;
			}
			
			void setGreen(const TF32 value)
			{
				this->_g = value;
			}
			
			TF32 getBlue(void) const
			{
				return this->_b;
			}
			
			void setBlue(const TF32 value)
			{
				this->_b = value;
			}
			
			TF32 getAlpha(void) const
			{
				return this->_a;
			}
			
			void setAlpha(const TF32 value)
			{
				this->_a = value;
			}
			
		private:
			/**
			 * Stores red component of this color.
			 */
			TF32 _r;
			
			/**
			 * Stores green component of this color.
			 */
			TF32 _g;
			
			/**
			 * Stores blue component of this color.
			 */
			TF32 _b;
			
			/**
			 * Stores alpha component of this color.
			 */
			TF32 _a;
	};
}

#endif