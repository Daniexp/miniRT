/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islight_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/02 20:56:41 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	islight_incylinder(t_scene *scene, t_cylinder *cy)
{
	t_util_plane	bot;
	t_util_plane	top;

	bot = pleq(invert(v_gen(cy->vec)), v_gen(cy->coord));
	top = pleq(v_gen(cy->vec), add_vector(v_gen(cy->coord),
				mult_k(v_gen(cy->vec), cy->h)));
	if (subs_in_plane(bot, v_gen(scene->L.coord)) <= EPSILON
		&& subs_in_plane(top, v_gen(scene->L.coord)) <= EPSILON)
	{
		if (dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord),
				v_gen(scene->L.coord)) <= cy->d / 2)
			return (1);
	}
	return (0);
}

int	islight_insphere(t_scene *scene, t_sphere *sp)
{
	return (dot_dot_distance(v_gen(scene->L.coord),
			v_gen(sp->coord)) <= sp->d / 2);
}

int	islight_inplane(t_scene *scene, t_plane *pl)
{
	t_util_plane	plane;

	plane = pleq(v_gen(pl->vec), v_gen(pl->coord));
	if (subs_in_plane(plane, v_gen(scene->L.coord))
		* subs_in_plane(plane, v_gen(scene->C.coord)) < 0)
		return (1);
	if (fabs(subs_in_plane(plane, v_gen(scene->L.coord))) <= EPSILON)
		return (1);
	return (0);
}

static int	check_light_sphere(t_scene *scene)
{
	int			res;
	t_list		*lst;
	t_sphere	*sp;

	res = 0;
	lst = *(t_list **)scene->sp;
	while (lst)
	{
		sp = (t_sphere *)lst->content;
		res = islight_insphere(scene, sp);
		lst = lst->next;
	}
	return (res);
}

int	islight_inside(t_scene *scene)
{
	t_list		*lst;
	t_plane		*pl;
	int			res;

	res = 0;
	if (!res && scene->sp)
		res = check_light_sphere(scene);
	if (!res && scene->cy)
		res = check_light_cylinder(scene);
	if (!res && scene->pl)
	{
		lst = *(t_list **)scene->pl;
		while (lst)
		{
			pl = (t_plane *)lst->content;
			res = (islight_inplane(scene, pl));
			lst = lst->next;
		}
	}
	return (res);
}
