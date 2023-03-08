/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:03:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/01 14:47:59 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define WIDTH 1080
#define HEIGHT 720

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
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
void	initialize(t_scene *scene)
{
	scene->n_L = 0;
	scene->n_C = 0;
	scene->n_A = 0;
	scene->n_sp = 0;
	scene->n_pl = 0;
	scene->n_cy = 0;
}

/*
int	main()
{
	float	v[3];
	float	dir[3];
	float	p[3];
	float	q[3];

	v[0] = -1;
	v[1] = 3;
	v[2] = 2;

	dir[0] = 2;
	dir[1] = 1;
	dir[2] = -1;

	p[0] = 0;
	p[1] = 2;
	p[2] = -1;

	q[0] = 1;
	q[1] = 0;
	q[2] = -1;
	printf("--%f--\n", cylinder(v, p, dir, q));
	return (0);
}
*/

int	main(int argc, char **argv)
{	
	t_mlxdata	window;
	int	width;
	int	height;
/*	float	v[3];
	float	v2[3];
	float	q[3];
	*/
	float	camera_screen[3];
	float	***sp;
	//float	*inter;
	//float	p[3];
	//float	o[3];
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();
	window.mlx = mlx;
	
	/* Do stuff */

	(void)argv;
	(void)argc;
	(void)sp;

	height = 720;
	width = 1080;
	//prueba parseo

	/*t_scene *scene;
	scene = malloc(sizeof(t_scene));
	initialize(scene);
	if (input_error(argc) == 1)
		printf("input_error devolvio 1\n");
	else if (parse(argv[1], scene) == 1)
		printf("parse devolvio 1\n");
	free(scene);*/
	// Create and display the image.
	// /*
	camera_screen[0] = 0;
	camera_screen[1] = 0;
	camera_screen[2] = 0;
/*
	v[0] = 2;
	v[1] = 4;
	v[2] = 0;

	v2[0] = 4;
	v2[1] = -2;
	v2[2] = 0;

	q[0] = 2;
	q[1] = 1;
	q[2] = 0;

	printf("--%f--\n", cylinder(v, camera_screen, v2, q));
*/

	mlx_image_t* img = imgWhite(window.mlx);
	window.img = img;
	//mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	/*p[0] = 1;
	p[1] = 0;
	p[2] = 0;

	o[0] = 0;
	o[1] = 1;
	o[2] = 0;
	*/
	//printf("--%f--\n", cylinder_angle(p, o));
	//printf("--%f--\n", lens_radius(120, 1080));
	sp = vec_space_camera(camera_screen, width, height);
	paint_cylinder(sp, img);
	//test xpm
	
	/*
	printf("XPM TEST\n");
	printf("%d\n", test_xpm(mlx));
	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 10, 10, 0xFF0000FF);
//	test_vector();
//	paint_sphere(&window);
	char * res;
	res = rgbHex(255,255,255);
	printf("res rgb: %s\n",res);
	printf("---------------------------\n");
	printf("TEST ADD_CLR_XPM()\n");
	test_addclrxpm();
	free(res);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
*/
	mlx_loop_hook(mlx, ft_hook, &window);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_delete_image(mlx, img);
	return (EXIT_SUCCESS);
}
