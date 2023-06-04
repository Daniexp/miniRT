/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:03:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/04 15:02:47 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracing.h>
#include <MLX42.h>
#include <libft.h>
#include <miniRT.h>

void	print_scene(t_scene *scene)
{
	printf("CAMERA_COORD : (%f, %f, %f)\n", scene->c.coord[0],
		scene->c.coord[1], scene->c.coord[2]);
	printf("CAMERA_VEC : (%f, %f, %f)\n", scene->c.vec[0],
		scene->c.vec[1], scene->c.vec[2]);
	printf("LIGHT_COORD : (%f, %f, %f)\n", scene->l.coord[0],
		scene->l.coord[1], scene->l.coord[2]);
	printf("AMBIENT: %f, (%u, %u, %u)\n", scene->a.rate,
		scene->a.rgb[0], scene->a.rgb[1], scene->a.rgb[2]);
	print_sphere(scene);
	print_plane(scene);
	print_cylinder(scene);
	return ;
}

void	initialize(t_scene *scene)
{
	scene->n_l = 0;
	scene->exit = 0;
	scene->n_c = 0;
	scene->n_a = 0;
	scene->n_sp = 0;
	scene->n_pl = 0;
	scene->n_cy = 0;
	scene->sp = NULL;
	scene->cy = NULL;
	scene->pl = NULL;
}

int	key_hook(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == 256)
		exit(0);
	return (0);
}

mlx_image_t	*paint_all_black(int width, int height, mlx_t *mlx)
{
	int				i;
	int				j;
	mlx_image_t		*img;

	img = mlx_new_image(mlx, (int32_t) width, (int32_t) height);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			mlx_put_pixel(img, i, j, get_rgba(0, 0, 0, 255));
	}
	return (img);
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!mlx)
		ft_error();
	initialize(&scene);
	if (input_error(argc) == 1 || parse(argv[1], &scene) == 1
		|| check_all_normalized(&scene) == 1)
		return (freescene(&scene), 1);
	if (islight_inside(&scene) == 1 || iscamera_inside(&scene) == 1)
		img = paint_all_black(WIDTH, HEIGHT, mlx);
	else
	{
		rotate_scene(&scene);
		img = paint_img(mlx, &scene);
	}
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_key_hook(mlx, (void *)key_hook, &scene);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (freescene(&scene), EXIT_SUCCESS);
}	
