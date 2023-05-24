/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:17:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/24 11:03:51 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	subs_in_plane(t_util_plane plane, t_vector p)
{
	return (plane.a * p.x + plane.b * p.y + plane.c * p.z + plane.d);
}

t_vector	compare(t_vector u, t_vector v, t_scene *scene)
{
	if (dot_dot_distance(u, v_gen(scene->C.coord))
		< dot_dot_distance(v, v_gen(scene->C.coord)))
		return (u);
	return (v);
}

float	*the_bases_i(t_vector v, t_scene *scene, t_cylinder *cy)
{
	t_vector	top;
	t_vector	top_inter;
	t_vector	bot_inter;
	float		d1;
	float		d2;

	top = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,
			v_gen(scene->C.coord), invert(v_gen(cy->vec)), top);
	bot_inter = plane_straight_inter(v,
			v_gen(scene->C.coord), v_gen(cy->vec), v_gen(cy->coord));
	d1 = dot_dot_distance(bot_inter, v_gen(cy->coord));
	d2 = dot_dot_distance(top_inter, top);
	if (d1 <= cy-> d / 2 && d2 <= cy-> d / 2)
	{
		if (dot_dot_distance(top_inter, v_gen(scene->C.coord))
			> dot_dot_distance(bot_inter, v_gen(scene->C.coord)))
		{
			return (gen_v(bot_inter));
		}
		return (gen_v(top_inter));
	}
	return (NULL);
}

float	*the_bases_ii(t_vector v, t_scene *scene, t_cylinder *cy)
{
	t_vector	top;
	t_vector	top_inter;
	float		d1;
	float		d2;
	t_vector	bot_inter;

	top = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,
			v_gen(scene->C.coord), v_gen(cy->vec), top);
	bot_inter = plane_straight_inter(v,
			v_gen(scene->C.coord), v_gen(cy->vec), v_gen(cy->coord));
	d1 = dot_dot_distance(top_inter, top);
	d2 = dot_dot_distance(bot_inter, v_gen(cy->coord));
	if (d1 <= cy->d / 2)
		return (gen_v(top_inter));
	else if (d2 <= cy->d / 2)
		return (gen_v(bot_inter));
	return (NULL);
}
