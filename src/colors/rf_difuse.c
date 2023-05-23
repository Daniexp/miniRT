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

static float	scalar_product(float *v1, float *v2)
{
	if (!v1 || !v2)
		return (0.0);
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

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

float	*difuse_shadow(t_inters *inters, t_scene *scene)
{
	float 		*light_vect;
	t_inters	*shadow;

	if (!inters || !scene || !inters->point)
		return (NULL);
	//Calculo del vector desde interseccion a luz  y normalizarlo	
	light_vect = get_vector_light(&scene->L, inters->point);
	shadow = get_intersection(light_vect, scene);
	if (shadow->type == NOTYPE)
		return (free(shadow), NULL);
	//Existe sombra por lo que el componente difuso es sin tener en cuenta el scalar_product()
		
	return (NULL);
}

t_difuse	*get_difuse_params(t_inters *inters, t_scene *scene)
{
	t_difuse	*df_data;

	if (!inters || !scene)
		return (NULL);
	df_data = (t_difuse *) ft_calloc(sizeof(t_difuse), 1);
	if (!df_data)
		return (NULL);
	return (NULL);
}
