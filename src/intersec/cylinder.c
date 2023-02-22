#include <miniRT.h>

float *proj_vec(float *v, float *u)
{
    float *proj = (float *)malloc(sizeof(float) * 3);
    float scalar = escalar_prod(v, u) / escalar_prod(u, u);

    proj[0] = scalar * u[0];
    proj[1] = scalar * u[1];
    proj[2] = scalar * u[2];

    return proj;
}


/*
float	*cylinder_intersec(float *v, float *center, float *dir)// float radius)
{
	float	a;
	float	b;
	float	c;
	float	t_1;
	float	t_2;
	(void)dir;

	a = pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2);
	b = -2 *(center[0] * v[0] + center[1] * v[1] + center[2] * v[2]);
	c = - (center[0]*center[0] + center[1] * center[1] + center[2] * center[2]);
	t_1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / 2*a;
	t_2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / 2*a;
	if ((t_1 && t_2) || (t_1 && !t_2) || (!t_1 && t_2))
		return (v);
	return (NULL);
}
*/


float  vector_module(float v[3])
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

float	*cylinder_intersec(float *v, float *center, float *dir, float radius)
{
	float	dist;
	float	*subs;
	float	*perp;
	float	*inter;

	subs = subs_vec(center, v);
	perp = subs_vec(subs, proj_vec(subs, dir));
	dist = vector_module(perp);
	if (dist <= radius)
	{
		inter = add_vec(v, perp);
		return (inter);
	}
	return (NULL);
}

