/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:03:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/03 19:26:46 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>
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

void	print_scene(t_scene *scene)
{
	t_list	*lst;
	t_sphere *sp;
	t_plane *pl;
	t_cylinder *cy;

	if (scene->sp)
	{
	lst = *(t_list **) scene->sp;
	while (lst)
	{
		sp = (t_sphere *) lst->content;
		printf("sp	%f,%f,%f %f %d,%d,%d\n", sp->coord[0], sp->coord[1], sp->coord[2], sp->d, sp->rgb[0], sp->rgb[1], sp->rgb[2]);
		lst = lst->next;
	}
	}
	if (scene->pl)
	{
	lst = *(t_list **) scene->pl;
	while (lst)
	{
		pl = (t_plane *) lst->content;
		printf("pl: %f,%f,%f %f,%f,%f, %d,%d,%d\n", pl->coord[0], pl->coord[1], pl->coord[2], pl->vec[0], pl->vec[1], pl->vec[2], pl->rgb[0], pl->rgb[1], pl->rgb[2]);
		lst = lst->next;
	}
		printf("A %f %d,%d,%d\n", scene->A.rate, scene->A.rgb[0], scene->A.rgb[1], scene->A.rgb[2]);
		printf("L %f,%f,%f %f\n", scene->L.rate, scene->L.coord[0], scene->L.coord[1], scene->L.coord[2]);
		printf("C %f,%f,%f %f,%f,%f, %d\n", scene->C.vec[0], scene->C.vec[1], scene->C.vec[2], scene->C.coord[0], scene->C.coord[1], scene->C.coord[2], scene->C.fov);
	}
	if (scene->cy)
	{
		lst = *(t_list **) scene->cy;
		while (lst)
		{
			cy = (t_cylinder*) lst->content;
			printf("cy: (%f, %f, %f); (%f ,%f, %f)\n", cy->coord[0], cy->coord[1], cy->coord[2], cy->vec[0], cy->vec[1], cy->vec[2]);
			printf(" radius: %f, height: %f\n", cy->d, cy->h);
			lst = lst->next;
		}
	}
	return ;
}
// Print the window width and height.
// 

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
	scene->sp = NULL;
	scene->cy = NULL;
	scene->pl = NULL;
}

int	main(int argc, char **argv)
{
	
	//atexit(leaks);
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	/* Do stuff */
	//(void)argv;
	t_scene scene;
	t_vector	v;
	t_vector	p;
	t_vector	u;
	t_vector	prod;
	t_vector	intersec;
	t_cylinder	*cy;
	t_list		*lst;
	float	distance;



	p.x = 1;
	p.y = 2;
	p.z = -2;

	v.x = 2;
	v.y = 4;
	v.z = -1;

	u.x = 1;
	u.y = 3;
	u.z = -2;


	prod = crossprod(v, u);
	printf("prod vect : (%f, %f, %f)", prod.x, prod.y, prod.z);
	prod.x = 3;
	prod.y = -1;
	prod.z = 1;

	intersec = plane_straight_inter(prod, p, v, u);
	printf("\ninter = (%f, %f, %f)", intersec.x, intersec.y, intersec.z);
	distance = plane_dot_distance(v, u, prod);
	printf("\ndistance = %f || %f", distance, 10 / sqrt(6));
	//scene = malloc(sizeof(t_scene));
	initialize(&scene);
	printf("termina initialize\n");
	if (input_error(argc) == 1)
		printf("input_error devolvio 1\n");
	else if (parse(argv[1], &scene) == 1)
		printf("parse devolvio 1\n");
	print_scene(&scene);

	lst = *(scene.cy);
	cy = (t_cylinder *)lst->content;
	printf("\ndistanciarectarecta: %f\n", cylinder(v, p, cy));
	//PARSEO DEL .RT CORRECTO
	//raytracing ray pixel-peer-pixel
	

//pintaaaaar//


	t_mlxdata	window;

	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();
	window.mlx = mlx;

	mlx_image_t	*img = paint_img(mlx, &scene);	
	//mlx_image_t *img = imgWhite(mlx);
	window.img = img;
//	paint_sphere(&window);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	//paint_sphere(&window);
	// Create and display the image.
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
//	test_pl_equation();
	mlx_loop_hook(mlx, ft_hook, &window);
	mlx_loop(mlx);
	mlx_terminate(mlx);
//	mlx_delete_image(mlx, img);
//	free(scene);
//	*/
	return (EXIT_SUCCESS);
}	
