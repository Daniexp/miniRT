#include <miniRT.h>
#include <vecpix.h>

float	*camera_screen_coor(float	*screen_vector, float	*camera_center)
{
	float	*camera_screen;

	camera_screen = add_vec(screen_vector, camera_center);
	return (camera_screen);
}


float	***vec_space_camera(float	*camera_screen, float weidth, float height)
{
	float	***space;
	int	i;
	int	z;
	int	j;

	space = malloc(sizeof(float **) * (weidth + 1));
	i = 0;
	z = 0;
	j = 0;
	while (i <  weidth)
	{
		space[i] = malloc(sizeof(float *) * (height + 1));
		while (j < height)
		{
			space[i][j] = ft_calloc(3, sizeof(float));
			space[i][j] = add_vec(camera_screen, generate_3dvec((float)coor_x(i, j, 1080), (float)coor_y(i, j, 420)));
			j++;
		}
		j = 0;
		i++;
	}
	return (space);
}




int main()
{
	int	i;
	float	camera[3];
	float	v_u[3];
	float *vmod;
	//float	lensradius;
	float	***space;
	mlx_t *mlx = mlx_init(1080, 420, "Cohone", false);
	mlx_image_t *img;
	if (!mlx)
		printf("error fatal");
	img = mlx_new_window(mlx, (int32_t)1080, (int32_t)420);
	mlx_image_to_window(mlx, img, 0, 0);
	i = 0;
	camera[0] = 0;
	camera[1] = 0;
	camera[2] = 0;
	i = 0;
	v_u[0] = 0;
	v_u[1] = 0;
	v_u[2] = 1;
	vmod = screen_center(camera, v_u, (float)80, (float)1080);
	space = vec_space_camera(vmod, (float)1080, (float)420);
	i = 0;
	while (i < 3)
		printf("--%f--\n", vmod[i++]);
	return (0);
}
