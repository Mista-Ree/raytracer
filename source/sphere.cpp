#include "sphere.h"

Sphere::Sphere(Vector3 centre, float radius){
	this->centre = centre;
	this->radius = radius;
}

void Sphere::intersect(Ray *r, float *t){
	float roots[2];
	float a, b, c;

	a = (r->direction) * (r->direction);
	b = (2*(r->origin-this->centre))*(r->direction);
	c = ((r->origin-this->centre)*(r->origin-this->centre)) - (radius*radius);

	*t = getQuadRoots(a, b, c, roots);

}