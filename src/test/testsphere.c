/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:06:39 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/03 18:34:33 by dexposit         ###   ########.fr       */
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
		sp.d = 15.0;
		//color de al luz ambiental
		//color de la esfera
		sp.rgb[0] = 120;
		sp.rgb[1] = 0;
		sp.rgb[2] = 120;
		sp.coord[0] = -5.0;
		sp.coord[1] = 0.0;
		sp.coord[2] = -20.0;
		psize = pixel_size(lens_radius(C.fov, (float) inf->img->height), (float) inf->img->width);
		int i,j;
		i = 0;
		float* vec=NULL;
		float* inters=NULL;
		unsigned int		*clrA;
		unsigned int		*clrD;
		t_ambient	A;
		A.rgb[0] = 255;
		A.rgb[1] = 255;
		A.rgb[2] = 0;
		A.rate = 0.44;
		t_light		L;
		L.coord[0] = 50;
		L.coord[1] = 0;
		L.coord[2] = -50;
		L.rate = 1;
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
						float *vectnor = sp_normal(&sp, inters);
						/*
						clrA = ambientcolor(&A, 1.0);
						clrD = difuse_color(&L, inters, vectnor, 1.0, sp.rgb);
						printf("EL VALOR DE CLRD:ES R%d G%d B%d\n", clrD[0], clrD[1], clrD[2]);
						mlx_put_pixel(inf->img, i, j, combine_clrs_mlx(clrA, clrD));
						free(clrA);
						free(clrD);
						free(vectnor);
						*/
						unsigned int *clrC = ambientcolor(&A, 1.0);
						clrA = rgb_combine_clrs(sp.rgb, 255, clrC, 255);
//						clrA = rgb_combine_clrs(sp.rgb, 255, A.rgb, round(A.rate * 255));
//						clrA = rgb_combine_clrs(A.rgb, round(A.rate * 255), sp.rgb, 255);
						clrD = difuse_color(&L, inters, vectnor, 1.0, sp.rgb);
//						mlx_put_pixel(inf->img, i, j, combine_clrs_mlx(clrD, 255, clrA, clrA[3]));
						mlx_put_pixel(inf->img, i, j, combine_clrs_mlx(clrA, 255, clrD, 255));
						free(inters);
						free(clrA);
						free(clrD);
						free(vectnor);
					}
					else
					{
						clrA = ambientcolor(&A, 1.0);
						mlx_put_pixel(inf->img, i, j, get_rgba(clrA[0], clrA[1], clrA[2], 255));
						free(clrA);
					}
				j++;
			}
			i++;
		}
	return (0);
}
