/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_difuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:24:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/28 10:10:31 by dexposit         ###   ########.fr       */
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

unsigned int	*difuse_color(t_light *L, float *p, float *N, float kd, unsigned int *rgb)
{
	float				*light_vect;
	int					i;
	unsigned int		*clr;

	if (!L || !p || !N || kd < 0 || !rgb)
		return (NULL);
	light_vect = (float *) ft_calloc(3, sizeof(float));
	if (!light_vect)
		return (NULL);
	clr = (unsigned int *) ft_calloc(3, sizeof(int));
	if (!clr)
		return (free(light_vect), NULL);
	i = -1;
	while (++i < 3)
		light_vect[i] = L->coord[i] - p[i];
	normalize_vector(light_vect);
	i = -1;
	while (++i < 3)
		clr[i] = (unsigned int) roundl(kd * L->rate
				* fmax(0.0, scalar_product(light_vect, N)) * rgb[i]);
	return (clr);
}
