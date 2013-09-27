/**
 * EyeProjector - Platform Specific Configuration.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/Platform.h
 * @version 	1.0.0 20-May-13
 * @version		1.1.0 23-May-13
 * @version		1.2.0 09-Jun-13
 * @version		1.3.0 19-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <Glut/glut.h>
#endif

#ifdef _DEBUG
	#include <iostream>
#endif

/**
 * EyeProjector Namespace.
 */
namespace EP
{
#ifdef __x86_64__
	typedef char 				TByte;
	typedef short int			TInt16;
	typedef int 				TInt32;
	typedef unsigned char 		TUByte;
	typedef unsigned short int	TUInt16;
	typedef unsigned int 		TUInt32;
	typedef float				TF32;
	typedef double				TF64;
#elif defined __i386__
#endif
}

#endif