/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:07:54 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	*sect_sphere(float *vector, float *camera, float *sphere,
		float sphere_radius)
{
	float	a;
	float	b;
	float	c;
	float	*intersection;
	float	t;

	if (!vector || !camera || !sphere || sphere_radius <= 0.0)
		return (NULL);
	a = pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2);
	b = 2 * (vector[0] * (camera[0] - sphere[0])
			+ vector[1] * (camera[1] - sphere[1])
			+ vector[2] * (camera[2] - sphere[2]));
	c = pow(sphere[0], 2) + pow(sphere[1], 2) + pow(sphere[2], 2)
		+ pow(camera[0], 2) + pow(camera[1], 2) + pow(camera[2], 2) - 2
		* (sphere[0] * camera[0] + sphere[1] * camera[1]
			+ sphere[2] * camera[2]) - pow(sphere_radius, 2);
	t = pow(b, 2) - 4 * a * c;
	if (t <= 0.0)
		return (NULL);
	intersection = ft_calloc(3, sizeof(float));
	t = (-b - sqrt(t)) / (2 * a);
	intersection[0] = camera[0] + t * vector[0];
	intersection[1] = camera[1] + t * vector[1];
	intersection[2] = camera[2] + t * vector[2];
	return (intersection);
}

float	*sp_normal(t_sphere *sp, float *p)
{
	float	*vec;
	int		i;

	if (!sp || !p)
		return (NULL);
	vec = ft_calloc(3, sizeof(float));
	i = -1;
	while (++i < 3)
		vec[i] = p[i] - sp->coord[i];
	normalize_vector(vec);
	return (vec);
}
