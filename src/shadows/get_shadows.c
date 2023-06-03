/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:55:19 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 18:51:39 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	freeshadows(t_shadows *s)
{
	if (!s)
		return ;
	if (s->point)
		free(s->point);
	free(s);
}

void	shadow(t_scene *scene, t_inters *inters)
{
	float		*shadow_point;
	t_vector	shadow_p;

	if (!inters->point)
		return ;
	shadow_p = add_vector(v_gen(inters->point),
			mult_k(normalize(subs_vector(v_gen(scene->l.coord),
						v_gen(inters->point))), 0.05));
	shadow_point = gen_v(subs_vector(shadow_p, v_gen(scene->l.coord)));
	get_shadows(shadow_point, inters, scene);
	free(shadow_point);
}

void	get_shadows(float *v, t_inters *inter, t_scene *scene)
{
	t_shadows	*s;
	int			i;

	s = (t_shadows *) ft_calloc(sizeof(t_shadows), 1);
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
		shsphere(s, v, scene, inter);
	if (scene->cy)
		shcylinder(s, normalize(v_gen(v)), scene, inter);
	if (scene->pl)
		shplane(s, v, scene, inter);
	freeshadows(s);
}
