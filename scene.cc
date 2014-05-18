
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glfw.h>
#include <GL/gl.h>

#include "scene.hh"

void Scene::run() {

	struct timespec ts;

	ts.tv_sec = 0;
	ts.tv_nsec = 25 * 1000000; /* 10 ms */
	
	while( glfwGetWindowParam( GLFW_OPENED ) ) {

		m_camera.animate();

	
		glfwPollEvents();

		glLoadIdentity();
		
		// Clear color buffer
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_camera.look();
		
		m_cubeGrid.draw();

		// Swap buffers
		glfwSwapBuffers();

		nanosleep( &ts, NULL );
	}

}

void Scene::init() {

	GLfloat fogColor[4]= { 0.0, 0.0, 0.0, 1.0f};
	
	glViewport(0, 0, 640, 480);

	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();     
	gluPerspective(40.0, 640.0 / 480.0, 0.25, 20.0);
	glMatrixMode(GL_MODELVIEW);
  
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glFogi( GL_FOG_MODE, GL_LINEAR);        // Fog Mode
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf( GL_FOG_DENSITY, 1.0f);              // How Dense Will The Fog Be
	glHint( GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf( GL_FOG_START, 1.0f);             // Fog Start Depth
	glFogf( GL_FOG_END, 5.0f);               // Fog End Depth
	glEnable( GL_FOG);                   // Enables GL_FOG

	glEnable( GL_CULL_FACE );
	glEnable( GL_DEPTH_TEST );

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_cubeGrid.init();
	m_camera.zero();
}

void Scene::cleanup() {

	m_cubeGrid.cleanup();
	
}



