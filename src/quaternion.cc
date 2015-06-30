
#include <iostream>

#include <math.h>

#include "quaternion.hh"
#include "vector3.hh"

#define PIOVER180 (3.14159 / 180)

Quaternion::Quaternion() {
  zero();
}

Quaternion::Quaternion(float _w, float _x, float _y, float _z) {

  w = _w;
  x = _x;
  y = _y;
  z = _z;
}

Quaternion::Quaternion( float theta, const Vector3& v ) {

  set_rot( theta, v );
}

void Quaternion::zero() {
  w = 1.0;
  x = 0.0;
  y = 0.0;
  z = 0.0;
}

void Quaternion::set_rot(float theta, const Vector3& v ) {

  theta = theta / 360 * (float)M_PI * 2;

  w = cos( theta / 2 );

  x = v.x * sin( theta / 2 );
  y = v.y * sin( theta / 2 );
  z = v.z * sin( theta / 2 );
}

void Quaternion::normalize() {
  *this *= 1.0 / magnitude(); 
}

float Quaternion::magnitude() {
  return sqrt( w * w + x * x + y * y + z * z );
}

Quaternion Quaternion::conjugate() {
  return Quaternion( w, -x, -y, -z ); 
}

Quaternion Quaternion::invert() {
  return conjugate() / magnitude();
}

void Quaternion::operator*=( float v ) {
  w *= v;
  x *= v;
  y *= v;
  z *= v;
}

Quaternion Quaternion::operator*( float v ) {
  return Quaternion( w * v, x * v, y * v, z * v ); 
}

Quaternion Quaternion::operator*( const Quaternion& q ) {
  return Quaternion(
    w * q.w - x * q.x - y * q.y - z * q.z,
    w * q.x + x * q.w + y * q.z - z * q.y,
    w * q.y + y * q.w + z * q.x - x * q.z,
    w * q.z + z * q.w + x * q.y - y * q.x 
  );
}

Vector3 Quaternion::operator*( const Vector3& v ) {

  Vector3 vn = v;

  vn.normalize();

  Quaternion vecQuat, resQuat;
	vecQuat.x = vn.x;
	vecQuat.y = vn.y;
	vecQuat.z = vn.z;
	vecQuat.w = 0.0f;
 
	resQuat = vecQuat * conjugate();
	resQuat = *this * resQuat;
 
	return Vector3(resQuat.x, resQuat.y, resQuat.z); 
}

/* there must be a better way of doing quaternion division */
Quaternion Quaternion::operator/( float v ) {
  return *this * (1.0 / v);
}

void Quaternion::dump() {

  std::cout << "quaternion[w=" << w << ", x=" << x << ", y=" << y << ", z=" << z << "]" << std::endl;
}


#define DEG2RAD ( 1.0 / 57.295 )

void Quaternion::set_PBH( float pitch, float bank, float heading ) {
  
  //57.295

  pitch   = pitch   * DEG2RAD * 0.5;
  bank    = bank    * DEG2RAD * 0.5;
  heading = heading * DEG2RAD * 0.5;

  float cp = cos(pitch);
  float sp = sin(pitch);
  float cb = cos(bank);
  float sb = sin(bank);
  float ch = cos(heading);
  float sh = sin(heading);

  w = ch * cp * cb + sh * sp * sb;
  x = ch * sp * cb + sh * cp * sb;
  y = sh * cp * cb - ch * sp * sb;
  z = ch * cp * sb - sh * sp * cb; 
}

