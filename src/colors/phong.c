/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/05/19 11:43:31 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>
#include <intersection.h>

unsigned int	*get_pnt_clr(t_inters *inters, t_scene *scene)
{
	unsigned int	*px_clr;
	float			*ambclr;
	float			*difclr;
	float			*normal;
	t_vector		n;
	//t_list			*lst;

	px_clr = NULL;
	if (!inters || !scene)
		return (NULL);
//	ambclr = ambientcolor(&(scene->A), 1.0);
//	if (!inters->point)
	//	return (ambclr);
	normal = NULL;
	//normal cuando esfera
	if (inters->type == SPHERE)
	{
		normal = sp_normal((t_sphere *) inters->obj, inters->point);	
		px_clr = ((t_sphere *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1.0);
		difclr = difuse_color(&(scene->L), inters->point, normal, 1.0, px_clr); 
	}
	//normal cuadno plano
	else if (inters->type == PLANE)
	{
		normal = ((t_plane *) inters->obj)->vec;
		//normal = normal_plane(scene);
		normal = (float *) ft_calloc(3, sizeof(float));
		normal[0] = -(((t_plane *) inters->obj)->vec[0]);
		normal[1] = -(((t_plane *) inters->obj)->vec[1]);
		normal[2] = -(((t_plane *) inters->obj)->vec[2]);
		
		px_clr = ((t_plane *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1);
		difclr = difuse_color(&(scene->L), inters->point, normal, 0.9, px_clr); 
	}
	else if (inters->type == CYLINDER)
	{

		n = normal_cylinder(v_gen(inters->point), v_gen(inters->vector), scene, inters);
		normal = gen_v(n);
		px_clr = ((t_cylinder *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 1.0);
		difclr = difuse_color(&(scene->L), inters->point, normal, 0.9, px_clr); 
	}
	else
	{
		ambclr = ambientcolor(&(scene->A), 1.0);
		difclr = ft_calloc(3, sizeof(float *));
		int j = -1;
		while (++j)
			difclr[j] = 0.0;
	}
	//normal cuadno cilindro
//	difclr = difuse_color(&(scene->L), inters->point, normal, 1.0, px_clr); 
//	if (difclr)
//	{
		//px_clr = rgb_combine_clrs(ambclr, 255, difclr, 255);
		int i = -1;
		px_clr = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
		while (++i < 3)
			px_clr[i] = round((ambclr[i] + difclr[i]) * 255);
//	}
	free(ambclr);
	free(difclr);
///	printf("px_clr: %d %d %d\n", px_clr[0], px_clr[1], px_clr[2]);
	return (px_clr);
}
