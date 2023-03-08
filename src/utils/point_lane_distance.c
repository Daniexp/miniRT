#include <miniRT.h>

float	point_lane_distance(float *p, float *v, float *q)
{
	float	*qp;
	float	*num;
	float	distance;

	qp = subs_vec(p, q);
	num = vectorial_prod(qp, v);
	distance = vec_module(num) / vec_module(v);
	return (distance);
}
