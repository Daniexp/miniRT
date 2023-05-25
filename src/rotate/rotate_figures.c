/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:48 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/25 11:49:39 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	rotate_camera(t_camera *C, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;

	aux = subs_vector(v_gen(C->coord), v);
	aux = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	vectoflo(C->coord, aux);
	aux = matrix_vector_product(ry, v_gen(C->vec));
	aux = matrix_vector_product(rx, aux);
	aux = rotate_yaxis(aux);
	vectoflo(C->vec, aux);
}

void	rotate_light(t_light *L, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;

	aux = subs_vector(v_gen(L->coord), v);
	aux = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	aux = rotate_yaxis(aux);
	vectoflo(L->coord, aux);
}

void	rotate_cylinder(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;
	t_list		*lst;
	t_cylinder	*cy;

	lst = *(t_list **)scene->cy;
	if (!scene->cy)
		return ;
	while (lst)
	{
		cy = (t_cylinder *) lst->content;
		aux = subs_vector(v_gen(cy->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(cy->coord, aux);
		aux = matrix_vector_product(ry, v_gen(cy->vec));
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(cy->vec, aux);
		lst = lst->next;
	}
}

void	rotate_sphere(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_list		*lst;
	t_sphere	*sp;
	t_vector	aux;

	if (!scene->sp)
		return ;
	lst = *(t_list **)scene->sp;
	while (lst)
	{
		sp = (t_sphere *)lst->content;
		aux = subs_vector(v_gen(sp->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(sp->coord, aux);
		lst = lst->next;
	}
}

void	rotate_plane(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;
	t_list		*lst;
	t_plane		*pl;

	if (!scene->pl)
		return ;
	lst = *(t_list **)scene->pl;
	while (lst)
	{
		pl = (t_plane *)lst->content;
		aux = subs_vector(v_gen(pl->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(pl->coord, aux);
		aux = matrix_vector_product(ry, v_gen(pl->vec));
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(pl->vec, aux);
		lst = lst->next;
	}
}
