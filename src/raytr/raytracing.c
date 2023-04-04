/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:08 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/04 11:58:43 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>
#include <intersection.h>

int	print_inters(t_inters *data)
{
	if (!data)
		return (-1);
	printf("DATA INTERSECTION\n");	
	printf("Type: %d\n", data->type);
	if (data->obj)
	printf("obj: %p\n", data->obj);
	if (data->point)
	printf("point: %f,%f,%f\n", data->point[0], data->point[1], data->point[2]);
	if (data->vector)
	printf("vector: %f,%f,%f\n", data->vector[0], data->vector[1], data->vector[2]);
	printf("len_c: %f\n", data->len_c);
	return (0);
}
mlx_image_t	*paint_img(mlx_t *mlx, t_scene *scene)
{
	int				i;
	int				j;
	float			*o;
	mlx_image_t		*img;
	t_inters		*inters;
	unsigned int	*clr;
	t_list			*lst;
	t_cylinder		*cy;

	lst = *(scene->cy);
	cy = (t_cylinder *) lst->content;
	(void)inters;
	(void)clr;
	o = ft_calloc(3, sizeof(float));
	o[0] = 0;
	o[1] = 0;
	o[2] = 0;
	if (!mlx || !scene)
		return (NULL);
	img = mlx_new_image(mlx, (int32_t) mlx->width, (int32_t) mlx->height);
	i = -1;
	while (++i < mlx->width)
	{
		j = -1;
		while (++j < mlx->height)
		{
			//calcular el vector del pixel

			//if (cylinder(v_gen(get_vector(i, j, mlx, scene)), v_gen(o), cy) < cy->d / 2)
			//if (is_pixel_incylinder(get_vector(i, j, mlx, scene), o, scene) == 1)

			//interseccion del vector
			inters = get_intersection(get_vector(i, j, mlx, scene), scene);

//			printf("print_inters: %d\n",print_inters(inters));

			//calcular color de ese px
			clr = get_pnt_clr(inters, scene);
			//pintar el color en la imagen
				mlx_put_pixel(img, i, j, get_rgba(clr[0], clr[1], clr[2], 255));
		}
	}
	return (img);
}

float	*get_vector(int i, int j, mlx_t *mlx, t_scene *scene)
{
	float	*vct;
	float	px_size;
	float	lens_rad;
	float	img_x;
	float	img_y;

	if (!mlx || !scene)
		return (NULL);
	lens_rad = lens_radius(fov_rad(scene->C.fov), mlx->height);
	px_size = pixel_size(lens_rad, mlx->width);
	img_x = image_x(i, mlx->width, px_size);
	img_y = image_y(j, mlx->height, px_size);
	vct = px_vector(img_x, img_y, scene->C.coord[0], scene->C.coord[1], lens_rad);
	//normalize_vector(vct);
	return (vct);
}

