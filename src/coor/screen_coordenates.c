#include <miniRT.h>
#include <vecpix.h>

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
