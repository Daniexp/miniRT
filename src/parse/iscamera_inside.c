/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscamera_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/26 12:47:32 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	iscamera_incylinder(t_scene *scene, t_cylinder *cy)
{
	t_util_plane	bot;
	t_util_plane	top;

	bot = pleq(invert(v_gen(cy->vec)), v_gen(cy->coord));
	top = pleq(v_gen(cy->vec), add_vector(v_gen(cy->coord), mult_k(v_gen(cy->vec), cy->h)));
	if (subs_in_plane(bot, v_gen(scene->C.coord)) <= EPSILON && subs_in_plane(top, v_gen(scene->C.coord)) <= EPSILON)
	{
		if (dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), v_gen(scene->C.coord)) <= cy->d / 2)
			return (1);
	}
	return (0);
}

int	iscamera_insphere(t_scene *scene, t_sphere *sp)
{
	if (dot_dot_distance(v_gen(scene->C.coord), v_gen(sp->coord)) <= sp->d  / 2)
		return (1);
	return (0);
}

int	iscamera_inplane(t_scene *scene, t_plane *pl)
{
	t_util_plane	plane;

	plane = pleq(v_gen(pl->vec), v_gen(pl->coord));
	if (subs_in_plane(plane, v_gen(scene->C.coord)) <= EPSILON)
		return (1);
	return (0);
}

int	iscamera_inside(t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_sphere	*sp;
	t_plane		*pl;

	if (scene->sp)
	{
		lst = *(t_list **)scene->sp;
		sp = (t_sphere *)lst->content;
		if (iscamera_insphere(scene, sp) == 1)
			return (1);
	}
	if (scene->cy)
	{
		lst = *(t_list **)scene->cy;
		cy = (t_cylinder *)lst->content;
		if (iscamera_incylinder(scene, cy) == 1)
			return (1);
	}
	if (scene->pl)
	{
		lst = *(t_list **)scene->pl;
		pl = (t_plane *)lst->content;
		if (iscamera_inplane(scene, pl) == 1)
			return (1);
	}
	return (0);
}
