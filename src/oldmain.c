// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <MLX42.h>
#include <miniRT.h>
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(int arg, char **argv)
{
	t_scene *scene;
	
	//kaaa();
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	scene = malloc(sizeof(t_scene));
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
#include <miniRT.h>

void	print_int(void	*content)
{
	printf("--%d--\n", *((int *)content));
}

int	main(int argc, char **argv)
{
	(void)argv;
/*	t_list	**sp;
	int	i;
	int	*dec;

	i = 0;
	sp = malloc(sizeof(t_list ) * 10);
	while (i < 10)
	{
		dec = malloc(sizeof(int) * 1);
		*dec = i;
		ft_lstadd_front(sp, ft_lstnew((void *)dec));
		i++;
	}
	ft_lstiter(*sp, print_int);
	(void)argv;
*/	
	if (input_error(argc) == 1)
		return (0);
	if (parse(argv[1], scene) == 1)
		return (0);
	//
	//printf("--%f--\n", scene->L.coord[1]);
	//printf("--%f--", scene->L.rate);
	//printf("--%f--\n", atofelio("23.45667"));
	//printf("--%d--", check_all_nb("23.4566,7"));
	return (0);
}	

