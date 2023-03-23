/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/23 12:00:03 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>
#include <intersection.h>

unsigned int	*get_pnt_clr(t_inters *inters, t_scene *scene)
{
	unsigned int	*px_clr;
	unsigned int	*ambclr;
	unsigned int	*difclr;
	float			*normal;

	px_clr = NULL;
	if (!inters || !scene)
		return (NULL);
	ambclr = ambientcolor(&(scene->A), 1.0);
	if (!inters->point)
		return (ambclr);
	normal = NULL;
	//normal cuando esfera
	if (inters->type == SPHERE)
	{
		normal = sp_normal((t_sphere *) inters->obj, inters->point);	
		px_clr = ((t_sphere *) inters->obj)->rgb;
	}
	//normal cuadno plano
	else if (inters->type == PLANE)
	{
		//normal = ((t_plane *) inters->obj)->vec;
		normal = (float *) ft_calloc(3, sizeof(float));
		normal[0] = -(((t_plane *) inters->obj)->vec[0]);
		normal[1] = -(((t_plane *) inters->obj)->vec[1]);
		normal[2] = -(((t_plane *) inters->obj)->vec[2]);
		px_clr = ((t_plane *) inters->obj)->rgb;
	}
	//normal cuadno cilindro
	difclr = difuse_color(&(scene->L), inters->point, normal, 1.0, px_clr); 
	px_clr = rgb_combine_clrs(ambclr, 255, difclr, 255);
	free(ambclr);
	free(difclr);
///	printf("px_clr: %d %d %d\n", px_clr[0], px_clr[1], px_clr[2]);
	return (px_clr);
}
