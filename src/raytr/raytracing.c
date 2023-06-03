/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:08 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 18:47:01 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>
#include <intersection.h>

void	free_res_shadow(t_inters *res)
{
	if (!res)
		return ;
	if (res)
	{
		if (res->rgb)
			free(res->rgb);
		if (res->point)
			free(res->point);
		if (res->vector)
			free(res->vector);
		if (res->clr)
			free(res->clr);
		free(res);
	}
}

t_inters	*initialize_inters(void)
{
	t_inters	*res;

	res = (t_inters *) ft_calloc(sizeof(t_inters), 1);
	res->type = 3;
	res->obj = NULL;
	res->point = NULL;
	res->len_c = -1.0;
	res->vector = NULL;
	res->cy = NULL;
	res->shadow = 0;
	return (res);
}

int	print_inters(t_inters *data)
{
	if (!data)
		return (-1);
	printf("DATA INTERSECTION\n");
	printf("Type: %d\n", data->type);
	if (data->obj)
		printf("obj: %p\n", data->obj);
	if (data->point)
		printf("point: %f,%f,%f\n", data->point[0],
			data->point[1], data->point[2]);
	if (data->vector)
		printf("vector: %f,%f,%f\n", data->vector[0],
			data->vector[1], data->vector[2]);
	printf("len_c: %f\n", data->len_c);
	return (0);
}

mlx_image_t	*paint_img(mlx_t *mlx, t_scene *scene)
{
	int				i;
	int				j;
	mlx_image_t		*img;
	t_inters		*inters;

	if (!mlx || !scene)
		return (NULL);
	img = mlx_new_image(mlx, (int32_t) mlx->width, (int32_t) mlx->height);
	i = -1;
	while (++i < mlx->width)
	{
		j = -1;
		while (++j < mlx->height)
		{
			inters = initialize_inters();
			inters->vector = get_vector(i, j, mlx, scene);
			get_intersection(inters->vector, scene, inters);
			shadow(scene, inters);
			inters->clr = get_pnt_clr(inters, scene);
			mlx_put_pixel(img, i, j, get_rgba(inters->clr[0],
					inters->clr[1], inters->clr[2], 255));
			free_res_shadow(inters);
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
	lens_rad = lens_radius(fov_rad(scene->c.fov), mlx->width);
	px_size = pixel_size(lens_rad, mlx->width, fov_rad(scene->c.fov));
	img_x = image_x(i, mlx->width, px_size);
	img_y = image_y(j, mlx->height, px_size);
	vct = px_vec(img_x, img_y, &(scene->c), lens_rad);
	return (vct);
}
