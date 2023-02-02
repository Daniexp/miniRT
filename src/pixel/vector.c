/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:02:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/02 14:15:57 by dexposit         ###   ########.fr       */
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
float*	px_vector(float image_x, float image_y, float camera_x, float camera_y, float lens_radius)
{
	float*	vec;
	vec = ft_calloc(3, sizeof(float));
	if (vec)
	{
		vec[0] = image_x - camera_x;
		vec[1] = image_y - camera_y;
		vec[2] = -lens_radius;
	}
	return (vec);
}
void normalize_vector(float* vector)
{
	float length = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}
