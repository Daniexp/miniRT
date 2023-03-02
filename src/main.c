/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:03:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/02 16:49:29 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define WIDTH 1080
#define HEIGHT 720
void leaks(void)
{
	system("Leaks miniRT");
}
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

int	main(int argc, char **argv)
{
	
	//atexit(leaks);
	t_mlxdata	window;
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();
	window.mlx = mlx;
	/* Do stuff */
	(void)argv;
	t_scene *scene;
	scene = malloc(sizeof(t_scene));
	initialize(scene);
	if (input_error(argc) == 1)
		printf("input_error devolvio 1\n");
	else if (parse(argv[1], scene) == 1)
		printf("parse devolvio 1\n");
	//PARSEO DEL .RT CORRECTO
	//raytracing ray pixel-peer-pixel
	
	// Create and display the image.
	mlx_image_t* img = imgWhite(window.mlx);
	window.img = img;
	//mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, &window);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_delete_image(mlx, img);
	free(scene);
	return (EXIT_SUCCESS);
}	
