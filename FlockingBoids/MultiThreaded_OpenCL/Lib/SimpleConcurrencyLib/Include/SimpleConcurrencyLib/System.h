/**
 * @version 	1.0.0 13-Jul-13
 * @version		1.1.0 25-Aug-13
 * @version		1.2.0 01-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_CONCURRENCY_LIB_SYSTEM_H__
#define __SIMPLE_CONCURRENCY_LIB_SYSTEM_H__

#include <OpenCL/OpenCL.h>
#include <string>

/**
 * Simple Concurrency Library Namespace.
 */
namespace SimpleConcurrencyLib
{
	typedef struct _device_capabilities
	{
	} DeviceCaps;

	class System
	{
		public:
			static System& getInstance(void);
			static void release(void);
			
			void init(const int type);
			void detectDeviceCapabilities(DeviceCaps* caps);
			void logError(const int errorCode, const std::string label="") const;
			
			cl_context getContext(void) const
			{
				return this->_context;
			}
			
			cl_device_id getDeviceId(void) const
			{
				return this->_deviceId;
			}
			
		private:
			System(void);
			System(const System &src);
			~System(void);
		
			System& operator = (const System &src);
		
		private:
			static System* _instance;
			
			cl_platform_id _platformId;
			cl_device_id _deviceId;
			cl_context _context;
	};
}

#endif