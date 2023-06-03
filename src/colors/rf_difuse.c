/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_difuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:24:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 15:06:04 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>

static float	scalar_product(float *v1, float *v2)
{
	if (!v1 || !v2)
		return (0.0);
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

float	*difuse_color(t_light *L, float *p, float *N,
		unsigned int *rgb)
{
	float				*light_vect;
	int					i;
	float				*clr;

	if (!L || !p || !N || !rgb)
		return (NULL);
	light_vect = get_vector_light(L, p);
	clr = (float *) ft_calloc(3, sizeof(float));
	if (!clr)
		return (free(light_vect), NULL);
	i = -1;
	while (++i < 3)
		clr[i] = L->rate * fmax(0.0,
				scalar_product(light_vect, N)) * (rgb[i]);
	free(light_vect);
	return (clr);
}

float	*get_vector_light(t_light *L, float *inters_coord)
{
	int	i;
	float	*light_vect;

	if (!L || !inters_coord)
		return (NULL);
	light_vect = (float *) ft_calloc(3, sizeof(float));
	if (!light_vect)
		return (NULL);
	i = -1;
	while (++i < 3)
		light_vect[i] = L->coord[i] - inters_coord[i];
	return (normalize_vector(light_vect), light_vect);
}
