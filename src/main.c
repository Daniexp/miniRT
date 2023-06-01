/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:03:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/05/31 14:03:49 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>
void leaks(void)
{
	system("leaks miniRT");
}

void freeList(t_list *head) 
{
  	t_list *current = head;
	t_list *next;
	
	while (current != NULL) 
	{
		next = current->next;
		free(current->content); 
		free(current);
		current = next;
	}
}
void freeScene(t_scene* scene)
{
	if (scene->sp)
	{
		freeList(*(scene->sp));
	   	free(scene->sp);
	}
  if (scene->cy)
  {
	  freeList(*(scene->cy));
	  free(scene->cy);
  }
  if (scene->pl)
  {
	  freeList(*(scene->pl));
  	  free(scene->pl);
  }
}

  // Asegúrate de liberar cualquier otra memoria dinámica en `scene` aquí

  // Finalmente, libera la propia escena

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

	printf("CAMERA_COORD : (%f, %f, %f)\n", scene->C.coord[0], scene->C.coord[1], scene->C.coord[2]);
	printf("CAMERA_VEC : (%f, %f, %f)\n", scene->C.vec[0], scene->C.vec[1], scene->C.vec[2]);
	printf("LIGHT_COORD : (%f, %f, %f)\n", scene->L.coord[0], scene->L.coord[1], scene->L.coord[2]);
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

void	initialize(t_scene *scene, mlx_t *mlx)
{
	scene->n_L = 0;
	scene->exit = 0;
	scene->n_C = 0;
	scene->n_A = 0;
	scene->n_sp = 0;
	scene->n_pl = 0;
	scene->n_cy = 0;
	scene->sp = NULL;
	scene->cy = NULL;
	scene->pl = NULL;
	scene->mlx = mlx;
}




int	key_hook(int keycode, mlx_t *mlx)
{
	if (keycode == 256)
	{
		mlx_terminate(mlx);
		exit(0);
	}
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
		{
			//calcular el vector del pixel

			//if (cylinder(v_gen(get_vector(i, j, mlx, scene)), v_gen(o), cy) < cy->d / 2)
			//if (is_pixel_incylinder(get_vector(i, j, mlx, scene), o, scene) == 1)

			//interseccion del vector
			mlx_put_pixel(img, i, j, get_rgba(0, 0, 0, 255));
			//if (cylinder(v_gen(get_vector(i, j, mlx, scene)), scene))
			//	mlx_put_pixel(img, i, j, get_rgba(0, 0, 255, 255));//get_rgba(clr[0], clr[1], clr[2], 255));
		}
	}
	return (img);
}


int	main(int argc, char **argv)
{
	
	//atexit(leaks);
	// MLX allows you to define its core behaviour before startup.
//	mlx_set_setting(MLX_MAXIMIZED, true);
	/* Do stuff */
	//(void)argv;
	t_scene scene;
	t_mlxdata	window;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	mlx_image_t	*img;

	if (!mlx)
		ft_error();

	//atexit(leaks);
	initialize(&scene, mlx);
	printf("termina initialize\n");
	if (input_error(argc) == 1 || parse(argv[1], &scene) == 1)
	{
		return (1);
	}
	//print_scene(&scene);
	
	if (islight_inside(&scene) == 1 || iscamera_inside(&scene) == 1)// || check_all_normalized(&scene) == 1)
	{
		printf("que pasa tucson\n");
	//atexit(leaks);
	//freeScene(&scene);
	return (0);
		//return (0);
		img = paint_all_black(WIDTH, HEIGHT, mlx);
	}
	else
	{
		rotate_scene(&scene);
	//print_scene(&scene);
		//img = paint_all_black(WIDTH, HEIGHT, mlx);
		img = paint_img(mlx, &scene);	
	}
	
	//printf("--------------\n");
	//print_scene(&scene);
	//printf("$$$$$$$$$$$$$$$$$$$$$$ %f $$$$$$$$$$$$$$$$$$$$$$$$$", lens_radius(fov_rad(scene.C.fov), 720));
	//printf("--------------\n");
	//lens_rad = lens_radius(fov_rad(scene.C.fov), WIDTH);
	//printf("&&&&&&&&&&& %f &&&&&&&&&&&&&&&&&&&&&&&\n", pixel_size(lens_rad, WIDTH, fov_rad(scene.C.fov)));
	//if (scene.sp)
	//	printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
/*
	if (iscamera_inside(&scene) == 0)
	{
		exit_and_free(scene);
		return (0);
	}
	*/
	//system("leaks miniRT");
	//printf("\ndistanciarectarecta: %f\n", cylinder(v, p, cy));
	//PARSEO DEL .RT CORRECTO
	//raytracing ray pixel-peer-pixel
	

//pintaaaaar//


	window.mlx = mlx;

	//mlx_image_t *img = imgWhite(mlx);
	window.img = img;
	(void)img;
//	paint_sphere(&window);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	//paint_sphere(&window);
	// Create and display the image.
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
//	test_pl_equation();
	print_scene(&scene);
	freeScene(&scene);
	mlx_key_hook(mlx, (void *)key_hook, (void *)mlx);
	mlx_loop_hook(mlx, ft_hook, &window);
	//mlx_hook(window.win, 17, 1L, << 17, ft_hook, &window);
	mlx_loop(mlx);
	mlx_terminate(mlx);
		//exit_and_free(&scene);
//	mlx_delete_image(mlx, img);
//	free(scene);
//	*/
	return (EXIT_SUCCESS);
}	
