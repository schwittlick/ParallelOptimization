#include "SharedData.h"

/*
 * constructor initially calculates the number of CPU cores
*/
SharedData::SharedData(void) : OPENMP( "OM" ), SEQUENTIAL( "SM" ), OPENCL( "CL" ), GLSL( "GLSL" ), dimension( 10 )
{
	numberOfCores = determineNumberOfCores();
	this->isBenchmarkMode = false;
}

/*
 * destructor is empty so far
*/
SharedData::~SharedData(void)
{

}

/* 
 * determines the number of CPU cores being present in the comp
*/
int SharedData::determineNumberOfCores(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo( &sysinfo );
	return sysinfo.dwNumberOfProcessors;
}