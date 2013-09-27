/**
 * @version 	1.0.0 26-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

struct DataBlock
{
	float2 position;
	float2 direction;
	float volcity;
}

__kernel void runKernel(__global const int* listSize, __global const DataBlock* listBoids, __global float2* listUpdatedBoids)
{
	for(int i=0;i < listSize;++i){
		listUpdatedBoids[i] = listBoids[i].direction;
	}
}