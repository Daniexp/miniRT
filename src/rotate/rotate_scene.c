/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:48 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/24 18:47:55 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	rotate_data(t_scene *scene, t_vector *ry, t_vector *rx, t_vector c)
{
	rotate_camera(&scene->C, ry, rx, c);
	rotate_light(&scene->L, ry, rx, c);
	rotate_cylinder(scene, ry, rx, c);
	rotate_sphere(scene, ry, rx, c);
	rotate_plane(scene, ry, rx, c);
}

void	rotate_scene(t_scene *scene)
{
	t_vector	*ry;
	t_vector	*rx;
	t_vector	c;
	t_vector	v;

	v = normalize(v_gen(scene->C.vec));
	vectoflo(scene->C.vec, v);
	if (check_camera(scene->C) == 0)
	{
		subs_camera(scene);
		return ;
	}
	c = v_gen(scene->C.coord);
	ry = obtain_y(normalize(v_gen(scene->C.vec)));
	rx = obtain_x(normalize(v_gen(scene->C.vec)));
	rotate_data(scene, ry, rx, c);
	free(ry);
	free(rx);
}
