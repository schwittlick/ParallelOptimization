/**
 * EyeProjector	- Resource Manager Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/ResourceManager.h
 * @version 	1.0.0 20-May-13
 * @version		1.1.0 21-May-13
 * @version 	1.1.1 23-May-13
 * @version		1.2.0 27-May-13
 * @version		1.2.1 30-May-13
 * @version		1.3.0 31-May-13
 * @version		1.3.1 16-Jun-13
 * @version		1.3.2 29-Jun-13
 * @version		1.4.0 19-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com>
 */
#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <EyeProjector/Platform.h>
#include <EyeProjector/NoSuchFileException.h>
#include <EyeProjector/UnknownFileFormatException.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	enum EImageFileFormat
	{
		IMAGE_FILE_FORMAT_AUTO = 0,
		IMAGE_FILE_FORMAT_BMP = 1,
		IMAGE_FILE_FORMAT_TGA = 2
	};
	
	typedef struct _texture
	{
		TUByte* data;
		TUInt32 id;
		TInt32 width;
		TInt32 height;
		TUByte bpp;
		TUByte colorDepth;
	}Texture;
	
	typedef std::map<std::string, Texture*> TextureIdList;
	typedef std::pair<std::string, Texture*> TextureIdListItem;
	
	class ResourceManager
	{
		public:
			static ResourceManager& getInstance(void);
			static void release(void);
			
			Texture* loadTextureToGPU(const std::string path, const bool releaseTextureData=true);
			void loadTexture(Texture* texture, const std::string path, const EImageFileFormat fileFormat=IMAGE_FILE_FORMAT_AUTO) throw(NoSuchFileException, UnknownFileFormatException);
			void bindTexture(Texture* texture);
			
		private:
			ResourceManager(void);
			ResourceManager(const ResourceManager& src);
			~ResourceManager(void);
			ResourceManager& operator=(ResourceManager const &src);
			
			void _loadBmp(std::ifstream* fileHnd, Texture* texture);
			void _loadTga(std::ifstream* fileHnd, Texture* texture);
			void _releaseTextureList(void);
			
		private:
			static ResourceManager* _instance;
			
			TextureIdList _textureIdList;
			TUInt32 _lastTextureId;
	};
}

#endif