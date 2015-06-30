/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * position-animator.hh
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#ifndef _POSITION_ANIMATOR_HH_
#define _POSITION_ANIMATOR_HH_

#include "vector3.hh"

class PositionAnimator
{
public:

	//float m_x;
	//float m_y;
	//float m_z;
	
	PositionAnimator();
	
	void zero();
	void animate();
	Vector3 to_vector();
	
private:
	
	enum MovementType {
		MT_NONE,
		MT_X,
		MT_Y,
		MT_Z,
		MT_MAX
	};

	MovementType m_axis;
	float m_direction;
	float m_target;
	float m_speed;
	
	Vector3 m_realPosition;
};

#endif // _POSITION_ANIMATOR_HH_

