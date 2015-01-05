#include "sphere.h"

Sphere::Sphere(Vector3 centre, double radius, Colour colour) : Shape(pos){
	this->centre = centre;
	this->radius = radius;
	this->colour = colour;
	this->diffuse = 1.0;
}

Intersection Sphere::intersect(Ray *r, double *t){
	double a, b, c;

	Vector3 temp = r->origin - this->centre;

	a = r->direction * r->direction;
	b = 2 * (r->direction * temp);
	c = (temp * temp) - (radius * radius);

	*t = getQuadRoots(a, b, c);


	return Intersection((*t) * r->direction);

}

Vector3 Sphere::normal(Vector3 p){
	return centre - p; // returns a normal vector at the point p
}


Colour Sphere::getColour(){
	return this->colour;
}

double Sphere::getDiffuse(){
	return this->diffuse;
}