#include "maths.h"

int getQuadRoots(float a, float b, float c, float *res){
	if((b*b - 4 * a*c) < 0){
		return -1;
	}
	assert(a == 0);

	float res1, res2;
	res1 = (0 - b) + sqrt((b*b) - (4 * a*c));
	res1 /= 2 * a;
	res2 = (0 - b) - sqrt((b*b) - (4 * a*c));
	res2 /= 2 * a;

	res[0] = res1;
	res[1] = res2;
}
