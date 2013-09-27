/**
 * EyeProjector - Unknown File Format Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Incude/EyeProjector/UnkownFileFormatException.h
 * @version 	1.0.0 19-Aug-13
 * @version		1.0.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_UNKNOWN_FILE_FORMAT_EXCEPTION_H__
#define __EYE_PROJECTOR_UNKNOWN_FILE_FORMAT_EXCEPTION_H__

#include <EyeProjector/BaseMessageException.h>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Unkown File Format Exception Class.
	 */
	class UnknownFileFormatException : public BaseMessageException
	{
		public:
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			UnknownFileFormatException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			UnknownFileFormatException(const UnknownFileFormatException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~UnknownFileFormatException(void) throw()
			{
			}
	};
}

#endif