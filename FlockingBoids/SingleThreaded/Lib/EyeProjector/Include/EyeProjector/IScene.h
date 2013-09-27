/**
 * EyeProjector - Scene Interface Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/IScene.h
 * @version 	1.0.0 20-May-13
 * @version		1.0.1 16-Jun-13
 * @version		1.0.2 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_SCENE_H__
#define __EYE_PROJECTOR_SCENE_H__

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	class IScene
	{
		public:
			virtual ~IScene()
			{
			}
			
			virtual void init(void) = 0;
			virtual void update(void) = 0;
			virtual void render(void) = 0;
			virtual void release(void) = 0;
	};
}

#endif