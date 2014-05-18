/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cube-grid.hh
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#ifndef _CUBE_GRID_HH_
#define _CUBE_GRID_HH_

#include <GL/gl.h>

class CubeGrid
{
public:

	CubeGrid();
	
	void init();
	void cleanup();
	void draw();
	
private:

	GLuint m_cubeList;
	GLuint m_texture;

};

#endif // _CUBE_GRID_HH_

