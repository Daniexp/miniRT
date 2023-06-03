/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:48 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:43:20 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	rotate_data(t_scene *scene, t_vector *ry, t_vector *rx, t_vector c)
{
	rotate_camera(&scene->c, ry, rx, c);
	rotate_light(&scene->l, ry, rx, c);
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

	v = normalize(v_gen(scene->c.vec));
	vectoflo(scene->c.vec, v);
	if (check_camera(scene->c) == 0)
	{
		subs_camera(scene);
		return ;
	}
	c = v_gen(scene->c.coord);
	ry = obtain_y(normalize(v_gen(scene->c.vec)));
	rx = obtain_x(normalize(v_gen(scene->c.vec)));
	rotate_data(scene, ry, rx, c);
	free(ry);
	free(rx);
}
