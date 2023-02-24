/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:06:39 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/24 13:18:41 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <MLX42.h>

mlx_image_t*	imgWhite(mlx_t* mlx)
{
	mlx_image_t* img = mlx_new_image(mlx, (int32_t) mlx->width, (int32_t) mlx->height);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	return (img);
}
int	paint_sphere(const t_mlxdata* inf)
{
		float	psize;
		unsigned int		ambclr[3];
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
		//color de al luz ambiental
		ambclr[0] = 255;
		ambclr[1] = 0;
		ambclr[2] = 0;
		//color de la esfera
		sp.rgb[0] = 0;
		sp.rgb[1] = 0;
		sp.rgb[2] = 255;
		sp.coord[0] = 0.0;
		sp.coord[1] = 0.0;
		sp.coord[2] = 10.0;
		psize = pixel_size(lens_radius(C.fov, (float) inf->img->height), (float) inf->img->width);
		int i,j;
		i = 0;
		float* vec=NULL;
		float* inters=NULL;
//		t_ambient	A;
		while (i < (int) inf->img->width)
		{
			j = 0;
			while ( j < (int) inf->img->height)
			{
				vec = px_vector(image_x(i, (float) inf->img->width, psize), image_y(j, (float) inf->img->height,psize), C.coord[0], C.coord[1], lens_radius(C.fov, (float) inf->img->height));
				normalize_vector(vec);
					inters = sect_sphere(vec, C.coord, sp.coord, sp.d / 2.0);
					if (inters)
					{
						mlx_put_pixel(inf->img, i, j, combine_clrs_mlx(sp.rgb, ambclr));
						free(inters);
					}
				j++;
			}
			i++;
		}
	return (0);
}
