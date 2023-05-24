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

t_phong	*get_phong_params(t_inters *inters, t_scene *scene)
{
	t_phong	*df_data;
	int	type;

	if (!inters || !scene)
		return (NULL);
	df_data = (t_phong *) ft_calloc(sizeof(t_phong), 1);
	if (!df_data)
		return (NULL);
	df_data->light = &scene->L;
	df_data->ambient = &scene->A;
	df_data->point = inters->point;
	type = phong_notype(df_data, inters);
	printf("Type: %d", type);
	type = phong_sphere(df_data, inters);
	printf("Type: %d", type);
	type = phong_plane(df_data, inters);
	printf("Type: %d", type);
	type = phong_cylinder(df_data, inters, scene);
	printf("Type: %d", type);
	//df_data->shadow = difuse_shadow(inters, scene);
	return (df_data);
}
