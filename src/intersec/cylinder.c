/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:17:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/24 11:06:54 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	*cylinder_return(t_vector v,
		t_scene *scene, t_cylinder *cy, t_vector inter)
{
	float		*bases;
	t_vector	aux_inter;
	t_vector	mid;

	mid = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h / 2));
	bases = the_bases_ii(normalize(v), scene, cy);
	aux_inter = plane_straight_inter(v_gen(cy->vec),
			v_gen(cy->coord), v_gen(cy->vec), inter);
	if (bases)
	{
		if (dot_dot_distance(aux_inter, mid) > cy->h / 2)
			return (bases);
		inter = compare(v_gen(bases), inter, scene);
		return (gen_v(inter));
	}
	if (dot_dot_distance(aux_inter, mid) > cy->h / 2)
		return (NULL);
	return (gen_v(inter));
}

float	*cylinder(t_vector v, t_scene *scene, t_cylinder *cy)
{
	float		*bases;
	t_vector	dir;
	t_vector	rpinter;
	float		d2;

	bases = the_bases_i(normalize(v), scene, cy);
	if (bases)
		return (bases);
	dir = normalize(v_gen(cy->vec));
	rpinter = plane_straight_inter(v, v_gen(scene->C.coord),
			crossprod(dir, crossprod(v, dir)), v_gen(cy->coord));
	bases = the_bases_ii(normalize(v), scene, cy);
	if (dot_straight_distance(dir, v_gen(cy->coord), rpinter) > cy->d / 2)
		return (NULL);
	d2 = sqrt(pow(cy->d / 2, 2)
			- pow(dot_straight_distance(dir, v_gen(cy->coord), rpinter), 2));
	rpinter = subs_vector(rpinter, mult_k(normalize(v), d2));
	dir = add_vector(rpinter, mult_k(normalize(v), d2));
	rpinter = compare(rpinter, dir, scene);
	return (cylinder_return(v, scene, cy, rpinter));
}

int	normal_for_bases(t_vector inter, t_scene *scene, t_cylinder *cy)
{
	t_vector		top;
	t_util_plane	bottom;
	t_util_plane	topo;

	top = add_vector(v_gen(cy->coord),
			mult_k(normalize(v_gen(cy->vec)), cy->h));
	topo = pleq(invert(v_gen(cy->vec)), top);
	bottom = pleq(v_gen(cy->vec), v_gen(cy->coord));
	if (dot_dot_distance(v_gen(cy->coord),
			v_gen(scene->C.coord)) < dot_dot_distance(top,
			v_gen(scene->C.coord)))
	{
		if (subs_in_plane(bottom, inter) <= EPSILON
			&& subs_in_plane(bottom, inter) >= -EPSILON)
			return (1);
	}
	else
	{
		if (subs_in_plane(topo, inter) <= EPSILON
			&& subs_in_plane(topo, inter) >= -EPSILON)
			return (2);
	}
	return (0);
}

t_vector	normal_cylinder(t_vector in, t_vector v,
		t_scene *scene, t_inters *inter)
{
	t_vector	mid;
	t_vector	dir;
	t_vector	top;
	t_vector	proj;
	t_vector	aux;
	float		*bases;
	float		prod_top;
	float		prod_bot;
	t_vector	aux2;

	(void)v;
	(void)top;
	top = add_vector(v_gen(inter->cy->coord), mult_k(normalize(v_gen(inter->cy->vec)), inter->cy->h));

	aux = subs_vector(v_gen(inter->cy->coord), in);
	aux2 = subs_vector(top, in);
	(void)aux;
	(void)aux2;
	prod_top = dotprod(aux2, v_gen(inter->cy->vec));
	prod_bot = dotprod(aux, v_gen(inter->cy->vec));
	(void)prod_bot;
	(void)prod_top;
	(void)bases;
	if (normal_for_bases(in, scene, inter->cy) == 1)
		return (normalize(invert(v_gen(inter->cy->vec))));
	else if (normal_for_bases(in, scene, inter->cy) == 2)
		return (normalize(v_gen(inter->cy->vec)));
	/*bases = the_bases_I(v, scene);
	if (bases)
		return (v_gen(cy->vec));
	bases = the_bases_II(v, scene);
	if (bases)
	{
		proj = compare(v_gen(bases), inter, scene);
		return (proj);
	}*/
	/*if (dot_dot_distance(v_gen(cy->coord), v_gen(scene->C.coord)) < dot_dot_distance(top, v_gen(scene->C.coord)))
	{
		//if (dot_dot_distance(v_gen(cy->coord), inter) <= cy->d / 2)
		//return (invert(v_gen(cy->vec)));
		if (prod_bot <= EPSILON && prod_bot >= -EPSILON)
			return (invert(v_gen(cy->vec)));
	}
	else
	{
		if (prod_top <= EPSILON && prod_top >= -EPSILON)
			return (v_gen(cy->vec));
	}*/
	mid = add_vector(v_gen(inter->cy->coord), mult_k(normalize(v_gen(inter->cy->vec)), inter->cy->h / 2));
	mid = subs_vector(in, mid);
	dir = normalize(v_gen(inter->cy->vec));
	proj.x = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.x;
	proj.y = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.y;
	proj.z = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.z;
	proj = subs_vector(mid, proj);
	return (normalize(proj));
}
