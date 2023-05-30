/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islight_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/25 14:13:56 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	islight_incylinder(t_scene *scene, t_cylinder *cy)
{
	t_util_plane	bot;
	t_util_plane	top;

	bot = pleq(invert(v_gen(cy->vec)), v_gen(cy->coord));
	top = pleq(v_gen(cy->vec), add_vector(v_gen(cy->coord), mult_k(v_gen(cy->vec), cy->h)));
	if (subs_in_plane(bot, v_gen(scene->L.coord)) <= EPSILON && subs_in_plane(top, v_gen(scene->L.coord)) <= EPSILON)
	{
		if (dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), v_gen(scene->L.coord)) <= cy->d / 2)
			return (1);
	}
	return (0);
}

int	islight_insphere(t_scene *scene, t_sphere *sp)
{
	if (dot_dot_distance(v_gen(scene->L.coord), v_gen(sp->coord)) <= sp->d  / 2)
		return (1);
	return (0);
}

int	islight_inplane(t_scene *scene, t_plane *pl)
{
	t_util_plane	plane;

	
	plane = pleq(v_gen(pl->vec), v_gen(pl->coord));
	//if (pl->vec[0] == 1 && pl->vec[1] == 0 && pl->vec[2] == 0)
	
	if (subs_in_plane(plane, v_gen(scene->L.coord)) * subs_in_plane(plane, v_gen(scene->C.coord)) < 0)
		return (1);
	if (fabs(subs_in_plane(plane, v_gen(scene->L.coord))) <= EPSILON)
		return (1);
	return (0);
}

int	islight_inside(t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_sphere	*sp;
	t_plane		*pl;

	if (scene->sp)
	{
		lst = *(t_list **)scene->sp;
		while (lst)
		{
			sp = (t_sphere *)lst->content;
			if (islight_insphere(scene, sp) == 1)
				return (1);
			lst = lst->next;
		}
	}
	if (scene->cy)
	{
		lst = *(t_list **)scene->cy;
		while (lst)
		{
			cy = (t_cylinder *)lst->content;
			if (islight_incylinder(scene, cy) == 1)
				return (1);
			lst = lst->next;
		}
	}
	if (scene->pl)
	{
		lst = *(t_list **)scene->pl;
		while (lst)
		{
			pl = (t_plane *)lst->content;
			if (islight_inplane(scene, pl) == 1)
				return (1);
			lst = lst->next;
		}
	}
	return (0);
}
