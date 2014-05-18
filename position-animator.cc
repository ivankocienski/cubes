/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * position-animator.cc
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#include <iostream>

#include <stdlib.h>

#include "position-animator.hh"
#include "vector3.hh"

using namespace std;

PositionAnimator::PositionAnimator() {
	zero();
}

void PositionAnimator::zero() {
	m_realPosition.zero();

	m_direction = 0;
	m_axis      = MT_NONE;
	m_target    = 0;
	m_speed     = 0;
}

void PositionAnimator::animate() {

	if(m_target > 0) {

		m_target -= m_speed;

		switch(m_axis) {			
			case MT_X: m_realPosition.x += m_speed * m_direction; break;
			case MT_Y: m_realPosition.y += m_speed * m_direction; break;
			case MT_Z: m_realPosition.z += m_speed * m_direction; break;
		}

		return;
	}

	// this may be 'snappy'
	m_realPosition.x = (int)m_realPosition.x;
	m_realPosition.y = (int)m_realPosition.y;
	m_realPosition.z = (int)m_realPosition.z;

	m_direction = (rand() & 1) ? 1 : -1;
	m_target    = 1 + rand() % 5;
	m_speed     = 0.00001 + 0.2 * ((double)rand() / (double)RAND_MAX);
	m_axis      = (MovementType)(rand() % MT_MAX);
}

Vector3 PositionAnimator::to_vector() {

	// is there a better way of doing this??
	
	Vector3 v( m_realPosition.x, m_realPosition.y, m_realPosition.z );

	while( v.x < 0) { v.x += 1; }
	while( v.x > 1) { v.x -= 1; }
	while( v.y < 0) { v.y += 1; }
	while( v.y > 1) { v.y -= 1; }
	while( v.z < 0) { v.z += 1; }
	while( v.z > 1) { v.z -= 1; }
	
	return v;
}

	
