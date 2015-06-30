
#ifndef _IK_VECTOR_INC_
#define _IK_VECTOR_INC_

class Vector3 {
private:

public:

	float x;
	float y;
	float z;

	Vector3( float, float, float );
	Vector3();

	void  zero();
	void  normalize();
	float magnitude();
	void  invert();

	Vector3 cross( const Vector3 & );
	Vector3 operator+( const Vector3 & );

	void operator*=( float );
	void operator+=( float );
	void operator+=( const Vector3& );
	
	void dump();
};

#endif /* _IK_VECTOR_INC_ */

