/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * scene.hh
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 * anjuta is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * anjuta is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "cube-grid.hh"
#include "camera.hh"

class Scene
{
public:

	void run();
	void init();
	void cleanup();
	
private:

	CubeGrid m_cubeGrid;
	Camera m_camera;
	
};

#endif // _SCENE_HH_

