/**
 * EyeProjector - Tile Map Scene Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/TileMapScene.h
 * @version 	1.0.0 10-Aug-13
 * @version		1.1.0 11-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TILE_MAP_SCENE_H__
#define __TILE_MAP_SCENE_H__

#include <EyeProjector/IScene.h>
#include <string>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	class TileMapScene : public IScene
	{
		public:
			TileMapScene(const std::string path);
			TileMapScene(const TileMapScene &src);
			virtual ~TileMapScene(void);
			
			void init(void);
			void update(void);
			void render(void);
			void release(void);
			
		private:
			std::string _path;
	};
}

#endif