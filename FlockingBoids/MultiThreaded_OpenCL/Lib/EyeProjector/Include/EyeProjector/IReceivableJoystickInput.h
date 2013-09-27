/**
 * EyeProjector - Joystick Receiver Interface Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/IReceivableJoystickInput.h
 * @version 	1.0.0 12-Jul-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IRECEIVERABLE_JOYSTICK_INPUT_H__
#define __IRECEIVERABLE_JOYSTICK_INPUT_H__

namespace EP
{
	class IReceivableJoystickInput
	{
		public:
			virtual ~IReceivableJoystickInput(void)
			{
			}
			
			virtual void handleJoystickEvent(const TUInt32 buttonCode, TInt32 x, TInt32 y, TInt32 z) = 0;
	};
}

#endif