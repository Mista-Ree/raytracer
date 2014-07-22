#include "maths.h"

float getQuadRoots(float a, float b, float c){
	float disc = (b*b - 4 * a*c);
	if(disc < 0){
		return -1;
	}
	assert(a > 0.0f);
	float discriminant = sqrt(disc);
	float res1, res2;

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
