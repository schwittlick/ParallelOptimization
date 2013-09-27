/**
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @version 	1.0.0 20-May-13
 * @version 	1.1.0 23-Jun-13
 * @version		1.1.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_WINDOW_H__
#define __EYE_PROJECTOR_WINDOW_H__

#include <EyeProjector/Platform.h>
#include <EyeProjector/IScene.h>
#include <string>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	class Window
	{
		public:
			static Window& getInstance(void);
			static void release(void);
			
			void init(const TUInt32 screenWidth, const TUInt32 screenHeight, const bool fullscreen);
			void run(IScene* scene);
			void resize(const TUInt32 screenWidth, const TUInt32 screenHeight);
			
			void setTitle(const std::string title)
			{
				this->_title = title;
			}
			
			TUInt32 getScreenWidth(void) const
			{
				return this->_screenWidth;
			}
			
			TUInt32 getScreenHeight(void) const
			{
				return this->_screenHeight;
			}
			
		private:
			Window(void);
			Window(const Window& src);
			~Window(void);
			Window& operator=(Window const&);
			
			void _release(void);
			
		private:
			static Window* _instance;
			
			std::string _title;
			IScene* _scene;
			bool _isInitilized;
			TUInt32 _screenWidth;
			TUInt32 _screenHeight;
	};
}

#endif