/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:51:51 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:43:22 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	subs_cylinder(t_scene *scene, t_vector v)
{
	t_list		*lst;
	t_vector	aux;
	t_cylinder	*cy;

	if (!scene->cy)
		return ;
	lst = *(t_list **)scene->cy;
	cy = (t_cylinder *)lst->content;
	aux = subs_vector(v_gen(cy->coord), v);
	vectoflo(cy->coord, aux);
}

void	subs_sphere(t_scene *scene, t_vector v)
{
	t_list		*lst;
	t_vector	aux;
	t_sphere	*sp;

	if (!scene->sp)
		return ;
	lst = *(t_list **)scene->sp;
	sp = (t_sphere *)lst->content;
	aux = subs_vector(v_gen(sp->coord), v);
	vectoflo(sp->coord, aux);
}

void	subs_plane(t_scene *scene, t_vector v)
{
	t_list		*lst;
	t_vector	aux;
	t_plane		*pl;

	if (!scene->pl)
		return ;
	lst = *(t_list **)scene->pl;
	pl = (t_plane *)lst->content;
	aux = subs_vector(v_gen(pl->coord), v);
	vectoflo(pl->coord, aux);
}

void	subs_light(t_light *L, t_vector v)
{
	t_vector	aux;

	aux = subs_vector(v_gen(L->coord), v);
	vectoflo(L->coord, aux);
}

void	subs_camera(t_scene *scene)
{
	t_vector	c;
	t_vector	aux;

	c = v_gen(scene->c.coord);
	subs_cylinder(scene, c);
	subs_plane(scene, c);
	subs_sphere(scene, c);
	subs_light(&scene->l, c);
	aux = subs_vector(v_gen(scene->c.coord), c);
	vectoflo(scene->c.coord, aux);
}
