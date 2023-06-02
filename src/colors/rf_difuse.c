/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_difuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:24:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 11:50:57 by ndonaire         ###   ########.fr       */
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
	//printf("---- %f ----", scalar_product(light_vect, N));
	while (++i < 3)
		clr[i] = kd * L->rate * fmax(0.0, scalar_product(light_vect, N)) * (rgb[i]);
	free(light_vect);
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

t_phong	*get_phong_params(t_inters *inters, t_scene *scene)
{
	t_phong	*df_data;

	if (!inters || !scene)
		return (NULL);
	df_data = (t_phong *) ft_calloc(sizeof(t_phong), 1);
	if (!df_data)
		return (NULL);
	df_data->light = &scene->L;
	df_data->ambient = &scene->A;
	df_data->point = inters->point;
	df_data->shadow = difuse_shadow(inters, scene);

//	Estos parametros dependen del tipo.
	
	if (inters->type == SPHERE)
	{
		df_data->kd = KDSPHERE;
		df_data->ka = KASPHERE;
		df_data->N = NULL;
		df_data->rgb = ((t_sphere *) inters->obj)->rgb;
	}
	else if (inters->type == NOTYPE)
	{
		df_data->kd = KDNOTYPE;
		df_data->ka = KANOTYPE;
		df_data->N = NULL;
		df_data->rgb = NULL;
	}
	else if (inters->type == PLANE)
	{
		df_data->kd = KDPLANE;
		df_data->ka = KAPLANE;
		df_data->N = NULL;
		df_data->rgb = NULL;
	}
	else if (inters->type == CYLINDER)
	{
		df_data->kd = KDCYLINDER;
		df_data->ka = KACYLINDER;
		df_data->N = NULL;
		df_data->rgb = NULL;
	}
	return (df_data);
}
