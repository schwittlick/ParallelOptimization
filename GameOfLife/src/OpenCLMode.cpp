#include "OpenCLMode.h"
#include "Cell.h"





OpenCLMode::OpenCLMode(void):
	dimension(128),
	running(true),
	file(ofToDataPath("benchmark_opencl_mode.csv"), ofFile::WriteOnly),
	elapsedFrames(0)
{
	board = new _Bool[ dimension * dimension ];

	std::cout << "OpenCLMode" << "\n";
}

OpenCLMode::~OpenCLMode(void)
{
	std::cout << "~OpenCLMode" << "\n";
}

/*
* this is called, when this state is entered. this equivalent to the constructor.
*/
void OpenCLMode::stateEnter(void)
{
	colony = new gol::Colony(dimension);

	startDeviceSelector();
	// initOpenCLStuff();
	initOpenCLBoolStuff();


	// creates a new gui and adds several sliders and buttons
	gui = new ofxUICanvas(0, 0, 350, 300);
	gui->setAutoDraw(false);
	gui->setColorBack(ofColor(0, 200));  
	gui->addWidgetDown(new ofxUILabel("Game of Life (OpenCL)", OFX_UI_FONT_LARGE)); 
	gui->addWidgetDown(new ofxUISlider(300,20,0,6144,dimension,"RESOLUTION")); 
	gui->addWidgetDown(new ofxUIButton(32, 32, false, "REINIT"));
	gui->addWidgetDown(new ofxUISlider(300,20,0,1,0.0,"RANDOMCHANCE")); 
	gui->addWidgetDown(new ofxUIToggle(32, 32, true, "RUNNING"));
	gui->addWidgetRight(new ofxUIButton(32, 32, false, "RANDOM"));
	gui->addWidgetDown(new ofxUILabel("AVERAGE TIME", OFX_UI_FONT_LARGE));
	ofAddListener(gui->newGUIEvent, this, &OpenCLMode::guiEvent); 
	//gui->loadSettings("GUI/guiSettings.xml"); 

	drawTimer = new Timer(); // starts the timer for the elapsed time during drawing the game of life.
	calculationTimer = new Timer();
	restart(); // restarts the entire animation


}

/*
* called when the state is exited. this is equivalent to the destructor.
*/
void OpenCLMode::stateExit(void)
{
	clean(); // cleaning objects from the heap.
}

size_t OpenCLMode::roundUp(int groupSize, int globalSize)
{
	int r = globalSize % groupSize;
	if(r == 0)
	{
		return globalSize;
	}
	else
	{
		return globalSize + groupSize - r;
	}
}

/*
* update method. updating values.
*/
void OpenCLMode::update()
{
	
	if( getSharedData().isBenchmarkMode )
	{
		if( elapsedFrames > 50) {
			running = false;
		} 
		else 
		{
			running = true;
		}
	}

	if(running)
	{
		calculationTimer->start();
		updateOpenCLBoolStuff( device_id );
		
		calculationTimer->stop();
		calculationTimer->store();

		// updating the board so it can be displayed. this could be displayed right away to gain some more performance but its not benchmarked anyways so left like this for clearer code
		for( int i = 0; i < dimension; ++i )
		{
			for( int j = 0; j < dimension; ++j )
			{
				int pos = i * dimension + j;
				bool alive = board[ pos ];
				colony->setCell( i, j, alive );
			}
		}

		elapsedFrames++;
	}
	else if( getSharedData().isBenchmarkMode && dimension < 4097 )
	{
		std::cout << "New Dimension: " << dimension << std::endl;
		
		elapsedFrames = 0;
		float elapsed = calculationTimer->getAverageTime();
		file << dimension << "," << elapsed << std::endl;
		dimension += 128;
		if(dimension > 4097)
		{
			file.close();
			std::cout << "Finished Benchmark for OpenCL mode." << std::endl;
		}
		restart();
	}
}

/*
* draw method. drawing the game of life.
*/
void OpenCLMode::draw()
{
	drawTimer->start();
	ofBackground(0);
	ofSetColor(255);
	ofFill();

	// determining width and height of each cell in relation to the size of the entire window
	float w = float(ofGetWidth()) / float(colony->getDimension());
	float h = float(ofGetHeight()) / float(colony->getDimension());
	// drawing all cells

	for(int y = 0; y < colony->getDimension(); y++)
	{
		for(int x = 0; x < colony->getDimension(); x++)
		{
			gol::Cell* c = colony->getCell(x, y);
			if(c->isAlive()){
				ofRect(x * w, y * h, w, h);
			}
		}
	}

	gui->draw(); // draws the gui on top of the game of life

	// draws some statistics of the elapsed times to the screen.
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 20, 250);
	//ofDrawBitmapString("neighbourCount average: "+ofToString(colony->getUpdateNeighbourTimer()->getAverageTime())+" ms", 20, 265);
	//ofDrawBitmapString("advance average: "+ofToString(colony->getAdvanceTimer()->getAverageTime())+" ms", 20, 280);
	ofDrawBitmapString("OpenCL calculation took: "+ofToString( calculationTimer->getAverageTime() ) + " ms", 20, 280 );
	// stoping the timer for the draw method
	drawTimer->stop();
	drawTimer->store();

	// drawing statistics about the draw timer to the screen. (should be included into the timer, but well, what was first, the hen or the egg?)
	ofDrawBitmapString("drawing average: "+ofToString(drawTimer->getAverageTime())+" ms", 20, 295);
	ofDrawBitmapString("elapsed time: " +ofToString( ofGetElapsedTimef() - elapsedTimeSinceLastReset )+" s", 20, 310 );

}

/*
* callback method for mouse input
*/
void OpenCLMode::mousePressed(int x, int y, int button)
{

}

/*
* returns the name of the state. important for state changes.
*/
string OpenCLMode::getName()
{
	return getSharedData().OPENCL;
}

/*
* callback method for keyboard inputs
*/
void OpenCLMode::keyPressed(int key)
{
	switch(key)
	{
		// 'c' switches to the sequential state
	case 'c':
		changeState(getSharedData().GLSL);
		break;
	default:
		break;
	}
}

/*
* callback method for gui events
*/
void OpenCLMode::guiEvent(ofxUIEventArgs &e)
{
	// adjusts the resolution of the game of life colony
	if(e.widget->getName() == "RESOLUTION")	
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;    
		dimension = int(slider->getScaledValue());
	}   
	// adjusts the ratio between dead and alive cells when reinitializing the colony
	else if(e.widget->getName() == "RANDOMCHANCE")	
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;    
		colony->setRandomChance(slider->getScaledValue());
	}  
	// toggling if the animation is running or not
	else if(e.widget->getName() == "RUNNING")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		running = toggle->getValue(); 
	}   
	// reinits the game of life and starts from a randomly initialized colony
	else if(e.widget->getName() == "REINIT")	
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		if(toggle->getValue() == false)
		{
			restart();
		}
	}  
	// randomly kills/awakes cells
	else if(e.widget->getName() == "RANDOM")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		if(toggle->getValue() == false)
		{
			colony->randomize();
		}
	} 
}

/*
* restarts the animataion entirely by creating new objects for the colony etc.
*/
void OpenCLMode::restart(void)
{
	delete colony;
	colony = new gol::Colony(dimension);
	colony->randomize();

	delete drawTimer;
	drawTimer = new Timer();

	delete calculationTimer;
	calculationTimer = new Timer();

	elapsedTimeSinceLastReset = ofGetElapsedTimef();

	initOpenCLBoolStuff();
}

/*
* cleans some objects from the heap.
*/
void OpenCLMode::clean(void)
{
	delete drawTimer;
	delete colony;
	delete gui;
}

void OpenCLMode::startDeviceSelector( void )
{
	cl_int errNum;

	cl_uint numPlatforms;

	errNum = clGetPlatformIDs( 0, nullptr, &numPlatforms );
	if( errNum != CL_SUCCESS || numPlatforms <= 0 ) 
	{
		std::cerr << "Failed to find any OpenCL platform." << std::endl;
		//return -1;
	}

	platformIds = (cl_platform_id*)alloca( sizeof( cl_platform_id) * numPlatforms );

	errNum = clGetPlatformIDs( numPlatforms, platformIds, nullptr );
	if( errNum != CL_SUCCESS  )
	{
		std::cerr << "Failed to find any OpenCL platform." << std::endl;
		//return -1;
	}

	std::cout << "There are " << numPlatforms << " platforms on the system." << std::endl;

	for( size_t i = 0; i < numPlatforms; ++i )
	{
		size_t nameSize = 0;
		errNum = clGetPlatformInfo( platformIds[i], CL_PLATFORM_NAME, 0, nullptr, &nameSize );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request the name of the platform." << std::endl;
			//return -1;
		}
		char* name = (char*)alloca( sizeof( char ) * nameSize );

		errNum = clGetPlatformInfo( platformIds[i], CL_PLATFORM_NAME, nameSize, name, nullptr );

		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request the name of the platform." << std::endl;
			//return -1;
		}

		size_t versionSize = 0;

		errNum = clGetPlatformInfo( platformIds[i], CL_PLATFORM_VERSION, 0, nullptr, &versionSize );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request the version of the platform." << std::endl;
			//return -1;

		}

		char* version = (char*)alloca( sizeof(char) * versionSize );
		errNum = clGetPlatformInfo( platformIds[i], CL_PLATFORM_VERSION, versionSize, version, nullptr );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request the version of the platform." << std::endl;
			//return -1;

		}

		std::cout << " [" << i << "] " << name << " with version: " << version << std::endl;		
	}


	std::cin >> choosenPlatform;

	cl_uint numDevices = 0;

	errNum = clGetDeviceIDs( platformIds[ choosenPlatform ], CL_DEVICE_TYPE_ALL, 0, nullptr, &numDevices ); 
	if( errNum != CL_SUCCESS )
	{
		std::cerr << "Failed to request devices of the platform." << std::endl;
		//return -1;

	}

	cl_device_id* deviceIds = (cl_device_id*)alloca( sizeof( cl_device_id ) * numDevices );

	errNum = clGetDeviceIDs( platformIds[ choosenPlatform ], CL_DEVICE_TYPE_ALL, numDevices, deviceIds, nullptr );

	std::cout << "The platform has " << numDevices << " devices." << std::endl;

	for( size_t i = 0; i < numDevices; ++i )
	{
		cl_device_type deviceType;

		errNum = clGetDeviceInfo( deviceIds[i], CL_DEVICE_TYPE, sizeof( cl_device_type ), &deviceType, nullptr );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request device type." << std::endl;
			//return -1;
		}

		char* type;
		if( deviceType == CL_DEVICE_TYPE_CPU ) {
			type = "CPU";
		} else if( deviceType == CL_DEVICE_TYPE_GPU ) {
			type = "GPU";
		} else if( deviceType == CL_DEVICE_TYPE_ACCELERATOR ) {
			type = "ACCELERATOR";
		} if( deviceType == CL_DEVICE_TYPE_DEFAULT ) {
			type = "DEFAULT";
		}  

		size_t nameSize = 0;
		clGetDeviceInfo( deviceIds[i], CL_DEVICE_NAME, 0, nullptr, &nameSize );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request device name." << std::endl;
			//return -1;
		}

		char* name = (char*)alloca( sizeof( char ) * nameSize );
		clGetDeviceInfo( deviceIds[i], CL_DEVICE_NAME, nameSize, name, nullptr );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request device name." << std::endl;
			//return -1;
		}

		cl_bool imageSupport;
		errNum = clGetDeviceInfo( deviceIds[i], CL_DEVICE_IMAGE_SUPPORT, sizeof( cl_bool ), &imageSupport, nullptr );
		if( errNum != CL_SUCCESS )
		{
			std::cerr << "Failed to request image support." << std::endl;
			//return -1;
		}

		char* imageSupportString;
		if( imageSupport ) {
			imageSupportString = "with image support";
		}
		else
		{
			imageSupportString = "without image support";
		}
		device_id = deviceIds[ i ];
		std::cout << "[" << i << "] " << type << ": " << name << " " << imageSupportString << " Device id:" << deviceIds[ i ] <<  std::endl;

		size_t max_paramter_size;
		errNum = clGetDeviceInfo( deviceIds[ i ], CL_DEVICE_MAX_PARAMETER_SIZE, sizeof( max_paramter_size ), &max_paramter_size, nullptr );

		std::cout << "CL_DEVICE_MAX_PARAMETER_SIZE = " << max_paramter_size << std::endl;

		cl_ulong max_mem_alloc;
		errNum = clGetDeviceInfo( deviceIds[ i ], CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof( max_mem_alloc), &max_mem_alloc, nullptr );
		std::cout << "CL_DEVICE_MAX_MEM_ALLOC_SIZE = " << max_mem_alloc << std::endl;
		std::cout << "I am allocating  " << dimension * dimension  << std::endl;

		size_t ret[3];
		errNum = clGetDeviceInfo( deviceIds[ i ], CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof( ret ), &ret, nullptr );

		std::cout << "DEBUG:" << std::endl;
		std::cout << "CL_DEVICE_MAX_WORK_ITEM_SIZES = " << ret[0] << " " << ret[1] << " " << ret[2] << std::endl;
	}

	size_t choosenDevice;
	std::cin >> choosenDevice;


}

void OpenCLMode::fail( std::string errorMsg)
{
	std::cerr << errorMsg << std::endl;

	clReleaseContext( context );
	clReleaseCommandQueue( commandQueue );
	clReleaseProgram( program );

	clReleaseSampler( sampler );

	clReleaseKernel( kernel );
}



void OpenCLMode::initOpenCLBoolStuff()
{
	delete board;
	board = new bool[ dimension * dimension ];

	// initializing a random array
	for( size_t i = 0; i < dimension * dimension; ++i )
	{
		if( ofRandomf() > 0.5 )
		{
			board[ i ] = true;
		}
		else
		{
			board[ i ] = false;
		}
	}

	//checking input values
	//printBoard();

	std::cout << "Starting to create Context." << std::endl;
	createContext();
	std::cout << "Finished creating Context." << std::endl;
	device_id = createCommandQueue();

	createKernel(device_id, context );
	std::cout << "Finished initializing OpenCL Bool stuff " << std::endl;
}

void OpenCLMode::updateOpenCLBoolStuff( cl_device_id device_id)
{
	//std::cout << "Started updateOpenCLBoolStuff() " << ofGetFrameNum() << std::endl;
	int err;
	size_t workgroup_size;
	err = clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE,
		sizeof(size_t), &workgroup_size, NULL);
	//workgroup_size = 32;
	if (err != CL_SUCCESS) 
	{ 
		std::cout << "ErrorNr was : " << err << std::endl;
		fail("Unable to get kernel work-group size"); 
	}

	//std::cout << "Workgroup Size: " << workgroup_size << std::endl;

	//std::cout << "sizeof( board ) " << sizeof( *board ) * dimension * dimension << std::endl;

	//std::cout << "Successfully got the kernel work group size." << std::endl;

	// the buffer is copied to the openCL stack. to the input cl_mem object.
	err = clEnqueueWriteBuffer(commandQueue, input, CL_TRUE, 0,
		sizeof( *board ) * dimension * dimension, board, 0, NULL, NULL);
	if (err != CL_SUCCESS) { fail("Unable to enqueue buffer"); }

	// enqueues the kernel to be run. on the given commandqueue and kernel.
	size_t board_size = dimension * dimension;
	err = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, &board_size,
		&workgroup_size, 0, NULL, NULL);
	if (err) 
	{
		std::cout << "Workgroup size: " << workgroup_size << std::endl;
		std::cout << "Board size: " << board_size << std::endl;
		std::cout << "ErrorNr was: " << err << std::endl;
		fail("Unable to enqueue kernel"); 
	}

	//std::cout << "Copying output to the input for the next iteration." << std::endl;
	// copies the output buffer to the input buffer for the next iteration
	err = clEnqueueCopyBuffer(commandQueue, output, input, 0, 0,
		sizeof( *board )* dimension * dimension, 0, NULL, NULL);
	if (err) { fail("Unable to enqueue copy"); }


	// reads the output buffer into the board object in order to display it on the screen.
	err = clEnqueueReadBuffer(commandQueue, output, CL_TRUE, 0,
		sizeof( *board )* dimension * dimension, board, 0, NULL, NULL );
	if (err != CL_SUCCESS) { fail("Unable to read results"); }
	//std::cout << "Trying to print out board." << std::endl;
	//printBoard();

}

void OpenCLMode::createContext()
{
	std::cout << "Started crateContext()" << std::endl;
	cl_int errNum;

	std::cout << "Chosen platform id: " << choosenPlatform << " : " << (cl_context_properties)platformIds[choosenPlatform] << std::endl;; 
	std::cout << "Device id: " << device_id << std::endl;

	cl_context_properties contextProperties[] =
	{
		CL_CONTEXT_PLATFORM,
		(cl_context_properties)platformIds[choosenPlatform],
		0
	};

	std::cout << "Context Properties: " << contextProperties[ 0 ] << " " << contextProperties[ 1 ] << " " << contextProperties[ 2 ] << std::endl;
	//context = clCreateContextFromType( contextProperties, CL_DEVICE_TYPE_GPU, nullptr, nullptr, &errNum );
	context = clCreateContext(0, 1, &device_id, NULL, NULL, &errNum );
	std::cout << "2" << std::endl;
	if( errNum != CL_SUCCESS )
	{
		std::cout << "Could not create GPU context, tying CPU...";
		context = clCreateContextFromType( contextProperties, CL_DEVICE_TYPE_CPU, nullptr, nullptr, &errNum );
		if( errNum != CL_SUCCESS )
		{
			std::cout << "FAILED" << std::endl;
			//return -1;
		}
		else
		{
			std::cout << "DONE" << std::endl;
		}
	}
	std::cout << "Finished createContext()" << std::endl;
}

cl_device_id OpenCLMode::createCommandQueue()
{
	cl_int errNum;
	size_t devicesBufferSize = -1;

	errNum = clGetContextInfo( context, CL_CONTEXT_DEVICES, 0, nullptr, &devicesBufferSize );

	if( errNum != CL_SUCCESS )
	{
		fail( "Failed to get device IDs." );
	}

	if( devicesBufferSize <= 0 )
	{
		fail( "No device is available." );
	}

	cl_device_id* devices = new cl_device_id[devicesBufferSize/sizeof(cl_device_id)];

	errNum = clGetContextInfo( context, CL_CONTEXT_DEVICES, devicesBufferSize, devices, nullptr );

	if( errNum != CL_SUCCESS )
	{
		fail( "Failed to get device IDs." );
	}

	commandQueue = clCreateCommandQueue( context, devices[0], 0, nullptr );

	if( commandQueue == nullptr )
	{
		fail( "Failed to create command queue for device 0." );
	}

	cl_device_id device = devices[0];

	std::cout << "testing device id: " << device << std::endl;

	delete [] devices;

	return device;
}

void OpenCLMode::createKernel(cl_device_id device, cl_context _context )
{
	const char *kernel_source =
		"__kernel void life(                                                     \n"
		"   constant bool*input,                                                 \n"
		"   global bool* output,                                                 \n"
		"   const unsigned int height,                                           \n"
		"   const unsigned int width)                                            \n"
		"{                                                                       \n"
		"   int i = get_global_id(0);                                            \n"
		"   int rowUp = i - width;                                               \n"
		"   int rowDown = i + width;                                             \n"
		"   bool outOfBounds = (i < width);                                      \n"
		"   outOfBounds |= (i > (width * (height-1)));                           \n"
		"   outOfBounds |= (i % width == 0);                                     \n"
		"   outOfBounds |= (i % width == width-1);                               \n"
		"   if (outOfBounds) { output[i] = false; return; }                      \n"
		"   int neighbours = input[rowUp-1] + input[rowUp] + input[rowUp+1];     \n"
		"   neighbours += input[i-1] + input[i+1];                               \n"
		"   neighbours += input[rowDown-1] + input[rowDown] + input[rowDown+1];  \n"
		"   if (neighbours == 3 || (input[i] && neighbours == 2))                \n"
		"       output[i] = true;                                                \n"
		"   else                                                                 \n"
		"       output[i] = false;                                               \n"
		"}                                                                       \n";



	kernel = createKernelFromSource( device, _context, kernel_source, "life" );
	std::cout << "Successfully created Kernel." << std::endl;
	input = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof( *board )* dimension * dimension, NULL,
		NULL);
	output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof( *board )* dimension * dimension, NULL,
		NULL);
	if (!input || !output) { fail("Unable to create buffers"); }


	int err = 0;
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
	err |= clSetKernelArg(kernel, 2, sizeof(dimension), &dimension );
	err |= clSetKernelArg(kernel, 3, sizeof(dimension), &dimension );
	if (err != CL_SUCCESS) { fail("Unable to set arguments"); }
}

cl_kernel OpenCLMode::createKernelFromSource(cl_device_id device_id, cl_context context,
											 const char *source, const char *name)
{
	int err;
	// Load the source
	cl_program program = clCreateProgramWithSource(context, 1, &source , NULL,
		&err);
	if (err != CL_SUCCESS) { fail("Unable to create program"); }

	// Compile it.
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		size_t len;
		char buffer[2048];
		clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG,
			sizeof(buffer), buffer, &len);
		fprintf(stderr, "%s\n", buffer);
		fail("Unable to build program");
	}
	// Load it.
	cl_kernel kernel = clCreateKernel(program, name, &err);
	if (!kernel || err != CL_SUCCESS) { fail("Unable to create kernel"); }
	clReleaseProgram(program);

	return kernel;
}

void OpenCLMode::printBoard()
{
	for( size_t i = 0; i < dimension; ++i )
	{
		for( size_t j = 0; j < dimension; ++j )
		{
			int pos = i * dimension + j;
			std::cout << board[ pos ] << " ";
		}
		std:: cout << std::endl;
	}
}