#ifndef _RAY_H
#define _RAY_H
#include "vector.h"

class Ray{
public:
	Vector3 origin;
	Vector3 direction;

	Ray(Vector3 origin, Vector3 direction);


};

#endif