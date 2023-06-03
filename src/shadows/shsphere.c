/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shsphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:56:05 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 17:59:20 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	isinscreen_sh(float *in, t_scene *scene, float *dot)
{
	t_util_plane	camera_plane;
	t_util_plane	light_plane;
	t_vector		util;

	if (!in)
		return (0);
	(void)light_plane;
	util = subs_vector(v_gen(dot), v_gen(scene->l.coord));
	camera_plane = pleq(v_gen(scene->c.vec), v_gen(scene->c.coord));
	light_plane = pleq(util, v_gen(scene->l.coord));
	if (subs_in_plane(camera_plane, v_gen(in)) <= EPSILON
		|| subs_in_plane(light_plane, v_gen(in)) <= EPSILON)
		return (0);
	return (1);
}

void	shsphere(t_shadows *s, float *v, t_scene *scene, t_inters *res)
{
	float		*in;
	float		len_l;
	t_list		*lst;
	t_sphere	*sp;

	if (!scene->sp)
		return ;
	if (res->shadow == 1)
		return ;
	lst = *(scene->sp);
	while (lst)
	{
		in = NULL;
		sp = (t_sphere *)lst->content;
		in = sect_sphere(v, s->light, sp->coord, sp->d / 2);
		len_l = distance_shadow(in, v_gen(s->light));
		if (in && len_l < s->len_l && same_in(in, v_gen(s->point)) == 0)
		{
			if (isinscreen_sh(in, scene, res->point) == 1 && res->obj != sp)
				res->shadow = 1;
		}
		if (in)
			free(in);
		lst = lst->next;
	}
}

void	shcylinder(t_shadows *s, t_vector v, t_scene *scene, t_inters *res)
{
	float		*in;
	t_list		*lst;
	t_cylinder	*cy;
	float		len_l;

	if (!scene->cy)
		return ;
	lst = *(scene->cy);
	while (lst)
	{
		in = NULL;
		cy = (t_cylinder *)lst->content;
		in = cylinder_sh(normalize(v), scene, cy);
		len_l = distance_shadow(in, v_gen(scene->l.coord));
		if (in && len_l < s->len_l && same_in(in, v_gen(s->point)) == 0)
		{
			if (isinscreen_sh(in, scene, res->point) == 1 && res->obj != cy)
				res->shadow = 1;
		}
		if (in)
			free(in);
		lst = lst->next;
	}
}

void	shplane(t_shadows *s, float *v, t_scene *scene, t_inters *res)
{
	float		*in;
	t_list		*lst;
	t_plane		*pl;
	float		len_l;

	if (!scene->pl || !s || res->shadow == 1)
		return ;
	lst = *(scene->pl);
	while (lst)
	{
		in = NULL;
		pl = (t_plane *)lst->content;
		in = sect_plane_sh(v, scene->l.coord, pl);
		len_l = distance_shadow(in, v_gen(scene->l.coord));
		if (in && len_l < s->len_l && same_in(in, v_gen(res->point)) == 0)
		{
			if (isinscreen_sh(in, scene, res->point) == 1 && res->obj != pl)
					res->shadow = 1;
		}
		if (in)
			free(in);
		lst = lst->next;
	}
}
