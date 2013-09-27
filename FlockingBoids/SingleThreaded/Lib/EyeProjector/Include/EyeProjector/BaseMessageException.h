/**
 * EyeProjector - Base Message Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/BaseMessageException.h
 * @version 	1.0.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __BASE_MESSAGE_EXCEPTION_H__
#define __BASE_MESSAGE_EXCEPTION_H__

#include <exception>
#include <string>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Base Message Exception Class.
	 */
	class BaseMessageException : public std::exception
	{
		public:
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			BaseMessageException(const std::string message);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			BaseMessageException(const BaseMessageException &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~BaseMessageException(void) throw();
			
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			BaseMessageException& operator = (const BaseMessageException &src);
			
			/**
			 * Returns exception message.
			 *
			 * @return string including exception message
			 */
			virtual const char* what(void) const throw();
			
		private:
		
			/**
			 * Stores exception message.
			 */
			std::string _message;
	};
}

#endif