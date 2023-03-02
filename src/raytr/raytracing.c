/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:08 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/02 19:48:19 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <raytracing.h>

int	paint_img(mlx_t *mlx, t_scene *scene)
{
	int			i;
	int			j;
	mlx_image_t	*img;
	float		*px_vct;

	if (!mlx || !scene)
		return (-1);
	img = mlx_new_image(mlx, (int32_t) mlx->width, (int32_t) mlx->height);
	i = -1;
	while (++i < mlx->width)
	{
		j = -1;
		while (++j < mlx->height)
		{
			px_vct = get_vector(i, j, mlx, scene);
			//calcular vector
			//calcular color de ese px
				//interseccion del vector
					//dado el punto, el objeto que intersecta
						//aplicar ley de phong para ver que color tiene
			//pintar el color en la imagen
			free(px_vct);
		}
	}
	return (0);
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

