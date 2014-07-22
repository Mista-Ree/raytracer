#include "maths.h"

double getQuadRoots(double a, double b, double c){
	double disc = (b*b - 4 * a*c);
	if(disc < 0){
		return -1;
	}
	assert(a > 0.0f);
	double discriminant = sqrt(disc);
	double res1, res2;

	res1 = (-b + discriminant) / (2 * a);
	res2 = (-b - discriminant) / (2 * a);


	if (res1 > 0){
		return res1;
	}
	else if(res2 > 0){
		return res2;
	}

	return -1;
}
