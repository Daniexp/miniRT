#include <miniRT.h>
#include <vecpix.h>

float	**rotate_z(float theta)
{
	float	**r_z;
	int	i;

	i = 0;
	r_z = malloc(sizeof(float *) * 3);
	while (i < 3)
		r_z[i++] = ft_calloc(3, sizeof(float));
	r_z[0][0] = cos(ctorad(theta));
	r_z[0][1] = -1 * sin(ctorad(theta));
	r_z[0][2] = 0;
	r_z[1][0] = sin(ctorad(theta));
	r_z[1][1] = cos(ctorad(theta));
	r_z[1][2] = 0;
	r_z[2][0] = 0;
	r_z[2][1] = 0;
	r_z[2][2] = 1;
	return (r_z);
}

float	**rotate_y(float beta)
{
	float	**r_y;
	int	i;

	i = 0;
	r_y = malloc(sizeof(float *) * 3);
	while (i < 3)
		r_y[i++] = ft_calloc(3, sizeof(float));
	r_y[0][0] = cos(ctorad(beta));
	r_y[0][1] = 0;
	r_y[0][2] = sin(ctorad(beta));
	r_y[1][0] = 0;
	r_y[1][1] = 1;
	r_y[1][2] = 0;
	r_y[2][0] = -1 * sin(ctorad(beta));
	r_y[2][1] = 0;
	r_y[2][2] = cos(ctorad(beta));
	return (r_y);
}

float	**rotate_x(float alfa)
{
	int	i;
	float	**r_x;

	r_x = malloc(sizeof(float *) * 3);
	i = 0;
	while (i < 3)
		r_x[i++] = ft_calloc(3, sizeof(float));
	r_x[0][0] = 1;
	r_x[0][1] = 0;
	r_x[0][2] = 0;
	r_x[1][0] = 0;
	r_x[1][1] = cos(ctorad(alfa));
	r_x[1][2] = -1 * sin(ctorad(alfa));
	r_x[2][0] = 0;
	r_x[2][1] = sin(ctorad(alfa));
	r_x[2][2] = cos(ctorad(alfa));
	return (r_x);
}

