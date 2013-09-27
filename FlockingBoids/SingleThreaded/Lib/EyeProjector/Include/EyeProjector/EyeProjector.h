/**
 * EyeProjector - Engine Core Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/EyeProjector.h
 * @version 	1.0.0 20-May-13
 * @version		1.0.1 21-May-13
 * @version		1.0.2 23-May-13
 * @version		1.0.3 27-May-13
 * @version		1.0.4 30-May-13
 * @version		1.1.0 31-May-13
 * @version		1.1.1 08-Jun-13
 * @version		1.2.0 09-Jun-13
 * @version		1.2.1 16-Jun-13
 * @version		1.2.2 18-Jun-13
 * @version		1.2.3 20-Jun-13
 * @version		1.2.4 22-Jun-13
 * @version		1.2.5 23-Jun-13
 * @version		1.2.6 27-Jun-13
 * @version		1.2.7 29-Jun-13
 * @version		1.2.8 11-Jul-13
 * @version		1.2.9 12-Jul-13
 * @version		1.3.0 10-Aug-13
 * @version		1.4.0 11-Aug-13
 * @version		1.4.1 13-Aug-13
 * @version		1.4.2 16-Aug-13
 * @version		1.4.3 17-Aug-13
 * @version		1.4.4 19-Aug-13
 * @version		1.4.5 20-Aug-13
 * @version		1.4.6 15-Sep-13
 * @version		1.5.0 21-Sep-13
 * @version		1.5.1 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_H__
#define __EYE_PROJECTOR_H__

#define EP_VERSION "0.22.1 BETA"
#define EP_VERSION_0_22_1_B 1

#define MEMORY_RELEASE(p) \
{ \
	if(p != NULL) \
	{ \
		p->release(); \
		delete p; \
		p = NULL;\
	} \
}

#define MEMORY_DELETE(p) \
{ \
	if(p != NULL) \
	{ \
		delete p; \
		p = NULL;\
	} \
}

#define MEMORY_DELETE_ARRAY(p) \
{ \
	if(p != NULL) \
	{ \
		delete[] p; \
		p = NULL;\
	} \
}

#include <EyeProjector/Platform.h>

#endif