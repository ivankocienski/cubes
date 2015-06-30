/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cube-grid.cc
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#include <iostream>

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "third-party/png++/png.hpp"

#include "cube-grid.hh"

using namespace std;

CubeGrid::CubeGrid() {
	m_cubeList = 0;
}

void CubeGrid::init() {

  {
    png::image< png::rgb_pixel >image;
    image.read("data/texture.png");

    int width  = image.get_width();
    int height = image.get_height();

    vector<unsigned char> buffer( width * height * 3 );
    unsigned char *d = buffer.data();

    for( int y = 0; y < height; y++ ) {

      png::image< png::rgb_pixel >::row_type const & row = image.get_row(y);

      for(int x = 0; x < width; x++ ) {

        *d = row.at(x).red;   d++;
        *d = row.at(x).green; d++;
        *d = row.at(x).blue;  d++;
      }
    }

    glGenTextures( 1, &m_texture );
    glBindTexture( GL_TEXTURE_2D, m_texture);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        width,
        height,
        0, // border
        GL_RGB,
        GL_UNSIGNED_BYTE,
        buffer.data()
    );
  }

	glBindTexture( GL_TEXTURE_2D, m_texture);
	
	m_cubeList = glGenLists(1);

	glLoadIdentity();     
	glNewList(m_cubeList, GL_COMPILE);

	glBegin(GL_QUADS);

	float x, y, z; 

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


