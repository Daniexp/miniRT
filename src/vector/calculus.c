#include <miniRT.h>

t_vector	mult_k(t_vector v, float k)
{
	t_vector v2;

	v2.x = v.x * k;
	v2.y = v.y * k;
	v2.z = v.z * k;
	return (v2);
}

float	dotprod(t_vector v1, t_vector v2)
{
	return (v1.x *  v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	crossprod(t_vector u, t_vector v)
{
	t_vector sol;

	sol.x = u.y * v.z - u.z *v.y;
	sol.y = -1 * (u.x * v.z - u.z * v.x);
	sol.z = u.x * v.y - u.y * v.x;
	return (sol);
}

float	vector_module(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vector	subs_vector(t_vector v, t_vector u)
{
	t_vector sol;

	sol.x = v.x - u.x;
	sol.y = v.y - u.y;
	sol.z = v.z - u.z;
	return (sol);
}

t_vector	add_vector(t_vector v, t_vector u)
{
	t_vector sol;

	sol.x = v.x + u.x;
	sol.y = v.y + u.y;
	sol.z = v.z + u.z;
	return (sol);
}

t_vector	v_gen(float *v)
{
	t_vector	sol;

	sol.x = v[0];
	sol.y = v[1];
	sol.z = v[2];
	return (sol);
}

t_vector	normalize(t_vector v)
{
	t_vector norm;
	float	mod;

	mod = vector_module(v);
	norm.x = v.x / mod;
	norm.y = v.y / mod;
	norm.z = v.z / mod;
	return (norm);
}
