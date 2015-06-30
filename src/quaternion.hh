
#ifndef _IK_QUATERNION_INC_
#define _IK_QUATERNION_INC_

#include "vector3.hh"

class Quaternion {
private:
  
  float w;
  float x;
  float y;
  float z;

public:

  Quaternion();
  Quaternion(float, float, float, float);
  Quaternion(float, const Vector3& );

  Quaternion conjugate();
  Quaternion invert();

  float magnitude();

  void zero();
  void set_rot(float, const Vector3& );
  void set_PBH( float, float, float);
  void normalize();

  void operator*=( float );
  Quaternion operator*( float );
  Quaternion operator/( float );

  Quaternion operator*( const Quaternion& );
  Vector3 operator*( const Vector3& );


  void dump();
};

#endif /* _IK_QUATERNION_INC_ */

