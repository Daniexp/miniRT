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

unsigned int	*phong_pnt_clr(t_inters *inters, t_scene *scene)
{
	unsigned int	*px_clr;
	float		*ambclr;
	float		*difclr;
	t_phong		*phong;
	int		i;

	if (!inters || !scene)
		return (NULL);
	phong = get_phong_params(inters, scene);
	if (!phong)
		return (NULL);
	px_clr = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
	if (!px_clr)
		return (NULL);
	ambclr = ambientcolor(&scene->A, phong->ka);
	//old difuse_color
	difclr = difuse_color(&scene->L, phong->point, phong->N, phong->kd, phong->rgb);
	//el nuevo difuse_color mira si tiene luz directa o no 
	i = -1;
	while (++i < 3)
		px_clr[i] = round((ambclr[i] + difclr[i]) * 255);
	printf("px_clr: %d %d %d\n", px_clr[0], px_clr[1], px_clr[2]);
	free(ambclr);
	free(difclr);
	return (px_clr);
}


int	phong_sphere(t_phong *df_data, t_inters *inters)
{
	if (!df_data || !inters)
		return (-1);
	if (inters->type == SPHERE)
	{
		df_data->kd = KDSPHERE;
		df_data->ka = KASPHERE;
		df_data->N = sp_normal((t_sphere *) inters->obj, inters->point);
		df_data->rgb = ((t_sphere *) inters->obj)->rgb;
	}
	return (inters->type == SPHERE);
}

int	phong_notype(t_phong *df_data, t_inters *inters)
{
	if (!df_data || !inters)
		return (-1);
	if (inters->type == NOTYPE)
	{
		df_data->kd = KDNOTYPE;
		df_data->ka = KANOTYPE;
		df_data->N = NULL;
		df_data->rgb = NULL;
	}
	return (inters->type == NOTYPE);
}

int	phong_plane(t_phong *df_data, t_inters *inters)
{
	if (!df_data || !inters)
		return (-1);
	if (inters->type == PLANE)
	{
		df_data->kd = KDPLANE;
		df_data->ka = KAPLANE;
		df_data->N = ((t_plane *) inters->obj)->vec;
		df_data->rgb = ((t_plane *) inters->obj)->rgb;
	}
	return (inters->type == PLANE);
}

int	phong_cylinder(t_phong *df_data, t_inters *inters, t_scene *scene)
{
	if (!df_data || !inters || !scene)
		return (-1);
	if (inters->type == CYLINDER)
	{
		df_data->kd = KDCYLINDER;
		df_data->ka = KACYLINDER;
		df_data->N = gen_v(normal_cylinder(v_gen(inters->point), v_gen(inters->vector), scene, inters));
		df_data->rgb = ((t_cylinder *) inters->obj)->rgb;
	}
	return (inters->type == CYLINDER);
}
