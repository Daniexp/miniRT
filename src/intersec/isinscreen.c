/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:30:23 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/26 13:25:19 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	check_res(t_inters *res, t_scene *scene)
{
	t_util_plane	camera_plane;
	
	if (!res->point)
		return ;
	camera_plane = pleq(v_gen(scene->C.vec), v_gen(scene->C.coord));
	if (subs_in_plane(camera_plane, v_gen(res->point)) <= EPSILON)
	{
		res->type = 3;
		res->obj = NULL;
		free(res->point);
		res->point = NULL;
		res->len_c = -1.0;
		res->cy = NULL;
	}
}

int	isinscreen(float *in, t_scene *scene)
{
	t_util_plane	camera_plane;
	t_util_plane	screen_plane;
	t_vector	screen_dot;

	if (!in)
		return (0);
	screen_dot = add_vector(v_gen(scene->C.coord), mult_k(v_gen(scene->C.vec), lens_radius(fov_rad(scene->C.fov), WIDTH)));
	camera_plane = pleq(v_gen(scene->C.vec), v_gen(scene->C.coord));
	screen_plane = pleq(v_gen(scene->C.vec), screen_dot);
	//printf("------------------------------           %f\n", subs_in_plane(screen_plane, v_gen(in))); 
	//printf("(%f, %f, %f, %f) ---- (%f, %f, %f)\n", screen_plane.a, screen_plane.b, screen_plane.c, screen_plane.d, in[0], in[1], in[2]);
	if (subs_in_plane(camera_plane, v_gen(in)) <= EPSILON)
	{
		free(in);
		return (0);
	}
	if (subs_in_plane(screen_plane, v_gen(in)) >= EPSILON)
	{
		free(in);
		return (0);
	}
	return (1);
}
