#ifndef _VECTOR_H
#define _VECTOR_H

using namespace std;

class Vector3{


public:
	Vector3();
	Vector3(float x, float y, float z);

	friend Vector3 operator+(const Vector3 &c1, const Vector3 &c2);
	friend Vector3 operator-(const Vector3 &c1, const Vector3 &c2);
	friend float   operator*(const Vector3 &c1, const Vector3 &c2);
	friend float   operator*(const float c1, const Vector3 &c2);

	float x();
	float y();
	float z();

	void x(float x);
	void y(float y);
	void z(float z);

private:
	float _x,_y,_z;

};

float dot(Vector3 *v1, Vector3 *v2);

Vector3 cross(Vector3 *v1, Vector3 *v2);

#endif