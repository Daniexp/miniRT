/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:02:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/05 21:22:23 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	image_x(int i, float image_width, float pixel_size)
{
	
	return ((i - image_width / 2.0) * pixel_size);
}
float	image_y(int j, float image_height, float pixel_size)
{
	return ((j - image_height / 2.0) * pixel_size);
}
float*	px_vec(float image_x, float image_y, t_camera *C, float lens_radius)
{
	if (!C)
		return (NULL);
	float*	vec;
	vec = ft_calloc(3, sizeof(float));
	if (vec)
	{
		// la coordenada del vectores: coord_camara + lens_radius * vect_camara
		vec[0] = image_x  - C->coord[0] + lens_radius * C->vec[0];
		vec[1] = image_y - C->coord[1] + lens_radius * C->vec[1];
		vec[2] = C->coord[2] + lens_radius * C->vec[2];
	}
	return (vec);
}
float*	px_vector(float image_x, float image_y, float camera_x, float camera_y, float lens_radius)
{
	float*	vec;
	vec = ft_calloc(3, sizeof(float));
	if (!vec)
		return (NULL);
	vec[0] = image_x - camera_x;
	vec[1] = image_y - camera_y;
	vec[2] = -lens_radius;
	return (vec);
}
void normalize_vector(float* vector)
{
	if (!vector) 
		return ;
	float length = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}
