/**
 * SimpleConcurrencyLib - Program Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		SimpleConcurrenyLib/Program.h
 * @version 	1.0.0 25-Aug-13
 * @version		1.1.0 01-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_CONCURRENCY_LIB_PROGRAM_H__
#define __SIMPLE_CONCURRENCY_LIB_PROGRAM_H__

#include <OpenCL/OpenCL.h>
#include <string>
#include <vector>

/**
 * Simple Concurrency Library Namespace.
 */
namespace SimpleConcurrencyLib
{
	/**
	 * Concurrency Program Class.
	 */
	class Program
	{
		public:
			/**
			 * Creates new instance of this class.
			 */
			Program(void);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			Program(const Program &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~Program(void);
		
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			Program& operator = (const Program &src);
		
			/**
			 * Executes this program.
			 *
			 * @param result 		- pointer to the result float array
			 * @param resultSize	- size of the result array
			 */
			void execute(float* result, const int resultSize);
			
			/**
			 * Releases blocked memory of this program.
			 */
			void release(void);
			
			/**
			 * Adds new float parameter to this program.
			 *
			 * @param value 	- float value as new parameter
			 * @param options	- OpenCL options for this parameter
			 */
			void addParameter(const float value, const int options);
			
			/**
			 * Adds new float array parameter to this program.
			 *
			 * @param value 		- float value as new parameter
			 * @param countItems	- size of the array parameter
			 * @param options		- OpenCL options for this parameter
			 */
			void addParameter(const float* list, const int countItems, const int options);
			
			/**
			 * Adds new integer parameter to this program.
			 *
			 * @param value 	- integer value as new parameter
			 * @param options	- OpenCL options for this parameter
			 */
			void addParameter(const int value, const int options);
			
			/**
			 * Adds new integer array parameter to this program.
			 *
			 * @param value 		- integer value as new parameter
			 * @param countItems	- size of the array parameter
			 * @param options		- OpenCL options for this parameter
			 */
			void addParameter(const int* list, const int countItems, const int options);
			
			/**
			 * Loads kernel source code from a string.
			 *
			 * @param content 					- string including kernel source code
			 * @param mainFunctionIdentifier	- string including identifier of the main function within the kernel source code
			 */
			void loadFromString(const std::string content, const std::string mainFunctionIdentifier);
			
			/**
			 * Loads kernel source code from a file.
			 *
			 * @param path 						- string including path to the kernel source code file
			 * @param mainFunctionIdentifier	- string including identifier of the main function within the kernel source code
			 */
			void loadFromFile(const std::string path, const std::string mainFunctionIdentifier);
			
			/**
			 * Loads kernel source code from a bineary file.
			 *
			 * @note This function isn't completely implemented yet!
			 * @param path 						- string including path to the kernel bineary file
			 * @param mainFunctionIdentifier	- string including identifier of the main function within the kernel source code
			 */
			void loadFromBinearyFile(const std::string path, const std::string mainFunctionIdentifier);
		
		private:
			/**
			 * Stores device ID this program should run on.
			 */
			cl_device_id _deviceId;
			
			/**
			 * Stores program information.
			 */
			cl_program _program;
			
			/**
			 * Stores context information.
			 */
			cl_context _context;
			
			/**
			 * Stores kernel of this program.
			 */
			cl_kernel _kernel;
			
			/**
			 * Stores command queue of this program.
			 */
			cl_command_queue _commandQueue;
			
			/**
			 * Stores parameter count.
			 */
			unsigned int _parameterCounter;
	};
}

#endif