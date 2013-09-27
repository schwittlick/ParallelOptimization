/**
 * @version 1.0.0 01-Sep-13
 */
#ifndef __SIMPLE_CONCURRENCY_LIB_LOGGER_H__
#define __SIMPLE_CONCURRENCY_LIB_LOGGER_H__

#include <SimpleConcurrencyLib/NoSuchFileException.h>

/**
 * Simple Concurrency Library Namespace.
 */
namespace SimpleConcurrencyLib
{
	enum EMessageType
	{
		MESSAGE_TYPE_NOTICE = 0,
		MESSAGE_TYPE_ERROR = 1,
		MESSAGE_TYPE_WARNING = 2,
		MESSAGE_TYPE_DEBUG = 3
	};
	
	class Logger
	{
		public:
			static void init(const std::string path) throw(NoSuchFileException);
			static void writeMessage(const std::string message, const EMessageType type);
			
			static void writeError(const std::string message)
			{
				writeMessage(message, MESSAGE_TYPE_ERROR);
			}
			
			static void writeNotice(const std::string message)
			{
				writeMessage(message, MESSAGE_TYPE_NOTICE);
			}
			
			static void writeWarning(const std::string message)
			{
				writeMessage(message, MESSAGE_TYPE_WARNING);
			}
			
			static void writeException(const std::exception* exceptionObj)
			{
				writeMessage(exceptionObj->what(), MESSAGE_TYPE_ERROR);
			}
			
		private:
			static std::string _path;
	};
}

#endif