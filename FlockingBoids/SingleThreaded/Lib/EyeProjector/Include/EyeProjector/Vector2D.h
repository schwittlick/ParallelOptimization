/**
 * EyeProjector - 2D Vector Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/Vector2D.h
 * @version		1.0.0 22-Jun-13
 * @version		1.1.0 23-Jun-13
 * @version		1.2.0 27-Jun-13
 * @version		1.3.0 29-Jun-13
 * @version		1.4.0 11-Jul-13
 * @version		1.4.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_VECTOR2D_H__
#define __EYE_PROJECTOR_VECTOR2D_H__

#include <EyeProjector/Platform.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
#ifdef _DEBUG
	class Vector2D;
	
	/**
	 * Converts a Vector2D object to nice readable string and puts it to the output stream.
	 *
	 * @note 	Because that feature is actually only needed in debugging pruposes, 
	 *			this function isn't available in the release version of this library.
	 */
	std::ostream& operator << (std::ostream &out, Vector2D &src);
#endif
	
	/**
	 * 2D Vector Class.
	 */
	class Vector2D
	{
		public:
			/**
			 * Default constructor.
			 */
			Vector2D(void);
			
			/**
			 * Initilizes this vector with two start parameters.
			 *
			 * @param[in] x - x value for this new 2D vector
			 * @param[in] y - y value for this new 2D vector
			 */
			Vector2D(const TF32 x, const TF32 y);
			
			/**
			 * Default decontructor.
			 */
			virtual ~Vector2D(void);
			
			/**
			 * Default copy constructor.
			 *
			 * @param src - other Vector2D object that used as a source 
			 */
			Vector2D(const Vector2D &src);
			
			/**
			 * Adds two vectors together.
			 *
			 * @param vec2 - second vector that should be add to this one
			 * @return new version of vector addition process
			 */
			Vector2D operator + (const Vector2D &src);
			
			/**
			 * Subtracts this vector with another.
			 *
			 * @param vec2 - other vector that this vector has to be subtract with
			 * @return new vector as result of (v1.x - v2.x, v1.y - v2.y)
			 */
			Vector2D operator - (const Vector2D &src);
			
			Vector2D operator / (const TF32 value);
			Vector2D operator * (const TF32 value);
			bool operator == (const Vector2D &src);
			Vector2D& operator += (const Vector2D &src);
			Vector2D& operator -= (const Vector2D &src);
			Vector2D& operator /= (const TF32 value);
			Vector2D& operator *= (const TF32 value);
			
			TF32 dotProduct(const Vector2D &src) const;
			TF32 length(void) const;
			TF32 determineAngle(const Vector2D &src);
			void normalize(void);
			void rotate(const TF32 angleRad);
			void negate(void);

#ifdef _DEBUG			
			friend std::ostream& operator << (std::ostream &out, Vector2D &src);
#endif			
			/**
			 * Returns x component of this vector.
			 *
			 * @return x value as a float
			 */
			TF32 getX(void) const
			{
				return this->_x;
			}
			
			/**
			 * Assigns x value for this vector.
			 *
			 * @param x - new x value for this vector
			 */
			void setX(const TF32 x)
			{
				this->_x = x;
			}
			
			/**
			 * Returns y component of this vector.
			 *
			 * @return y value as a float
			 */
			TF32 getY(void) const
			{
				return this->_y;
			}
			
			/**
			 * Assigns y value for this vector.
			 *
			 * @param y - new x value for this vector
			 */
			void setY(const TF32 y)
			{
				this->_y = y;
			}
			
		protected:
			/**
			 * Stores x component of this vector.
			 */
			TF32 _x;
			
			/**
			 * Stores y component of this vector.
			 */
			TF32 _y;
	};
}
#endif