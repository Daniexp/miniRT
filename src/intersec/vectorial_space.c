#include <miniRT.h>

float	coor_x(int i, int j, float weidth)
{
	(void)j;
	float	mid_weidth;

	mid_weidth = weidth / 2;
	return ((i - mid_weidth));
}


float	coor_y(int i, int j, float weidth)
{
	(void)i;
	float	mid_weidth;

	mid_weidth = weidth / 2;
	return ((mid_weidth - j));
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

float	***vec_space_camera(float	*camera_screen, float weidth, float height)
{
	float	***space;
	int	i;
	int	j;
	(void)camera_screen;

	space = malloc(sizeof(float **) * (weidth + 1));
	i = 0;
	j = 0;
	while (i <  weidth)
	{
		space[i] = malloc(sizeof(float *) * (height + 1));
		while (j < height)
		{
			space[i][j] = ft_calloc(3, sizeof(float));
			//space[i][j] = add_vec(camera_screen, generate_3dvec((float)coor_x(i, j, 1080), (float)coor_y(i, j, 420)));
			space[i][j] = generate_3dvec((float)coor_x(i, j, weidth), (float)coor_y(i, j, height));
			j++;
		}
		space[i][j] = NULL;
		j = 0;
		i++;
	}
	space[i] = NULL;
	return (space);
}
