#include <miniRT.h>

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
	matrix[1][2] = v2[1];
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
/*
float cylinder(float *v1, float *p1, float *v2, float *p2) {
    float dp[3], dpv1[3], dpv2[3], v1v2[3];//, cross[3];
    float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    float dist;

    // Calculate differences
    for (int i = 0; i < 3; i++) {
        dp[i] = p2[i] - p1[i];
        dpv1[i] = dp[i]*v1[i];
        dpv2[i] = dp[i]*v2[i];
        v1v2[i] = v1[i]*v2[i];
    }

    // Calculate intermediate values
    a = dp[0]*dp[0] + dp[1]*dp[1] + dp[2]*dp[2];
    b = dp[0]*v1[0] + dp[1]*v1[1] + dp[2]*v1[2];
    c = dp[0]*v2[0] + dp[1]*v2[1] + dp[2]*v2[2];
    d = v1[0]*v1[0] + v1[1]*v1[1] + v1[2]*v1[2];
    e = v2[0]*v2[0] + v2[1]*v2[1] + v2[2]*v2[2];
    f = v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
    g = dpv1[0] + dpv1[1] + dpv1[2];
    h = dpv2[0] + dpv2[1] + dpv2[2];
    i = v1v2[0]*v1v2[0] + v1v2[1]*v1v2[1] + v1v2[2]*v1v2[2];
    j = b*f - c*d;
    k = g*f - h*d;
    l = g*e - h*f;
    m = b*k - c*j;
    n = a*d - b*b;
    o = a*f - b*c;
    p = a*e - c*c;

    // Calculate distance
    dist = sqrt(fabs(n*l - o*k + p*j) / i);

    return dist;
}
*/

float	*straight_intersect(float *v1, float *p, float *v2, float *q)
{
	float	t;
	float	t2;
	float	*inter;

	t = (p[1] - q[1]) / (v1[1] - v1[0]) + (p[0] - q[0]) / (v2[0]*(v1[1] - v1[0]));
	t2 = ((p[0] - q[0]) + t * v1[0] ) / v2[0];
	inter = ft_calloc(3, sizeof(float));
	inter[0] = p[0] + t * v1[0];
	inter[1] = p[1] + t * v1[1];
	inter[2] = p[2] + t * v1[2];
	return (inter);
}


float	cylinder(float *v, float *p, float *dir, float *q)
{
	float	*ab;
	float	*n;
	float	*plane;
	float	**matrix;
	float	distance;

	ab = subs_vec(q, p);
	matrix = matrix_generator(v, dir, ab);
	/*printf("esto es v: %f, %f, %f\n", v[0], v[1], v[2]);
	printf("esto es dir: %f, %f, %f\n", dir[0], dir[1], dir[2]);
	printf("esto es ab: %f, %f, %f\n", ab[0], ab[1], ab[2]);
	*/
	//printf("\n\n");
	//printf("%f", determinante(matrix));
	if (determinante(matrix) == 0)
	{
		//return (0);
		distance = parallel(v, ab);
		if (distance == 0)
			printf("\n\n--%f--\n\n", distance);
		return (distance);
		//printf("a saber");
	}
	//write(1, "a", 1);
	n = vectorial_prod(v, dir);
	plane = plane_equation(n, p);
	distance = distance_point_plane(plane, q);
	//write(1, "a", 1);
	//free_arg((char **)matrix);
	//free(ab);
	//free(n);
	//free(plane);
	return (distance);
}
