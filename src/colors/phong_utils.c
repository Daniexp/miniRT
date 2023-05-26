/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/05/19 11:43:31 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	scalar_product(float *v1, float *v2)
{
	if (!v1 || !v2)
		return (0.0);
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

t_phong	*get_phong_params(t_inters *inters, t_scene *scene)
{
	t_phong	*df_data;

	if (!inters || !scene)
		return (NULL);
	df_data = (t_phong *) ft_calloc(sizeof(t_phong), 1);
	if (!df_data)
		return (NULL);
	df_data->light = &(scene->L);
	df_data->ambient = &(scene->A);
	df_data->point = inters->point;
	df_data->light_vct = get_vector_light(df_data->light, df_data->point);
	normalize_vector(df_data->light_vct);
	phong_notype(df_data, inters);
	phong_sphere(df_data, inters);
	phong_plane(df_data, inters);
	phong_cylinder(df_data, inters, scene);
	//df_data->shadow = difuse_shadow(inters, scene);
	return (df_data);
}

float	*shadow_difuse_color(t_phong *data)
{
	int	i;
	float	*clr;

	if (!data->light || !data->light_vct || !data->point || data->kd < 0)
		return (NULL);
	clr = (float *) ft_calloc(3, sizeof(float));
	if (!clr)
		return (NULL);
	i = -1;
	//if (data->N && data->light_vct && data->rgb && data->kd && data->light->rate)
		while (++i < 3)
			clr[i] = data->kd * data->light->rate * (float) fmax(0.0, (double) scalar_product(data->light_vct, data->N)) * (data->rgb[i] / 255);
	//else if (!data->N && !data->rgb)
	//	while (++i < 3)
	//		clr[i] = 0;
	return (clr);
}
