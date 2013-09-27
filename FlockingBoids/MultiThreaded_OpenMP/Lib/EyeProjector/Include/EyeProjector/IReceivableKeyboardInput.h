/**
 * EyeProjector - Keyboard Receiver Interface Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/IReceivableKeyboardInput.h
 * @version 	1.0.0 30-May-13
 * @version		1.1.0 31-May-13
 * @version		1.1.1 16-Jun-13
 * @version		1.1.2 29-Jun-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IRECEIVABLE_KEYBOARD_INPUT_H__
#define __IRECEIVABLE_KEYBOARD_INPUT_H__

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	class IReceivableKeyboardInput
	{
		public:
			virtual ~IReceivableKeyboardInput(void) 
			{
			}
			
			virtual void handlePressedKey(const TInt32 keyCode) = 0;
	};
}

#endif