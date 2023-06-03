/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:02:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 15:14:40 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	image_x(int i, float image_width, float pixel_size)
{
	return ((i - image_width / 2.0) * pixel_size);
}

float	image_y(int j, float image_height, float pixel_size)
{
	return ((image_height / 2 - j) * pixel_size);
}

float	*px_vec(float image_x, float image_y, t_camera *C, float lens_radius)
{
	float	*vec;

	if (!C)
		return (NULL);
	vec = (float *) ft_calloc(3, sizeof(float));
	if (vec)
	{
		vec[0] = C->coord[0] + image_x;
		vec[1] = C->coord[1] + image_y;
		vec[2] = -lens_radius;
	}
	return (vec);
}
/*
float	*px_vector(float image_x, float image_y, float camera_x, float camera_y,
		float lens_radius)
{
	float	*vec;

	vec = (float *) ft_calloc(3, sizeof(float));
	if (!vec)
		return (NULL);
	vec[0] = camera_x + image_x;
	vec[1] = camera_y + image_y;
	vec[2] = -lens_radius;
	return (vec);
}
*/

void	normalize_vector(float *vector)
{
	float	length;

	if (!vector || is_normalize(vector))
		return ;
	length = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}
