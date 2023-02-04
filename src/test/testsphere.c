/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:06:39 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/04 19:43:50 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <MLX42.h>

mlx_image_t*	imgWhite(mlx_t* mlx)
{
	mlx_image_t* img = mlx_new_image(mlx, (int32_t) mlx->width, (int32_t) mlx->height);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	/*
	int i,j;
	i = 0;
	while (i < (int) img->height)
	{
		j = 0;
		while (j < (int) img->width)
		{
			mlx_put_pixel(img, j, i, 0xFF0000FF);
			j++;
		}
		i++;
	}
	*/
	mlx_image_to_window(mlx, img, 0, 0);
	return (img);
}
int	paint_sphere(const t_mlxdata* inf)
{
		float	psize;
		t_camera C;
		C.coord[0] = 0.0;
		C.coord[1] = 0.0;
		C.coord[2] = 0.0;
		C.vec[0] = 0.0;
		C.vec[1] = 0.0;
		C.vec[2] = 1.0;
		normalize_vector(C.vec);
		C.fov = 90;
		C.fov = fov_rad(C.fov);
		t_sphere sp;
		sp.d = 5.0;
		sp.rgb[0] = 0;
		sp.rgb[1] = 0;
		sp.rgb[2] = 0;
		sp.coord[0] = 0.0;
		sp.coord[1] = 0.0;
		sp.coord[2] = 10.0;
		psize = pixel_size(lens_radius(C.fov, (float) inf->img->height), (float) inf->img->width);
		int i,j;
		i = 0;
		float* vec=NULL;
		float* inters=NULL;
		t_ambient	A;
		while (i < (int) inf->img->width)
		{
			j = 0;
			while ( j < (int) inf->img->height)
			{
				vec = px_vector(image_x(i, (float) inf->img->width, psize), image_y(j, (float) inf->img->height,psize), C.coord[0], C.coord[1], lens_radius(C.fov, (float) inf->img->height));
				normalize_vector(vec);
				if (vec)
				{
					printf("PIXEL SIZE: %f -------\n", psize);
					printf("i: %d j: %d  x: %f y: %f z: %f ------\n", i, j, vec[0], vec[1], vec[2]);
					inters = sect_sphere(vec, C.coord, sp.coord, sp.d / 2.0);
					if (inters)
					{
						mlx_put_pixel(inf->img, i, j, 0xFF0000FF);
						free(inters);
					}
					else
					{
						A.rate = 1.0;
						A.rgb[0] = 255;
						A.rgb[1] = 255;
						A.rgb[2] = 255;
						char *s = rgbHex(A.rgb[0], A.rgb[1], A.rgb[2]);
						mlx_put_pixel(inf->img, i, j, (uint32_t) s);
						free(s);
						//memset(inf->img->pixels + (int) (psize * i) + (int) (psize * inf->img->width * j), ambientColor(&A), sizeof(int32_t));
					}
				}

				j++;
			}
			i++;
		}
	return (0);
}

