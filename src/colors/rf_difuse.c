/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_difuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:24:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/23 13:20:39 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>


float	*difuse_color(t_light *L, float *p, float *N, float kd, unsigned int *rgb)
{
	float				*light_vect;
	int					i;
	float				*clr;

	if (!L || !p || !N || kd < 0 || !rgb)
		return (NULL);
	light_vect = get_vector_light(L, p);
	clr = (float *) ft_calloc(3, sizeof(float));
	if (!clr)
		return (free(light_vect), NULL);
	i = -1;
	while (++i < 3)
		clr[i] = kd * L->rate * fmax(0.0, scalar_product(light_vect, N)) * (rgb[i] / 255);
	return (clr);
}

float	*get_vector_light(t_light *L, float *inters_coord)
{
	float	*light_vect;
	int	i;

	if (!L || !inters_coord)
		return (NULL);
	light_vect = (float *) ft_calloc(3, sizeof(float));
	if (!light_vect)
		return (NULL);
	i = -1;
	while (++i < 3)
		light_vect[i] = L->coord[i] - inters_coord[i];
//		light_vect[i] = p[i] - L->coord[i];
	return (normalize_vector(light_vect), light_vect);
}

int	difuse_shadow(t_inters *inters, t_scene *scene)
{
	float 		*light_vect;
	t_inters	*shadow;
	int		in_shadow;

	if (!inters || !scene || !inters->point)
		return (-1);
	in_shadow = 0;
	//Calculo del vector desde interseccion a luz  y normalizarlo	
	light_vect = get_vector_light(&scene->L, inters->point);
	shadow = get_intersection(light_vect, scene);
	if (shadow)
		in_shadow = 1;
	//Existe sombra por lo que el componente difuso es sin tener en cuenta el scalar_product()
	free(shadow);
	return (in_shadow);
}
