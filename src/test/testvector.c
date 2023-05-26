/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testvector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:17:07 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/05 18:32:01 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	print_vector(float x, float y, float z)
{
	printf("VECTOR-> X: %f Y: %f Z %f\n", x, y , z);
}
void	test_vector( void )
{
	t_camera	C;
	int	img_width;
	int	img_height;
	float px_size;
	float lens_rad;
	//i,j para pixel del centro
	int center[2];
	//coordenadas 2D del px respecto al centro
	float coord[2];
	float *vector;

	// test 1 DATA
	C.coord[0] = 0.0;
	C.coord[1] = 0.0;
	C.coord[2] = 0.0;
	C.vec[0] = 0.0;
	C.vec[1] = 0.0;	
	C.vec[2] = 1.0;	
	img_width = 1920;
	img_height = 1800;
	//calcular datos intermedios
	center[0] = img_height / 2;
	center[1] = img_width / 2;
	C.fov = fov_rad(180);
	lens_rad = lens_radius(C.fov, img_height);
	px_size =  pixel_size(lens_rad, img_width, 70);
	coord[0] = image_x(center[0], img_width, px_size);
	coord[1] = image_y(center[1], img_height, px_size);
	printf("PXSIZE: %f, lens_Rad: %f\n", px_size, lens_rad);
	// CAlCULAR VECTOR
	vector = px_vector(coord[0], coord[1], C.coord[0], C.coord[1], lens_rad);	
	normalize_vector(vector);
	print_vector(vector[0], vector[1], vector[2]);
	print_vector(0.0, 0.0, lens_rad);
	vector = px_vec(coord[0], coord[1], &C, lens_rad);	
	print_vector(vector[0], vector[1], vector[2]);
	normalize_vector(vector);
	print_vector(vector[0], vector[1], vector[2]);
	
}
