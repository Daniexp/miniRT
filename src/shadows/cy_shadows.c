/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:17:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:43:22 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	*cylinder_return_sh(t_vector v,
		t_scene *scene, t_cylinder *cy, t_vector inter)
{
	float		*bases;
	t_vector	aux_inter;
	t_vector	mid;

	mid = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h / 2));
	bases = the_bases_ii_sh(normalize(v), scene, cy);
	aux_inter = plane_straight_inter(v_gen(cy->vec),
			v_gen(cy->coord), v_gen(cy->vec), inter);
	if (bases)
	{
		if (dot_dot_distance(aux_inter, mid) > cy->h / 2)
			return (bases);
		inter = compare(v_gen(bases), inter, scene);
		free(bases);
		return (gen_v(inter));
	}
	if (dot_dot_distance(aux_inter, mid) > cy->h / 2)
		return (NULL);
	return (gen_v(inter));
}

float	*the_bases_i_sh(t_vector v, t_scene *scene, t_cylinder *cy)
{
	t_vector	top;
	t_vector	top_inter;
	t_vector	bot_inter;
	float		d1;
	float		d2;

	top = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,
			v_gen(scene->l.coord), invert(v_gen(cy->vec)), top);
	bot_inter = plane_straight_inter(v,
			v_gen(scene->l.coord), v_gen(cy->vec), v_gen(cy->coord));
	d1 = dot_dot_distance(bot_inter, v_gen(cy->coord));
	d2 = dot_dot_distance(top_inter, top);
	if (d1 <= cy-> d / 2 && d2 <= cy-> d / 2)
	{
		if (dot_dot_distance(top_inter, v_gen(scene->c.coord))
			> dot_dot_distance(bot_inter, v_gen(scene->c.coord)))
		{
			return (gen_v(bot_inter));
		}
		return (gen_v(top_inter));
	}
	return (NULL);
}

float	*the_bases_ii_sh(t_vector v, t_scene *scene, t_cylinder *cy)
{
	t_vector	top;
	t_vector	top_inter;
	float		d1;
	float		d2;
	t_vector	bot_inter;

	top = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,
			v_gen(scene->l.coord), v_gen(cy->vec), top);
	bot_inter = plane_straight_inter(v,
			v_gen(scene->l.coord), v_gen(cy->vec), v_gen(cy->coord));
	d1 = dot_dot_distance(top_inter, top);
	d2 = dot_dot_distance(bot_inter, v_gen(cy->coord));
	if (d1 <= cy->d / 2)
		return (gen_v(top_inter));
	else if (d2 <= cy->d / 2)
		return (gen_v(bot_inter));
	return (NULL);
}

t_vector	compare_sh(t_vector u, t_vector v, t_scene *scene)
{
	if (dot_dot_distance(u, v_gen(scene->c.coord))
		< dot_dot_distance(v, v_gen(scene->c.coord)))
		return (u);
	return (v);
}

float	*cylinder_sh(t_vector v, t_scene *scene, t_cylinder *cy)
{
	float		*bases;
	t_vector	dir;
	t_vector	rpinter;
	float		d2;

	bases = the_bases_i_sh(normalize(v), scene, cy);
	if (bases)
		return (bases);
	dir = normalize(v_gen(cy->vec));
	rpinter = plane_straight_inter(v, v_gen(scene->l.coord),
			crossprod(dir, crossprod(v, dir)), v_gen(cy->coord));
	if (dot_straight_distance(dir, v_gen(cy->coord), rpinter) > cy->d / 2)
		return (NULL);
	d2 = sqrt(pow(cy->d / 2, 2)
			- pow(dot_straight_distance(dir, v_gen(cy->coord), rpinter), 2));
	rpinter = subs_vector(rpinter, mult_k(normalize(v), d2));
	dir = add_vector(rpinter, mult_k(normalize(v), d2));
	rpinter = compare_sh(rpinter, dir, scene);
	return (cylinder_return_sh(v, scene, cy, rpinter));
}
