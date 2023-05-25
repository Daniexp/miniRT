/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscamera_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:04 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/25 13:33:50 by ndonaire         ###   ########.fr       */
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
		return (1);




int	iscamera_inside(t_scene *scene)
{

