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
#include <GLFW/glfw3.h>

#include "globals.hh"
#include "scene.hh"

GLFWwindow *main_window = NULL;
static Scene scene;

static void init() {

	srand(time(NULL));

	if(!glfwInit()) {
		printf("could not init glfw\n");
		exit(-1);
	}

	// Open OpenGL window
  main_window = glfwCreateWindow( 640, 480, "cubes", NULL, NULL);
	if( !main_window ) {
		printf("could not open window\n");
		exit(-1);
	}

  glfwMakeContextCurrent(main_window);

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

