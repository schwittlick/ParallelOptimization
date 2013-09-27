/**
 * @version 	1.0.0 31-May-13
 * @version		1.0.1 16-Jun-13
 * @version		1.1.0 13-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __NO_SUCH_FILE_EXCEPTION_H__
#define __NO_SUCH_FILE_EXCEPTION_H__

#include <EyeProjector/BaseMessageException.h>

namespace EP
{
	class NoSuchFileException : public BaseMessageException
	{
		public:
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			NoSuchFileException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			NoSuchFileException(const NoSuchFileException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~NoSuchFileException(void) throw()
			{
			}
	};
}

#endif