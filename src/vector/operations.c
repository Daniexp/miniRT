/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:17:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/24 13:36:09 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	plane_straight_inter(t_vector s, t_vector p
		, t_vector normal, t_vector pplane)
{
	float			num;
	float			den;
	t_vector		null;
	t_util_plane	plane;

	null.x = 0;
	null.y = 0;
	null.z = 0;
	if (dotprod(s, normal) == 0)
		return (null);
	plane = pleq(normal, pplane);
	num = -1 * (plane.d + plane.a * p.x + plane.b * p.y + plane.c * p.z);
	den = dotprod(normal, s);
	return (add_vector(p, mult_k(s, num / den)));
}

float	plane_dot_distance(t_vector dot, t_vector n, t_vector pplane)
{
	t_util_plane	plane;
	float			num;
	float			den;

	plane = pleq(n, pplane);
	num = plane.a * dot.x + plane.b * dot.y + plane.c * dot.z + plane.d;
	if (num < 0)
		num *= -1;
	den = sqrt(dotprod(n, n));
	return (num / den);
}

float	dot_straight_distance(t_vector s, t_vector p, t_vector dot)
{
	t_vector	vectorial;
	float		num;
	float		den;

	vectorial = crossprod(subs_vector(p, dot), s);
	num = vector_module(vectorial);
	den = vector_module(s);
	return (num / den);
}

float	dot_dot_distance(t_vector p, t_vector q)
{
	t_vector	tuk;

	tuk = subs_vector(p, q);
	return (vector_module(tuk));
}
/*
int	check_inter(t_vector inter, t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_vector	top;
	t_vector	bot;
	t_util_plane	real_top;
	t_util_plane	real_bot;
	t_vector	dir;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	bot = v_gen(cy->coord);
	dir = v_gen(cy->vec);
	top.x = bot.x + cy->h * dir.x;
	top.y = bot.y + cy->h * dir.y;
	top.z = bot.z + cy->h * dir.z;
	real_bot = pleq(v_gen(cy->vec), v_gen(cy->coord));
	real_top = pleq(invert(v_gen(cy->vec)), top);
	if (subs_in_plane(real_bot, inter) >= 0 && subs_in_plane(real_top, inter) >= 0)
		return (1);
	return  (0);
}
*/

t_vector	invert(t_vector a)
{
	t_vector	q;

	q.x = -a.x;
	q.y = -a.y;
	q.z = -a.z;
	return (q);
}
