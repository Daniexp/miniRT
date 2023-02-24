#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* cross_product(float* a, float* b) {
    float* c = (float*) malloc(sizeof(float) * 3);
    c[0] = a[1]*b[2] - a[2]*b[1];
    c[1] = a[2]*b[0] - a[0]*b[2];
    c[2] = a[0]*b[1] - a[1]*b[0];
    return c;
}

float dot_product(float* a, float* b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

float* subtract(float* a, float* b) {
    float* c = (float*) malloc(sizeof(float) * 3);
    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];
    return c;
}

float straights_module(float* p1, float* d1, float* p2, float* d2) {
    float* n = cross_product(d1, d2);
    float* u = cross_product(d1, n);
    float* v = cross_product(d2, n);
    float* w = subtract(p1, p2);
    float a = dot_product(w, u);
    float b = dot_product(w, v);
    float c = dot_product(n, n);
    float d = a*a/c + b*b/c;
    float distance = sqrt(d);
    free(n);
    free(u);
    free(v);
    free(w);
    return distance;
}

float	*cylinder_intersec(float *v, float *center, float *dir, float radius)
{
	float	o[3];
	(void)radius;
	(void)center;
	(void)dir;
	(void)v;

	o[0] = 0;
	o[1] = 0;
	o[2] = 0;

	//printf("--%f--", straights_module(o, center, v, dir));
	if (straights_module(o, v, center, dir) <= radius)
	{
		return  (v);
	}
	return (NULL);
}
