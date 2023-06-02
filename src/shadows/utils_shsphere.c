/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_shsphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:04:25 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 22:04:38 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	same_in(float *v, t_vector point)
{
	t_vector	subs;

	if (!v)
		return (0);
	subs = subs_vector(v_gen(v), point);
	if (fabs(subs.x) <= EPSILON && fabs(subs.y) <= EPSILON
		&& fabs(subs.z) <= EPSILON)
		return (1);
	return (0);
}

float	*sect_plane_sh(float *vector, float *light, t_plane *pl)
{
	t_vector	inter;

	inter.null = 0;
	inter = plane_straight_inter(v_gen(vector), v_gen(light),
			normalize(v_gen(pl->vec)), v_gen(pl->coord));
	if (inter.null == 13)
		return (NULL);
	return (gen_v(inter));
}

float	distance_shadow(float *in, t_vector light)
{
	if (!in)
		return (-1);
	return (dot_dot_distance(v_gen(in), light));
}
