#include <miniRT.h>
#include <vecpix.h>

void	fill_vector(float x, float y, float z, float *v)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

float *plane_ecuation(float n[3], float p[3])
{
	float	*coef;
	int		i;

	i = 0;
	coef = ft_calloc(4, sizeof(float));
	while (i < 3)
	{
		coef[i] = n[i];
		i++;
	}
	coef[i] = (-1) * escalar_prod(n, p);
	return (coef);
}

float	*normal_vector(float v1[3])
{
	float *n_s;
	float *n;


	n  = ft_calloc(3, sizeof(float));
	n_s  = ft_calloc(3, sizeof(float));
	n_s[0] = 0;
	n_s[1] = 1;
	n_s[2] = (-1) * v1[1] / v1[2];
	n = vectorial_prod(v1, n_s);
	return (n);
}

float	*v_from_plane(float *p, int r)
{
	(void)r;
	float	*v;

	v = ft_calloc(3, sizeof(float));
	if (p[0] == 0)
	{
		v[1] = -p[2];
		v[2] = p[1];
	}
	else if (p[1] == 0)
	{
		v[0] = -p[2];
		v[2] = p[0];
	}
	else if (p[2] == 0)
	{
		v[1] = -p[0];
		v[0] = p[1];
	}
	else
	{
		v[1] = -p[0];
		v[0] = p[1];
	}
	return (v);
}

/*
float	*v_from_plane(float *plane)
{
	float	*a;
	float	*b;

	a = ft_calloc(3, sizeof(float));
	b = ft_calloc(3, sizeof(float));
	fill_vector(0, 0, 0, a);
	fill_vector(0, 0, 0, b);
	if (plane[2] != 0)
		a[2] = -plane[3] / plane[2];
	else if (plane[1] != 0)
		a[1] = -plane[3] / plane[1];
	else if (plane[0] != 0)
		a[0] = -plane[3] / plane[0];

	if (plane[0] != 0)
		b[0] = -plane[3] / plane[0];
	else if (plane[1] != 0)
		b[1] = -plane[3] / plane[1];
	else if (plane[2] != 0)
		b[2] = -plane[3] / plane[2];
	return (subs_vec(b, a));
}
*/
