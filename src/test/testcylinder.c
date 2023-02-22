#include <miniRT.h>

void	paint_cylinder(float ***sv, mlx_image_t *img)//float *center, float *dir, float radius, mlx_image_t *img)
{
	float	center[3];
	int		i;
	int		j;
	float	dir[3];
	float	radius;
	float	*intersec;

	center[0] = 0;
	center[1] = 0;
	center[2] = 7;


	dir[0] = 0;
	dir[1] = 0;
	dir[2] = 1;
	radius = 50;
	i = 0;
	j = 0;
	//intersec = cylinder_intersec(sv[i][j], center, dir, radius);
	(void)intersec;
	(void)img;
	
	while (i < 1080)
	{
		j = 0;
		while (j < 720)
		{
			intersec = cylinder_intersec(sv[i][j], center, dir, radius);
			if (intersec)
			{
				printf("EXISTE INTERSECCION: %f\n", intersec[0]);
				mlx_put_pixel(img, i, j, 0xFF0000FF);
			}
			j++;
		}
		i++;
	}
}
