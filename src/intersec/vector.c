/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 18:52:19 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>
#include <intersection.h>

void	get_intersection(float *vector, t_scene *scene, t_inters *res)
{
	if (!vector || !scene)
		return ;
	srchplane_inters(res, scene);
	srchsphere_inters(res, scene);
	srchcylinder_inters(res, scene);
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
