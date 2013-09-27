/**
 * @version 	1.0.0 20-May-13
 * @version		1.1.0 21-May-13
 * @version		1.2.0 27-May-13
 * @version		1.2.1 16-Jun-13
 * @version		2.0.0 23-Jun-13
 * @version		2.1.0 16-Aug-13
 * @version		2.2.0 19-Aug-13
 * @version		2.2.1 20-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SPRITE_ENTITY_H__
#define __SPRITE_ENTITY_H__

#include <EyeProjector/BaseEntity.h>
#include <EyeProjector/ResourceManager.h>

#include <string>

/**
 * EyeProjector Namespace.
 */
namespace EP
{	
	class SpriteEntity : public BaseEntity
	{
		public:
			SpriteEntity(void);
			SpriteEntity(const SpriteEntity& src);
			virtual ~SpriteEntity(void);
			
			SpriteEntity& operator = (SpriteEntity const &src);
			
			void init(const std::string texture, const TF32 startPosX=0.0f, const TF32 startPosY=0.0f);
			void render(void);
			void release(void);
			//void setFrameDimension(const TUInt32 width, const TUInt32 height);
			void setCurrentFrame(const TUInt32 frameIndex);
			
		private:
			Texture* _texture;
			TUInt32 _currFrameIndex;
			Vector2D _frameStart;
			Vector2D _frameEnd;
			double _frameStartX;
			double _frameStartY;
			double _frameEndX;
			double _frameEndY;
	};
}

#endif