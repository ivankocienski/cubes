/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cube-grid.cc
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#include <iostream>

#include <GL/gl.h>
#include <GL/glfw.h>
#include <stdio.h>
#include <stdlib.h>

#include "cube-grid.hh"

using namespace std;

CubeGrid::CubeGrid() {
	m_cubeList = 0;
}

void CubeGrid::init() {

	float x, y, z;


	glGenTextures(1, &m_texture);

	glBindTexture( GL_TEXTURE_2D, m_texture);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	if( !glfwLoadTexture2D( "texture.tga", GLFW_ORIGIN_UL_BIT ) ) {
		cerr << "could not load texture" << endl;
		exit(-1);
	}

	glBindTexture( GL_TEXTURE_2D, m_texture);
	
	m_cubeList = glGenLists(1);

	glLoadIdentity();     
	glNewList(m_cubeList, GL_COMPILE);

	glBegin(GL_QUADS);

	for(z = -5.5; z < 5.5; z += 1.0)
		for(y = -5.5; y < 5.5; y += 1.0)
		for(x = -5.5; x < 5.5; x += 1.0) {

			glColor3f( 1.0, 1.0, 1.0 );

			/* front */
			glTexCoord2d(0, 1); glVertex3f( x + -0.25, y +  0.25, z +  0.25);
			glTexCoord2d(0, 0); glVertex3f( x + -0.25, y + -0.25, z +  0.25);
			glTexCoord2d(1, 0); glVertex3f( x +  0.25, y + -0.25, z +  0.25);
			glTexCoord2d(1, 1); glVertex3f( x +  0.25, y +  0.25, z +  0.25);

			/* back */
			glTexCoord2d(0, 0); glVertex3f( x +  0.25, y +  0.25, z + -0.25);
			glTexCoord2d(0, 1); glVertex3f( x +  0.25, y + -0.25, z + -0.25);
			glTexCoord2d(1, 1); glVertex3f( x + -0.25, y + -0.25, z + -0.25);
			glTexCoord2d(1, 0); glVertex3f( x + -0.25, y +  0.25, z + -0.25);

			glColor3f( 0.95, 0.95, 0.95 );

			/* left */
			glTexCoord2d(0, 0); glVertex3f( x + -0.25, y +  0.25, z +  0.25);
			glTexCoord2d(0, 1); glVertex3f( x + -0.25, y +  0.25, z + -0.25);
			glTexCoord2d(1, 1); glVertex3f( x + -0.25, y + -0.25, z + -0.25);
			glTexCoord2d(1, 0); glVertex3f( x + -0.25, y + -0.25, z +  0.25);

			/* right */
			glTexCoord2d(0, 0); glVertex3f( x +  0.25, y +  0.25, z +  0.25);
			glTexCoord2d(1, 0); glVertex3f( x +  0.25, y + -0.25, z +  0.25);
			glTexCoord2d(1, 1); glVertex3f( x +  0.25, y + -0.25, z + -0.25);
			glTexCoord2d(0, 1); glVertex3f( x +  0.25, y +  0.25, z + -0.25);

			glColor3f( 0.90, 0.90, 0.90 );

			/* top */
			glTexCoord2d(0, 0); glVertex3f( x +  0.25, y +  0.25, z +  0.25);
			glTexCoord2d(0, 1); glVertex3f( x +  0.25, y +  0.25, z + -0.25);
			glTexCoord2d(1, 1); glVertex3f( x + -0.25, y +  0.25, z + -0.25);
			glTexCoord2d(1, 0); glVertex3f( x + -0.25, y +  0.25, z +  0.25);

			/* bottom */
			glTexCoord2d(0, 0); glVertex3f( x +  0.25, y + -0.25, z +  0.25);
			glTexCoord2d(1, 0); glVertex3f( x + -0.25, y + -0.25, z +  0.25);
			glTexCoord2d(1, 1); glVertex3f( x + -0.25, y + -0.25, z + -0.25);
			glTexCoord2d(0, 1); glVertex3f( x +  0.25, y + -0.25, z + -0.25);

		}

	glEnd();

	glEndList();
}

void CubeGrid::cleanup() {
	if(m_texture)  glDeleteTextures(1, &m_texture);
	if(m_cubeList) glDeleteLists(m_cubeList, 1);
}

void CubeGrid::draw() {

	glBindTexture( GL_TEXTURE_2D, m_texture);
	
	glCallList(m_cubeList);
}


