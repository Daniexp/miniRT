#include <miniRT.h>

float determinante_2x2(float **matrix) {
    float det = 0.0;
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return det;
}


float	*plane_equation(float *n, float *p)
{
	float	*eq;
	float	d;

	d = -1 * (n[0]*p[0] + n[1]*p[1] + n[2] * p[2]);
	eq = ft_calloc(4, sizeof(float));
	//if (!eq)
	//	return (NULL);
	eq[0] = n[0];
	eq[1] = n[1];
	eq[2] = n[2];
	eq[3] = d;
	return (eq);
}

float	**matrix_generator(float *v1, float *v2, float *v3)
{
	float	**matrix;
	int	i;

	i = 0;
	matrix = malloc(sizeof(float *) * 3);
	while (i < 3)
		matrix[i++] = ft_calloc(3, sizeof(float));
	matrix[0][0] = v1[0];
	matrix[0][1] = v2[0];
	matrix[0][2] = v3[0];
	matrix[1][0] = v1[1];
	matrix[1][1] = v2[1];
	matrix[1][2] = v3[1];
	matrix[2][0] = v1[2];
	matrix[2][1] = v2[2];
	matrix[2][2] = v3[2];
	return (matrix);
}

float	distance_point_plane(float *plane, float *p)
{
	float	num;
	float	den;
	float	res;

	num = plane[0] * p[0] + plane[1] * p[1] + plane[2] * p[2] + plane[3];
	if (num < 0)
		num *= -1;
	den = sqrt(plane[0] * plane[0] + plane[1] * plane[1] + plane[2] * plane[2]);
	res = num / den;
	return (res);
}

float	vec_module(float *v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

float	parallel(float *v, float *ab)
{
	float	num;
	float	den;
	float	res;

	num = vec_module(vectorial_prod(ab, v));
	den = vec_module(v);
	res = num / den;
	//printf("%f, %f, %f distancia: %f\n\n", v[0], v[1], v[2], res);
	return (res);
}

float	straight_intersect(float *v1, float *p, float *v2, float *q)
{
	float	*n;
	float	*plane;
	float	z_axis[3];

	z_axis[0] = 0;
	z_axis[1] = 0;
	z_axis[2] = 1;

	if (vec_module(vectorial_prod(v2, z_axis)) == 0)
		return (0);
	n = vectorial_prod(v1, v2);
	plane = plane_equation(n, p);
	if (plane[0] * q[0] + plane[1] * q[1] + plane[2] * q[2] + plane[3] == 0)
		return (1);
	return (0);
}

	/*t = (p[1] - q[1]) / (v1[1] - v1[0]) + (p[0] - q[0]) / (v2[0]*(v1[1] - v1[0]));
	t2 = ((p[0] - q[0]) + t * v1[0] ) / v2[0];
	//inter = ft_calloc(3, sizeof(float));
	inter[0] = p[0] + t * v1[0];
	inter[1] = p[1] + t * v1[1];
	inter[2] = p[2] + t * v1[2];

	coor[0] = q[0] + t * v2[0];
	coor[1] = q[1] + t * v2[1];
	coor[2] = q[2] + t * v2[2];

	if (inter[0] != coor[0] || inter[1] != coor[1] || inter[2] != coor[2])
		return (0);
	return (1);
}*/


float	cylinder(float *v, float *p, float *dir, float *q)
{
	float	*ab;
	float	*tmp;
	float	*n;
	float	plane;
	float	**matrix;
	float	distance;

	ab = subs_vec(p, q);
	matrix = matrix_generator(v, dir, ab);
	if (straight_intersect(v, p, dir, q) == 1)
		return (0);
	if (determinante(matrix) == 0)
	{
		distance = parallel(v, ab);
		return (distance);
	}
	n = vectorial_prod(dir, ab);
	plane = escalar_prod(v, n);
	if (plane < 0)
		plane *= -1;
	tmp = vectorial_prod(v, dir);
	distance = plane / vec_module(tmp);
	//free_arg((char **)matrix);
	//free(ab);
	//free(n);
	//free(plane);
	return (distance);
}

int	cylinder(float x[2], float *ray, float *p, t_cylinder *cy)
{
	t_vector	v;
	t_vector	u;
	t_vector	radyi;
	t_vector	pos;
	t_vector	ray_pos;
	t_vector	cy_dir;
	float	a;
	float	b;
	float	c;

	ray_pos = v_gen(p);
	pos = v_gen(cy->coord);
	cy_dir = v_gen(cy->vec);
	radyi = v_gen(ray);
	v = mult_k(cy_dir, dotprod(radyi, cy_dir));
	v = subs_vector(radyi, v);
	u = mult_k(cy_dir, dot_product(sub_vect(ray_pos, pos), cy_dir));
	u = sub_vect(sub_vect(ray_pos, pos), u);
	a = dotprod(v, v);
	b = 2 * dotprod(v, u);
	c = dotprod(u, u) - pow(cy->d / 2, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
		return (0);
	return (1);
}

float	cy_inter(float	*ray, float *p, t_cylinder *cy, 
