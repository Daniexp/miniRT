#include <miniRT.h>
#include <vecpix.h>

typedef struct s_mlxdata{
	mlx_t *mlx;
	mlx_image_t *img;
}	t_mlxdata;

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
	int	j;

	space = malloc(sizeof(float **) * (weidth + 1));
	i = 0;
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

void	paint_sphere(float ***space, float camera[3], float sp[3], float r, mlx_image_t *img)
{
	int	i;
	float	*itrs;
	int	j;

	i = 0;
	j = 0;
	itrs = NULL;
	while (i < S_WEIDTH)
	{
		while (j < S_HEIGHT)
		{
			itrs = sect_sphere(space[i][j], camera, sp, r);
			if (itrs)
			{
				mlx_put_pixel(img, i, j, 0xFF0000FF);
				free(itrs);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
/*
static void ft_hook(void* param)
{
	const t_mlxdata* wd = (t_mlxdata *) param;
	//printf("WIDTH: %d | HEIGHT: %d\n", wd->mlx->width, wd->mlx->height);
	if (!mlx_resize_image(wd->img, wd->mlx->width, wd->mlx->height))
		printf("FATAL ERROR TRYING TO RESIZE THE IMAGE DISPLAY.\n");
	//memset(wd->img->pixels, 255, wd->img->width * wd->img->height * sizeof(int32_t));
	//pintar spherve
	//paint_sphere(wd);
}
*/
int main()
{
	t_mlxdata *window;
	float	camera[3];
	float	sp[3];
	float	v_u[3];
	float	*uni;
	float *vmod;
	float	*plane;
	float	*neo_x;
	float	*neo_y;
	//float	lensradius;
	float	***space;
	int	i;
	int	j;
	float	**matrix;

	window = malloc(sizeof(t_mlxdata));
	window->mlx = mlx_init(1080, 420, "Cohone", false);
	i = 0;
	mlx_image_t *img;
	if (!window->mlx)
		printf("error fatal");
	img = mlx_new_image(window->mlx, (int32_t)1080, (int32_t)420);
	mlx_image_to_window(window->mlx, img, 0, 0);
	window->img = img;
	camera[0] = 1;
	camera[1] = 1;
	camera[2] = 1;
	sp[0] = 0;
	sp[1] = 0;
	sp[2] = 10;
	v_u[0] = 1;
	v_u[1] = 0;
	v_u[2] = 0;
	plane = plane_ecuation(v_u, add_vec(v_u, camera));
	neo_x = v_from_plane(plane, 2);
	neo_y = vectorial_prod(plane, neo_x);
	matrix = generate_matrix(camera, sp, v_u);
	printf("ahi va la generate matrix: \n");
	j = 0;
	while (i < 3)
	{
		while (j < 3)
			printf("%f  ", matrix[i][j++]);
		printf("\n");
		i++;
		j = 0;
	}
	i = 0;
	while (i < 3)
	{
		printf("esto es neo_x: %f, ", neo_x[i++]);
	}
	printf("\n");
	i = 0;
	while (i < 3)
		printf("esto es neo_y: %f", neo_y[i++]);
	printf("\n");
	printf("prod_vectorial entre neo_x y neo_y: %f\n", escalar_prod(neo_x, neo_y));
	printf("esto otro, prod_vectorial entre neo_x y plane: %f\n", escalar_prod(neo_x, plane));
	printf("prod_vectorial entre plane y neo_y: %f\n", escalar_prod(neo_y, plane));

	vmod = screen_center(camera, v_u, (float)80, (float)1080);
	uni = modtouni(vmod, (float)sqrt(escalar_prod(vmod, vmod)));
	space = vec_space_camera(uni, (float)1080, (float)420);
	paint_sphere(space, camera, sp, 1.23, img);
	/*i = 0;
	while (i < 3)
		printf("--%f--\n", vmod[i++]);
	*/
	//mlx_loop_hook(window->mlx, ft_hook, &window);
	mlx_loop(window->mlx);
	mlx_terminate(window->mlx);
	mlx_delete_image(window->mlx, img);
	return (0);
}
/*
// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <MLX42.h>
#include <miniRT.h>
#define WIDTH 1080
#define HEIGHT 720

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
int32_t	main(void)
{
	
	kaaa();
	t_mlxdata	window;
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();
	window.mlx = mlx;
	*//*
	* Do stuff 

	// Create and display the image.
	mlx_image_t* img = imgWhite(window.mlx);
	window.img = img;
	//mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 10, 10, 0xFF0000FF);
//	test_vector();
	paint_sphere(&window);
	char * res;
	res = rgbHex(255,255,255);
	printf("res rgb: %s\n",res);
	free(res);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, &window);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_delete_image(mlx, img);
	return (EXIT_SUCCESS);
}*/
