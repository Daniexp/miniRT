/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:08 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/03 21:53:43 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>

mlx_image_t	*paint_img(mlx_t *mlx, t_scene *scene)
{
	int				i;
	int				j;
	mlx_image_t		*img;
	t_inters		*inters;
	unsigned int	*clr;
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
			//interseccion del vector
			inters = get_intersection(get_vector(i, j, mlx, scene), scene);
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
	normalize_vector(vct);
	return (vct);
}

