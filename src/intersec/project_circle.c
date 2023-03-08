#include <miniRT.h>

float	project_circle(float *q, float *v, float *dir, float *center, float radius)
{
	float	*plane;
	float	t;
	float	inter[3];
	//float	circle;

	plane = plane_equation(dir, center);
	if (escalar_prod(dir, q) == 0)
		return (0);

	t = - (plane[3] + escalar_prod(v, dir)) / escalar_prod(dir, q);
	inter[0] = v[0] + t * q[0];
	inter[1] = v[1] + t * q[1];
	inter[2] = v[2] + t * q[2];
	if (pow(inter[0] - center[0], 2) + pow(inter[1] - center[1], 2) + pow(inter[2] - center[2], 2) <= pow(radius, 2))
		return (1);
	return (0);
}

