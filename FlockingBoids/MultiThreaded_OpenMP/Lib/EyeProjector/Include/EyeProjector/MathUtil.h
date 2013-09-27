/**
 * EyeProjector Engine - Math Utitilites Module.
 *
 * @author		Andy Liebke<andydeveloper@online.de>
 * @file		EyeProjector/MathUtil.h
 * @version		1.0.0 23-Jun-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rigths reserved.
 */
#ifndef __MATH_UTIL_H__
#define __MATH_UTIL_H__

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Math Utilities Module.
	 */
	class MathUtil
	{
		public:
			/**
			 * Constant value for PI.
			 */
			static const float PI;
			
			/**
			 * Converts Degree to Radian.
			 *
			 * @param value - value in degree
			 * @return converted value in radian
			 */
			static float convDegToRad(const float value)
			{
				return value * (PI / 180.0f);
			}
	
			/**
			 * Converts Radian to Degree.
			 *
			 * @param value - value in radian
			 * @return converted value in degree
			 */
			static float convRadToDeg(const float value)
			{
				return value * (180.0f / PI);
			}
	};
}

#endif