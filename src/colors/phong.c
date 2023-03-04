/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/04 19:08:58 by dexposit         ###   ########.fr       */
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

	px_clr = ft_calloc(sizeof(float), 3);
	if (!px_clr)
		return (NULL);
	if (!inters || !scene)
		return (free(px_clr), NULL);
	//componente ambiental
	ambclr = ambientcolor(&scene->A, 1.0);
	if (!inters->point)
		return (ambclr);
	//componente difusa
	normal = NULL;
	//normal cuando esfera
	//printf("coord inters: %f %f %f\n", inters->point[0], inters->point[1], inters->point[2]);
	if (inters->type == SPHERE)
	{
		normal = sp_normal((t_sphere *) inters->obj, inters->point);	
		px_clr = ((t_sphere *) inters->obj)->rgb;
	}
	//normal cuadno cilindro
	//normal cuadno plano
	difclr = difuse_color(&scene->L, inters->point, normal, 1.0, px_clr); 
	px_clr = rgb_combine_clrs(ambclr, 255, difclr, 255);
//	else if (inters->type == NOTYPE)
	printf("A VECES MEZCLA DIFUSO AMBIENTE");
	return (px_clr);
}
