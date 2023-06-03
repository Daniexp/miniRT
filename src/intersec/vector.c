/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 15:17:47 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>
#include <intersection.h>

t_inters	*get_intersection(float *vector, t_scene *scene)
{
	t_inters	*res;

	if (!vector || !scene)
		return (NULL);
	res = (t_inters *) ft_calloc(sizeof(t_inters), 1);
	res->type = 3;
	res->obj = NULL;
	res->point = NULL;
	res->len_c = -1.0;
	res->vector = fdup(vector);
	res->cy = NULL;
	res->shadow = 0;
	srchplane_inters(res, scene);
	srchsphere_inters(res, scene);
	srchcylinder_inters(res, scene);
	return (res);
}

int	srchsphere_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;

	if (!data->vector || !scene || !scene->sp)
		return (-1);
	lst = *(scene->sp);
	while (lst)
	{
		fill_inters_sp(lst, data, scene, (t_sphere *) lst->content);
		lst = lst->next;
	}
	return (0);
}

int	srchplane_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;

	if (!data || !scene || !scene->pl)
		return (-1);
	lst = *(scene->pl);
	while (lst)
	{
		fill_inters_pl(lst, data, scene, (t_plane *) lst->content);
		lst = lst->next;
	}
	return (0);
}

int	srchcylinder_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;

	if (!data || !scene || !scene->cy)
		return (-1);
	lst = *(scene->cy);
	while (lst)
	{
		fill_inters_cy(lst, data, scene, (t_cylinder *) lst->content);
		lst = lst->next;
	}
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
		res += pow(camera[i] - vector[i], 2);
	return (sqrt(res));
}
