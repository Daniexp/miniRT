#include <miniRT.h>
#include <vecpix.h>

float	*system_two(float c1, float c2, float c3, float d1, float d2, float d3)
{
	float 	y;
	float 	x;
	float	*solution;

	y = (d3 - d1 * c3 / c1) / (d2 + d1 * c2 / c1);
	x = (c3 - c2 * y) / c1;
	solution = ft_calloc(2, sizeof(float));
	solution[0] = x;
	solution[1] = y;
	return (solution);
}



float	coor_x(int i, int j, float weidth)
{
	(void)j;
	float	mid_weidth;

	mid_weidth = weidth / 2;
	return ((i - mid_weidth) * PIXEL);
}


float	coor_y(int i, int j, float weidth)
{
	(void)i;
	float	mid_weidth;

	mid_weidth = weidth / 2;
	return ((mid_weidth - j) * PIXEL);
}

float *generate_3dvec(float x, float y)
{
	float	*d;

	d = ft_calloc(3, sizeof(float));
	d[0] = x;
	d[1] = y;
	d[2] = lens_radius((float)80, 1080);
	return (d);
}

float	*y_axis_old(float *v, float alpha, float *C)
{
	float	*w;
	float	*plane;
	float	*solution;

	w = ft_calloc(3, sizeof(float));
	plane = plane_ecuation(v, C);
	solution = system_two(v[0], v[1], cos(ctorad(alpha)), plane[0], plane[1], plane[3]);
	w[0] = solution[0];
	w[1] = solution[1];
	w[3] = 0;
	return (vectorial_prod(w, v));
}

float	*x_axis_old(float *v, float *y)
{
	return (vectorial_prod(v, y));
}
