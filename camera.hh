
#ifndef _IK_CAMERA_INC_
#define _IK_CAMERA_INC_

#include "vector3.hh"
#include "quaternion.hh"
#include "axis-animator.hh"
#include "position-animator.hh"

class Camera {
	
private:

	AxisAnimator m_roll;   /* X-Z */
	AxisAnimator m_pitch;  /* Y-Z */
	AxisAnimator m_yaw;    /* X-Y */

	PositionAnimator m_pos;

	//Vector3 m_pos;
	Quaternion m_rot;

public:

	Camera();

	void zero();
	void animate();	
	void look();
};

#endif /* _IK_CAMERA_INC_ */

