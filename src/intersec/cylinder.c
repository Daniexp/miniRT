#include <miniRT.h>

float	*plane_equation(float *n, float *p)
{
	float	*eq;
	float	d;

	d = -1 * (n[0]*p[0] + n[1]*p[1] + n[2] * p[2]);
	eq = ft_calloc(4, sizeof(float));
	eq[0] = n[0];
	eq[1] = n[1];
	eq[2] = n[2];
	eq[4] = d;
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
	matrix[1][2] = v2[1];
	matrix[2][0] = v1[2];
	matrix[2][1] = v2[2];
	matrix[2][2] = v3[2];
	return (matrix);
}

float	distance_point_plane(float *plane, float *p)
{
	int	num;
	int	den;

	num = plane[0] * p[0] + plane[1] * p[1] + plane[2] * p[2] + plane[3];
	if (num < 0)
		num *= -1;
	den = sqrt(plane[0] * plane[0] + plane[1] * plane[1] + plane[2] * plane[2]);
	return (num / den);
}

float	cylinder(float *v, float *p, float *dir, float *q)
{
	float	*ab;
	float	*n;
	float	*plane;
	float	**matrix;
	float	distance;

	ab = subs_vec(p, q);
	matrix = matrix_generator(v, dir, ab);
	/*printf("esto es v: %f, %f, %f\n", v[0], v[1], v[2]);
	printf("esto es dir: %f, %f, %f\n", dir[0], dir[1], dir[2]);
	printf("esto es ab: %f, %f, %f\n", ab[0], ab[1], ab[2]);
	*/
	//printf("\n\n");
	//printf("%f", determinante(matrix));
	if (determinante(matrix) == 0)
	{
		//printf("a saber");
		return (-1);
	}
	n = vectorial_prod(v, dir);
	plane = plane_equation(n, p);
	distance = distance_point_plane(plane, q);
	//free_arg((char **)matrix);
	free(ab);
	free(n);
	free(plane);
	return (distance);
}
