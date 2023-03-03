/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/03 13:43:47 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>

t_inters	*get_intersection(float *vector, t_scene *scene)
{
	t_inters	*res;
	if (!vector || !scene)
		return (NULL);
	res = ft_calloc(sizeof(t_inters), 1);
	res->type = 3;
	res->obj = NULL;
	res->point = NULL;
	res->len_c = -1.0;
	res->vector = vector;
	srchsphere_inters(res, scene);
	return (res);
}

int	srchsphere_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	t_sphere	*sp;
	float		*inters;
	float		len_c;

	if (!data->vector || !scene)
		return (-1);
	lst = *(scene->sp);
	while (lst)
	{
		sp = (t_sphere *) lst->content;
		inters = sect_sphere(data->vector, scene->C.coord, sp->coord, sp->d / 2.0);
		len_c = distance_inters(inters, scene->C.coord);
		if (len_c < data->len_c)
		{
			data->type = 1;
			data->obj = lst->content;
			data->point = inters;
			data->len_c = len_c;
		}
		lst = lst->next;
	}
	/*
	lst = scene->pl;
	while (*lst)
	{
		lst = lst->next;
	}
	lst = scene->cy;
	while (*lst)
	{
		lst = lst->next;
	}
	*/
	return (0);
}

float	distance_inters(float *vector, float *camera)
{
	float	res;
	int		i;
	if (!vector || !camera)
		return (-1.0);
	i = -1;
	res = 0;
	while (++i < 3)
		res += pow(vector[i] - camera[i], 2);
	return (sqrt(res));
}
