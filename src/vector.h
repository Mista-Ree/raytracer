#ifndef _VECTOR_H
#define _VECTOR_H

#include <math.h>

using namespace std;

class Vector3{


public:
	Vector3();
	Vector3(double x, double y, double z);

	friend Vector3 operator+(const Vector3 &c1, const Vector3 &c2);
	friend Vector3 operator-(const Vector3 &c1, const Vector3 &c2);
	friend double   operator*(const Vector3 &c1, const Vector3 &c2);
	friend Vector3   operator*(const double c1, const Vector3 &c2);

	double x();
	double y();
	double z();

	void x(double x);
	void y(double y);
	void z(double z);

	double _x,_y,_z;

};

double dot(Vector3 *v1, Vector3 *v2);

Vector3 cross(Vector3 *v1, Vector3 *v2);

Vector3 normalise(Vector3 v);

double mod(Vector3 v);

Vector3 reverse(Vector3 v);
#endif