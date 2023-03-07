#include <miniRT.h>

float	cylinder_angle(float *v, float *center)
{
	float	alpha;

	alpha = acos(escalar_prod(v, center) / (vec_module(v) * vec_module(center)));
	return (alpha);
}

float	scala_factor(float lens_radius, float *center, float *obj_mid)
{
	float	*d;

	d = ft_calloc(3, sizeof(float));
	d[0] = obj_mid[0] - center[0];
	d[1] = obj_mid[1] - center[1];
	d[2] = obj_mid[2] - center[2];
	return (lens_radius / sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]));
}




void	paint_cylinder(float ***sv, mlx_image_t *img)//float *center, float *dir, float radius, mlx_image_t *img)
{
	float	center[3];
	int		i;
	int		j;
	float	dir[3];
	float	*q;
	float	radius;
	float	intersec;
	float	tuker;
	float	screen_center[3];
	float	height;

	(void)height;
	(void)screen_center;
	height = 100; //* scala_factor(lens_radius((float)120, 1080), screen_center, center);
	center[0] = 0;
	center[1] = 0;
	//center[2] = 0;
//	center[2] = lens_radius(fov_rad(120), 1080) + 10;
	center[2] = -200;

	dir[0] = 0;
	dir[1] = 1;
	dir[2] = 1;

	(void)tuker;
	screen_center[0] = 0;
	screen_center[1] = 0;
	screen_center[2] = 0;
	radius = 7; //* scala_factor(lens_radius((float)120, 1080), screen_center, center);
;
	i = 0;
	j = 0;
	//intersec = cylinder_intersec(sv[i][j], center, dir, radius);
	(void)intersec;
	(void)img;
	//q[1] = 720;
	///q[2] = lens_radius((float)80, 1080);
	q = ft_calloc(3, sizeof(float));
	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 720)
		{
			/*
			q = ft_calloc(3, sizeof(float));
			q[0] = i;
			q[1] = j;
			q[2] = lens_radius((float)80, 1080);
			*/
			//q = generate_3dvec((float)i, (float)j);
			intersec = cylinder(sv[i][j],q , dir, center);
			//printf("-%f-\n", intersec);
			/*if (intersec == 0)
			{
				printf("%f, %f, %f\n", sv[i][j][0], sv[i][j][1], sv[i][j][2]);
				printf("--%f--\n", lens_radius((float)80, 1080));
			}
*/
			/*if (sv[i][j][1] == 0 && intersec > radius)
			{
				printf("intersec: %f\n\n", intersec);
				printf("%f, %f, %f\n", sv[i][j][0], sv[i][j][1], sv[i][j][2]);
				printf("--%f--\n", lens_radius((float)80, 1080));
			}*/
			if (intersec <= radius) //&& cylinder_angle(sv[i][j], center) <= cylinder_angle(screen_center, center))// && intersec != -1)
			{
				//if (intersec == -1)
				//	write(1, "aaaa", 4);
				//printf("--%f--\n\n", intersec);
				//write(1, "a", 1);
				//printf("EXISTE INTERSECCION: %f\n", intersec[0]);
				if (intersect_ray_cylinder(sv[i][j], q,  dir, center, radius, height) == 1)
					mlx_put_pixel(img, i, j, 0xFF0000FF);
			}
			//free(q);
			j++;
		}
		i++;
	}
}
