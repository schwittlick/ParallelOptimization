/**
 * EyeProjector - Random Number Managment Module.
 *
 * This class supports methods for generating random numbers.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/Random.h
 * @version		1.0.0 08-Jun-13
 * @version		1.0.1 16-Jun-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_RANDOM_H__
#define __EYE_PROJECTOR_RANDOM_H__

#include <EyeProjector/Range.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Random module.
	 */
	class Random
	{
		public:
			/**
			 * Return the only instance of this module.
			 *
			 * If at this point no instance exists, it creates one.
			 */
			static Random& getInstance(void);
			
			/**
			 * Releases the memory of this module.
			 */
			static void release(void);
			
			/**
			 * Initilizes this randomizer.
			 */
			void init(void);
			
			/**
			 * Return random number within min and max range.
			 *
			 * @param min - minimum double value
			 * @param max - maximum double value
			 * @return random double value
			 */
			double getNextValue(const double min, const double max);
			
			/**
			 * Return random number within min and max range.
			 *
			 * @param min - minimum integer value
			 * @param max - maximum integer value
			 * @return random integer value
			 */
			int getNextValue(const int min, const int max);
			
			/**
			 * Returns an random value as float type in s specific range.
			 *
			 * @param range - range definition within the random value should be fit
			 * @return random value between given range
			 */
			float getNextValue(Range<float> range);
			
			/**
			 * Returns an random value as int type in s specific range.
			 *
			 * @param range - range definition within the random value should be fit
			 * @return random value between given range
			 */
			int getNextValue(Range<int> range);
			
		private:
			/**
			 * Default constructor.
			 *
			 * Disabled because part of singleton pattern.
			 */
			Random(void);
			
			/**
			 * Default deconstructor.
			 *
			 * Disabled because part of singleton pattern.
			 */
			~Random(void);
			
			/**
			 * Default copy constructor.
			 *
			 * Disabled because part of singleton pattern.
			 */
			Random(const Random &src);
			
		private:
			/**
			 * Stores the only instance of this module. 
			 */
			static Random* _instance;
			
			/**
			 * Stores status if this random module was already initilizes.
			 */
			bool _isInitilized;
	};
}
#endif