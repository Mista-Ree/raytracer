#ifndef _SPHERE_H
#define _SPHERE_H

#include "shape.h"
#include "ray.h"
#include "maths.h"


class Sphere : public Shape {

private:
	Vector3 centre;
	double radius;
	Colour colour;
	double diffuse;

public:

	Sphere(Vector3 pos, double radius, Colour colour);

	Intersection intersect(Ray *v, double *t);
	
	Vector3 normal(Vector3 v);

	Colour getColour();

	double getDiffuse();
};

#endif