/**
 * EyeProjector - Input Manager Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/InputManager.h
 * @version 	1.0.0 30-May-13
 * @version 	1.1.0 31-May-13
 * @version		1.2.0 20-Jun-13
 * @version		1.3.0 23-Jun-13
 * @version		1.4.0 29-Jun-13
 * @version		1.5.0 12-Jul-13
 * @version		1.6.0 10-Aug-13
 * @version		1.6.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_INPUT_MANAGER_H__
#define __EYE_PROJECTOR_INPUT_MANAGER_H__

#include <EyeProjector/Platform.h>
#include <EyeProjector/IReceivableKeyboardInput.h>
#include <EyeProjector/IReceivableMouseInput.h>
#include <EyeProjector/IReceivableJoystickInput.h>
#include <vector>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	enum EKeyboard
	{
		KEY_ESC = 27
	};
	
	enum EMouseButtons
	{
		MOUSE_BUTTON_LEFT = 0,
		MOUSE_BUTTON_RIGHT = 2
	};
	
	enum EMouseState
	{
		MOUSE_STATE_DOWN = 0,
		MOUSE_STATE_UP = 1
	};
	
	enum EJoystickButton
	{
		JOYSTICK_BUTTON_A = 2048,
		JOYSTICK_BUTTON_B = 4096,
		JOYSTICK_BUTTON_X = 8192,
		JOYSTICK_BUTTON_Y = 16384,
		JOYSTICK_BUTTON_START = 16,
		JOYSTICK_BUTTON_LB = 256,
		JOYSTICK_BUTTON_RB = 512
	};
	
	class InputManager
	{
		public:
		
			static InputManager& getInstance(void);
			static void release(void);
			
			void handleKeyPressEvent(const TUInt32 key);
			void handleMouseButtonEvent(const TUInt32 buttonCode, const TUInt32 state, const TInt32 x, const TInt32 y);
			void handleMousePositionChangeEvent(const TInt32 x, const TInt32 y);
			void handleJoystickEvent(const TUInt32 buttonCode, const TInt32 x, const TInt32 y, const TInt32 z);
			
			void addKeyboardReceiver(IReceivableKeyboardInput* receiver);
			void addMouseReceiver(IReceivableMouseInput* receiver);
			void addJoystickReceiver(IReceivableJoystickInput* receiver);
			
		private:
			InputManager(void);
			InputManager(const InputManager &src);
			~InputManager(void);
			InputManager& operator=(InputManager const &src);
			
		private:
			static InputManager* _instance;
			
			std::vector<IReceivableKeyboardInput*> _listKeyboardReceiver;
			std::vector<IReceivableMouseInput*> _listMouseReceiver;
			std::vector<IReceivableJoystickInput*> _listJoystickReceiver;
	};
}

#endif