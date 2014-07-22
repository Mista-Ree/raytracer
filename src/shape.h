#ifndef _SHAPE_H
#define _SHAPE_H

#include "vector.h"
#include "ray.h"
#include "colour.h"
#include "intersection.h"

class Shape{
public:
	virtual Intersection intersect(Ray *v, double *t) = 0;

	virtual Colour getColour() = 0;
	
	virtual Vector3 normal(Vector3 v) = 0;

	virtual double getDiffuse() = 0;
};

#endif