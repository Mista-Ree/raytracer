#include "sphere.h"

Sphere::Sphere(Vector3 centre, float radius){
	this->centre = centre;
	this->radius = radius;
}

void Sphere::intersect(Ray *r, float *t){
	float a, b, c;

	Vector3 temp = r->origin - this->centre;

	a = r->direction * r->direction;
	b = 2 * (r->direction * temp);
	c = (temp * temp) - (radius * radius);

	*t = getQuadRoots(a, b, c);

}