
// i am totally writing this off the top of my head
//

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>

#include "camera.hh"
#include "axis-animator.hh"

Camera::Camera() {
	zero();
}

void Camera::zero() {

	m_roll.zero();
	m_pitch.zero();
	m_yaw.zero();

	m_pos.zero();
	
	m_pos.zero();
	m_rot.zero();
}

void Camera::animate() {

	m_pos.animate();
	
	m_pitch.animate();
	m_roll.animate();
	m_yaw.animate();
}

void Camera::look() {

	//float m[16];

	Vector3 pos = m_pos.to_vector();
	
	m_rot.set_PBH( m_roll.m_value, m_pitch.m_value, m_yaw.m_value );

	Vector3 up      = m_rot * Vector3( 0, 1, 0 );
	Vector3 forward = m_rot * Vector3( 0, 0, 1 );

	//Vector3 up      = Vector3( 0, 1, 0 );
	//Vector3 forward = Vector3( 0, 0, 1 );

	//up      += pos;
	//forward += pos;
	
	gluLookAt(
	    0,
	    0,
	    0,

	    forward.x,
	    forward.y,
	    forward.z,

	    up.x,
	    up.y,
		up.z
	);

	glTranslatef( pos.x, pos.y, pos.z );

	//m_rot.apply_to_matrix_as_rotation( m );

	//glLoadMatrixf( m ); 
	//glMultMatrixf( m ); 
}

