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

float2 calcAlignment(DataBlock* list, unsigned int size, DataBlock* currBlock)
{
	float2 avgDirection(0.0f, 0.0f);
	unsigned int count = 0;
	
	for(unsigned int i=0;i < size;++i)
	{
		float2 diff = list[i].position - currBlock.position;
		 
		if(sqrt((diff.x * diff.x) + (diff.y * diff.y))  < NEIGHBOR_AREA)
		{
			avgDirection += list[i].direction;
		
			++count;
		}
	}
	
	if(count > 0)
	{
		avgDirection /= (float)count;
		avgDirection.normalize();
	}
	
	return avgDirection;
}

__kernel void runKernel(__global const int* listSize, __global const DataBlock* listBoids, __global float2* listUpdatedBoids)
{
	for(int i=0;i < listSize;++i){
		listUpdatedBoids[i] = listBoids[i].direction;
	}
}