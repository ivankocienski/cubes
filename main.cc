/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2014 Me <dino@dashie>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include "scene.hh"

static Scene scene;

static void init() {

	srand(time(NULL));

	if(!glfwInit()) {
		printf("could not init glfw\n");
		exit(-1);
	}

	// Open OpenGL window
	if( !glfwOpenWindow( 640, 480, 8, 8, 8, 8, 32, 0, GLFW_WINDOW)) {
		printf("could not open window\n");
		exit(-1);
	}

	// Set tile
	glfwSetWindowTitle("CUBES!");

	scene.init();
}

static void cleanup() {
	
	scene.cleanup();

	glfwTerminate();
}


int main( int argc, char** argv ) {
 
	atexit(cleanup);
	
	init();

	scene.run();
	
	return 0;
}

