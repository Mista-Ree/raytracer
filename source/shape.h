#ifndef _SHAPE_H
#define _SHAPE_H

#include "vector.h"
#include "ray.h"

class Shape{
public:
	virtual void intersect(Ray *v, float *t) = 0;
};

#endif