#include <miniRT.h>

float	escalar_prod(float v1[3], float v2[3])
{
	return (v1[1] * v2[1] + v1[2] * v2[2] + v1[0] * v2[0]);
}

float	*vectorial_prod(float v1[3], float v2[3])
{
	float	*prod;

	prod = ft_calloc(3, sizeof(float));
	prod[0] = v1[1] * v2[2] - v1[2] * v2[1];
	prod[1] = v1[2] * v2[0] - v1[0] * v2[2];
	prod[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return (prod);
}

float	module(float v[3])
{
	return (sqrt(pow(v[0], 2) + pow(v[1], 2) +  pow(v[2], 2)));
}

float	ctorad(float beta)
{
	float	rad;

	rad = (M_PI * beta) / 180;
	return (rad);
}

float	*add_vec(float v1[3], float v2[3])
{
	float *v3;
	int		i;

	i = 0;
	v3 = ft_calloc(3, sizeof(float));
	while (i < 3)
	{
		v3[i] = v1[i] + v2[i];
		i++;
	}
	return (v3);
}

float	*subs_vec(float v1[3], float v2[3])
{
	float *v3;
	int		i;

	i = 0;
	v3 = ft_calloc(3, sizeof(float));
	while (i < 3)
	{
		v3[i] = v2[i] - v1[i];
		i++;
	}
	return (v3);
}
/*
float	lens_radius(float alpha, float weidth)
{
	float	lens_radius;

	lens_radius = weidth / tan(ctorad(alpha));
	return (lens_radius);
}
*/
float	*unitomod(float *uni, float mod)
{
	int		i;
	float	*modular;

	modular = ft_calloc(3, sizeof(float));
	i = 0;
	while (i < 3)
	{
		modular[i] = uni[i] * mod;
		i++;
	}
	return (modular);
}

float	*modtouni(float *v)
{
	int	i;
	float *uni;
	float mod;

	mod = sqrt(pow(v[0], 2) + pow(v[1], 2) +  pow(v[2], 2));
	uni = ft_calloc(3, sizeof(float));
	i = 0;
	while (i < 3)
		uni[i++] *= mod;
	return (uni);
}

float	*screen_center(float camera[3], float v_u[3], float alpha, float weidth)
{
	(void)camera;
	float	lensradius;
	float	*camera_center;
	//float	*mid_coor;

	//mid_coor = ft_calloc(3, sizeof(float));
	camera_center = ft_calloc(3, sizeof(float));
	lensradius = lens_radius(alpha, weidth);
	camera_center = unitomod(v_u, lensradius);
	//mid_coor = add_vec(camera, camera_center);
	return (camera_center);
}
