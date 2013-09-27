/**
 * EyeProjector - Range Structure Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/Range.h
 * @version		1.0.0 08-Jun-13
 * @version		1.0.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_RANGE_H__
#define __EYE_PROJECTOR_RANGE_H__

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Describes a particular range with an start and end value.
	 */
	template <typename T>
	class Range
	{
		public:
			/**
			 * Default constructor.
			 */
			Range(void)
			{
				this->_min = 0;
				this->_max = 0;
			}
			
			/**
			 * Default constructor for range definition.
			 *
			 * @param min - min boundary of this range
			 * @param max - max boundary of this range
			 */
			Range(const T min, const T max)
			{
				this->_min = min;
				this->_max = max;
			}

			/**
			 * Default deconstructor.
			 */
			virtual ~Range(void)
			{
				this->_min = 0;
				this->_max = 0;
			}

			/**
			 * Default copy constructor.
			 *
			 * @param src - other instance of this module for the copy process
			 */
			Range(const Range &src)
			{
				this->_min = src._min;
				this->_max = src._max;
			}
			
			/**
			 * Assign the min boundary value.
			 *
			 * @param min - min boundary of this range
			 */
			void setMin(const T min)
			{
				this->_min = min;
			}
			
			/**
			 * Return the min boundary value.
			 *
			 * @return min boundary value of this range
			 */
			T getMin(void) const
			{
				return this->_min;
			}
			
			/**
			 * Assign the max boundary value.
			 *
			 * @param max - max boundary of this range
			 */
			void setMax(const T max)
			{
				this->_max = max;
			}
			
			/**
			 * Return the max boundary value.
			 *
			 * @return max boundary value of this range
			 */
			T getMax(void) const
			{
				return this->_max;
			}
			
		private:
			/**
			 * Stores start value.
			 */
			T _min;
			
			/**
			 * Stores end value.
			 */
			T _max;
	};
}
#endif