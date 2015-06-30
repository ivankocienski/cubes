/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * axis-animator.cc
 * Copyright (C) 2014 Unknown <dino@dashie>
 *
 */

#include <stdlib.h>

#include "axis-animator.hh"


AxisAnimator::AxisAnimator() {
	zero();
}
	
void AxisAnimator::zero() {
	
	m_value = 0;
	m_inc   = 0;
	m_count = 0;
}

void AxisAnimator::animate() {
	
	if(m_count) {
		m_value += m_inc;
		m_count--;
		return;
	}

	m_count = 50 + rand() % 150;

	double i = 2.0 * (0.5 - (double)rand() / (double)RAND_MAX);
	//double m =  - (double)rand() / (double)RAND_MAX);
	
	m_inc = i; 
}
