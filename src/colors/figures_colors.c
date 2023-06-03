/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:59:54 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 14:01:48 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>
#include <intersection.h>

unsigned int	*color_sphere(t_inters *inters, t_scene *scene)
{
	float			*normal;
	float			*difclr;
	unsigned int	*px_clr;
	float			*ambclr;

	normal = sp_normal((t_sphere *) inters->obj, inters->point);
	px_clr = ((t_sphere *) inters->obj)->rgb;
	ambclr = ambientcolor(&(scene->A), 1);
	if (inters->shadow == 0)
		difclr = difuse_color(&(scene->L), inters->point,
				normal, 1.0, px_clr);
	else
		difclr = zero_dif();
	px_clr = get_pxclr(ambclr, difclr);
	free(normal);
	free(ambclr);
	free(difclr);
	return (px_clr);
}

unsigned int	*color_plane(t_inters *inters, t_scene *scene)
{
	float				*normal;
	float				*difclr;
	float				*ambclr;
	unsigned int		*px_clr;

	normal = normal_plane(scene, inters);
	px_clr = ((t_plane *) inters->obj)->rgb;
	ambclr = ambientcolor(&(scene->A), 1);
	if (inters->shadow == 0)
		difclr = difuse_color(&(scene->L),
				inters->point, normal, 1, px_clr);
	else
		difclr = zero_dif();
	px_clr = get_pxclr(ambclr, difclr);
	free(normal);
	free(ambclr);
	free(difclr);
	return (px_clr);
}

unsigned int	*color_cylinder(t_inters *inters, t_scene *scene)
{
	float			*normal;
	float			*difclr;
	float			*ambclr;
	unsigned int	*px_clr;

	normal = gen_v(normal_cylinder(v_gen(inters->point),
				v_gen(inters->vector), scene, inters));
	px_clr = ((t_cylinder *) inters->obj)->rgb;
	ambclr = ambientcolor(&(scene->A), 1.0);
	if (inters->shadow == 0)
		difclr = difuse_color(&(scene->L), inters->point,
				normal, 1, px_clr);
	else
		difclr = zero_dif();
	px_clr = get_pxclr(ambclr, difclr);
	free(normal);
	free(ambclr);
	free(difclr);
	return (px_clr);
}

unsigned int	*nothing(t_scene *scene)
{
	unsigned int	*px_clr;
	float			*ambclr;
	float			*difclr;

	ambclr = ambientcolor(&(scene->A), 1.0);
	difclr = zero_dif();
	px_clr = get_pxclr(ambclr, difclr);
	free(ambclr);
	free(difclr);
	return (px_clr);
}
