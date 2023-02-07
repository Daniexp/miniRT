#include <miniRT.h>

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
	coef[i] = escalar_prod(n, p);
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
	n_s[2] = -v1[1] / v1[2];
	n = vectorial_prod(v1, n_s);
	return (n);
}
