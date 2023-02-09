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

int32_t	main(void)
{
	
	t_mlxdata	window;
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();
	window.mlx = mlx;
	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = imgWhite(window.mlx);
	window.img = img;
	//mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	//test xpm
	printf("XPM TEST\n");
	printf("%d\n", test_xpm(mlx));
	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 10, 10, 0xFF0000FF);
//	test_vector();
//	paint_sphere(&window);
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
}
