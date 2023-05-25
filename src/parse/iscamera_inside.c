/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscamera_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/25 14:13:56 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	iscamera_incylinder(t_scene *scene, t_cylinder *cy)
{
	t_util_plane	bot;
	t_util_plane	top;

	bot = pleq(v_gen(cy->vec), v_gen(cy->coord));
	top = pleq(invert(v_gen(cy->vec)), add_vector(v_gen(cy->coord), mult_k(v_gen(cy->vec), cy->h)));
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

int	iscamera_inplane(t_scene *scene, t_sphere *sp)
{
	




int	iscamera_inside(t_scene *scene)
{

