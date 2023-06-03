/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscamera_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:43:13 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	iscamera_incylinder(t_scene *scene, t_cylinder *cy)
{
	t_util_plane	bot;
	t_util_plane	top;

	bot = pleq(invert(v_gen(cy->vec)), v_gen(cy->coord));
	top = pleq(v_gen(cy->vec), add_vector(v_gen(cy->coord),
				mult_k(v_gen(cy->vec), cy->h)));
	if (subs_in_plane(bot, v_gen(scene->c.coord)) <= EPSILON
		&& subs_in_plane(top, v_gen(scene->c.coord)) <= EPSILON)
	{
		if (dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord),
				v_gen(scene->c.coord)) <= cy->d / 2)
			return (1);
	}
	return (0);
}

int	iscamera_insphere(t_scene *scene, t_sphere *sp)
{
	return (dot_dot_distance(v_gen(scene->c.coord), v_gen(sp->coord))
		<= sp->d / 2);
}

int	iscamera_inplane(t_scene *scene, t_plane *pl)
{
	t_util_plane	plane;

	plane = pleq(v_gen(pl->vec), v_gen(pl->coord));
	if (fabs(subs_in_plane(plane, v_gen(scene->c.coord))) <= EPSILON)
		return (1);
	return (0);
}

static int	check_camera_in_sphere(t_scene *scene)
{
	int			res;
	t_list		*lst;
	t_sphere	*sp;

	res = 0;
	lst = *(t_list **)scene->sp;
	sp = (t_sphere *)lst->content;
	res = (iscamera_insphere(scene, sp));
	return (res);
}

int	iscamera_inside(t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_plane		*pl;
	int			res;

	res = 0;
	if (!res && scene->sp)
		res = check_camera_in_sphere(scene);
	if (!res && scene->cy)
	{
		lst = *(t_list **)scene->cy;
		cy = (t_cylinder *)lst->content;
		res = (iscamera_incylinder(scene, cy));
	}
	if (!res && scene->pl)
	{
		lst = *(t_list **)scene->pl;
		pl = (t_plane *)lst->content;
		res = (iscamera_inplane(scene, pl));
	}
	return (res);
}
