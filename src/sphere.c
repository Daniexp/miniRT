/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/05 21:22:51 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	escalar_prod(float v1[3], float v2[3])
{
	return (v1[1] * v2[1] + v1[2] * v2[2] + v1[0] * v2[0]);
}


float	*sect_sphere(float *v, float *camera, float *sp, float r)
{
	float a = escalar_prod(v, v);
	float b = 2 * (v[0] * (camera[0] - sp[0]) + v[1] * (camera[1] - sp[1]) + v[2] * (camera[2] - sp[2]));
	float c = escalar_prod(sp, sp) + escalar_prod(camera, camera) - 2*escalar_prod(sp, camera) - pow(r, 2);
	float disc = pow(b, 2) - 4 * a * c;
	float *inters;
	float t;
	inters = NULL;
	if (disc > 0)
	{
		inters = ft_calloc(3, sizeof(float));
		t = (-b - sqrt(disc)) / (2 * a);
		inters[0] = camera[0] + t * v[0];
		inters[1] = camera[1] + t * v[1];
		inters[2] = camera[2] + t * v[2];
	}
	return (inters);
}
/*
float	*sect_sphere(float* v, float* camera, float *sphere, float sphere_radius)
{
	if (!v || !camera || !sphere || sphere_radius <= 0.0)
		return (NULL);
	float a = v[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
	float b = 2 * (v[0] * (camera[0] - sphere[0]) + vector[1] * (camera[1] - sphere[1]) + vector[2] * (camera[2] - sphere[2]));
	float c = sphere[0] * sphere[0] + sphere[1] * sphere[1] + sphere[2] * sphere[2] + camera[0] * camera[0] + camera[1] * camera[1] + camera[2] * camera[2] - 2 * (sphere[0] * camera[0] + sphere[1] * camera[1] + sphere[2] * camera[2]) - sphere_radius * sphere_radius;
	float discriminant = b * b - 4 * a * c;
	float *intersection;
	float t;
	intersection = NULL;
	printf("DISCRIMINANT:-----------> %f\n", discriminant);
	if (discriminant > 0)
	{
		printf("EXISTE, INTERSECCIÓN\n");
		intersection = ft_calloc(3, sizeof(float));
		t = (-b - sqrt(discriminant)) / (2 * a);
		intersection[0] = camera[0] + t * v[0];
		intersection[1] = camera[1] + t * v[1];
		intersection[2] = camera[2] + t * v[2];
	}
	return (intersection);
}
*/
