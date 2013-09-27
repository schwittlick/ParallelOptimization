/**
 * @mainpage Flocking Boids.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <EyeProjector/EyeProjector.h>
#include <EyeProjector/Window.h>
#include <FlockingBoidScene.h>
#include <stdlib.h>

int main(void)
{
	EP::Window& win = EP::Window::getInstance();
	
	win.setTitle("Flocking Boids - OpenMP Version");
	win.init(800, 600, true);
	win.run(new FlockingBoidScene());
	
	return EXIT_SUCCESS;
}