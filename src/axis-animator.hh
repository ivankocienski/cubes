/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * axis-animator.hh
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#ifndef _AXIS_ANIMATOR_HH_
#define _AXIS_ANIMATOR_HH_

class AxisAnimator
{
public:

	float m_value;

	AxisAnimator();
	
	void zero();
	void animate();

private:

	int m_count;
	float m_inc;

};

#endif // _AXIS_ANIMATOR_HH_

