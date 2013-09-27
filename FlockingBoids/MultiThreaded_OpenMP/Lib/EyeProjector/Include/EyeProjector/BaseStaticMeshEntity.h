/**
 * @version 	1.0.0 15-Sep-13
 * @version		1.0.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_BASE_STATIC_MESH_ENTITY_H__
#define __EYE_PROJECTOR_BASE_STATIC_MESH_ENTITY_H__

#include <EyeProjector/BaseEntity.h>

namespace EP
{
	class BaseStaticMeshEntity : public BaseEntity
	{
		public:
			BaseStaticMeshEntity(void);
			BaseStaticMeshEntity(const Vector2D position, const TF32 width=0.0f, const TF32 height=0.0f);
			virtual ~BaseStaticMeshEntity(void);
			
			void init(void);
			
		protected:
			virtual void _createStaticMesh(void) = 0;
			virtual void _render(void);
			
		private:
			void _createStaticMeshList(void);
			
		private:
			static TUInt32 _meshId;
	};
}

#endif