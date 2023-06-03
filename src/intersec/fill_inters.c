/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_inters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:16:42 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 15:23:05 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>

void	fill_inters_sp(t_list *lst, t_inters *data,
		t_scene *scene, t_sphere *sp)
{
	float	*inters;
	float	len_c;

	inters = sect_sphere(data->vector, scene->C.coord,
			sp->coord, sp->d / 2.0);
	len_c = distance_inters(inters, scene->C.coord);
	if (inters && (data->len_c < 0.0 || len_c < data->len_c))
	{
		if (isinscreen(inters, scene) == 1)
		{
			data->type = SPHERE;
			data->obj = lst->content;
			if (data->point)
				free(data->point);
			data->point = fdup(inters);
			data->len_c = len_c;
		}
	}
	if (inters)
		free(inters);
}

void	fill_inters_cy(t_list *lst, t_inters *data,
		t_scene *scene, t_cylinder *cy)
{
	float	*inters;
	float	len_c;

	inters = cylinder(v_gen(data->vector), scene, cy);
	len_c = distance_inters(inters, scene->C.coord);
	if (inters && (data->len_c < 0.0 || len_c < data->len_c))
	{
		if (isinscreen(inters, scene) == 1)
		{
			data->type = CYLINDER;
			data->obj = lst->content;
			if (data->point)
				free(data->point);
			data->point = fdup(inters);
			data->len_c = len_c;
		}
	}
	if (inters)
		free(inters);
}

void	fill_inters_pl(t_list *lst, t_inters *data, t_scene *scene, t_plane *pl)
{
	float	*inters;
	float	len_c;

	inters = sect_plane(data->vector, &(scene->C), pl);
	len_c = distance_inters(inters, scene->C.coord);
	if (inters && (data->len_c < 0.0 || len_c < data->len_c))
	{
		if (isinscreen(inters, scene) == 1)
		{
			data->type = PLANE;
			data->obj = lst->content;
			if (data->point)
				free(data->point);
			data->point = fdup(inters);
			data->len_c = len_c;
		}
	}
	if (inters)
		free(inters);
}
