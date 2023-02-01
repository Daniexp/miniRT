/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/01 17:00:53 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	*sect_sphere(float* vector, float* camera, float *sphere, float sphere_radius)
{
	float a = vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
	float b = 2 * (vector[0] * (camera[0] - sphere[0]) + vector[1] * (camera[1] - sphere[1]) + vector[2] * (camera[2] - sphere[2]));
	float c = sphere[0] * sphere[0] + sphere[1] * sphere[1] + sphere[2] * sphere[2] + camera[0] * camera[0] + camera[1] * camera[1] + camera[2] * camera[2] - 2 * (sphere[0] * camera[0] + sphere[1] * camera[1] + sphere[2] * camera[2]) - sphere_radius * sphere_radius;
	float discriminant = b * b - 4 * a * c;
	float *intersection;
	intersection = NULL;
	if (discriminant > 0.0f)
	{
		printf("EXISTE, INTERSECCIÓN\n");
//		intersection = ft_calloc(3, sizeof(float));
	}
	return (intersection);
}
