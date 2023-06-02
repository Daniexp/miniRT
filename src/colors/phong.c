/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:04:39 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>
#include <intersection.h>

void	free_res_shadow(t_inters *inter);

float	*zero_dif(void)
{
	float	*dif;

	dif = (float *) ft_calloc(sizeof(float), 3);
	dif[0] = 0;
	dif[1] = 0;
	dif[2] = 0;
	return (dif);
}

unsigned int	*get_pnt_clr(t_inters *inters, t_scene *scene)
{
	unsigned int			*px_clr;
	t_vector				n;
	int						i;
	float					*ambclr;
	float					*difclr;
	float					*normal;

	px_clr = NULL;
	if (!inters || !scene)
		return (NULL);
	normal = NULL;
	if (inters->type == SPHERE)
	{
		normal = sp_normal((t_sphere *) inters->obj, inters->point);
		px_clr = ((t_sphere *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1);
		if (inters->shadow == 0)
			difclr = difuse_color(&(scene->L), inters->point,
					normal, 1.0, px_clr);
		else
			difclr = zero_dif();
	}
	else if (inters->type == PLANE)
	{
		normal = normal_plane(scene, inters);
		px_clr = ((t_plane *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1);
		if (inters->shadow == 0)
			difclr = difuse_color(&(scene->L),
					inters->point, normal, 1, px_clr);
		else
			difclr = zero_dif();
	}
	else if (inters->type == CYLINDER)
	{
		n = normal_cylinder(v_gen(inters->point),
				v_gen(inters->vector), scene, inters);
		normal = gen_v(n);
		px_clr = ((t_cylinder *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1.0);
		if (inters->shadow == 0)
			difclr = difuse_color(&(scene->L), inters->point,
					normal, 1, px_clr);
		else
			difclr = zero_dif();
	}
	else
	{
		ambclr = ambientcolor(&(scene->A), 1.0);
		difclr = (float *) ft_calloc(3, sizeof(float *));
		i = -1;
		while (++i)
			difclr[i] = 0.0;
	}
	i = -1;
	px_clr = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
	while (++i < 3)
			px_clr[i] = round((ambclr[i] + difclr[i]));
	free(ambclr);
	free(difclr);
	free(normal);
	return (px_clr);
}
