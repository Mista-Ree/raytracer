#ifndef _SPHERE_H
#define _SPHERE_H

#include "shape.h"
#include "ray.h"
#include "maths.h"

class Sphere : public Shape {

private:
	Vector3 centre;
	float radius;

public:

	Sphere(Vector3 pos, float radius);

	void intersect(Ray *v, float *t);
};

#endif