/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:55:19 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 17:42:57 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_shadows	*get_shadows(float *v, t_inters *inter, t_scene *scene,
			t_inters *res)
{
	t_shadows	*s;
	int			i;

	s = (t_shadows *) ft_calloc(sizeof(t_shadows), 1);
	(void)inter;
	(void)res;
	s->point = fdup(inter->point);
	s->len_l = dot_dot_distance(v_gen(inter->point), v_gen(scene->l.coord));
	s->type = 3;
	s->shadow = 0;
	i = 0;
	while (i < 3)
	{
		s->light[i] = scene->l.coord[i];
		i++;
	}
	if (scene->sp)
		shsphere(s, v, scene, res);
	if (scene->cy)
		shcylinder(s, normalize(v_gen(v)), scene, res);
	if (scene->pl)
		shplane(s, v, scene, res);
	return (s);
}
