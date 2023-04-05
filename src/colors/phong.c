/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/05 11:25:41 by ndonaire         ###   ########.fr       */
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
	t_vector		mid;
	t_vector		o;
	t_vector		up_base;
	t_vector		dir;
	t_vector		base;
	t_cylinder		*cy;
	t_util_plane			bot;
	t_util_plane			top;
	t_list			*lst;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	o.x = 0;
	o.y = 0;
	o.z = 0;
	px_clr = NULL;
	if (!inters || !scene)
		return (NULL);
//	ambclr = ambientcolor(&(scene->A), 1.0);
//	if (!inters->point)
	//	return (ambclr);
	normal = NULL;
	base = v_gen(cy->coord);
	dir = v_gen(cy->vec);
	up_base.x = base.x + cy->h * dir.x;
	up_base.y = base.y + cy->h * dir.y;
	up_base.z = base.z + cy->h * dir.z;
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
		//normal = ((t_plane *) inters->obj)->vec;
		normal = (float *) ft_calloc(3, sizeof(float));
		normal[0] = -(((t_plane *) inters->obj)->vec[0]);
		normal[1] = -(((t_plane *) inters->obj)->vec[1]);
		normal[2] = -(((t_plane *) inters->obj)->vec[2]);
		px_clr = ((t_plane *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 0.3);
		difclr = difuse_color(&(scene->L), inters->point, normal, 0.9, px_clr); 
	}
	else if (inters->type == CYLINDER)
	{
		mid = obtain_mid_point(inters->vector, gen_v(o), scene);
		(void)mid;
		bot = pleq(v_gen(cy->vec), v_gen(cy->coord));
		top = pleq(invert(v_gen(cy->vec)), up_base);
		if (subs_in_plane(bot, v_gen(inters->point)) <= EPSILON)
			normal = cy->vec;
		else if (subs_in_plane(top, v_gen(inters->point)) <= EPSILON)
			normal = gen_v(invert(v_gen(cy->vec)));
		else
		{
			n = normal_cylinder(inters->point, scene);
			normal = gen_v(n);
		}
		px_clr = ((t_cylinder *) inters->obj)->rgb;
		ambclr = ambientcolor(&(scene->A), 0.3);
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
