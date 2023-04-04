/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/04 13:12:14 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>

t_inters	*get_intersection(float *vector, t_scene *scene)
{
	t_inters	*res;
	if (!vector || !scene)
		return (NULL);
//	printf("LLega aqui\n");
	res = ft_calloc(sizeof(t_inters), 1);
	res->type = 3;
	res->obj = NULL;
	res->point = NULL;
	res->len_c = -1.0;
	res->vector = vector;
	srchsphere_inters(res, scene);
	srchplane_inters(res, scene);
	srchcylinder_inters(res, scene);
	//if (res->type == CYLINDER)
	//	print_inters(res);
	return (res);
}

int	srchsphere_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	t_sphere	*sp;
	float		*inters;
	float		len_c;

	if (!data->vector || !scene || !scene->sp)
		return (-1);
//	printf("vector: coord %f,%f,%f \n", data->vector[0], data->vector[1], data->vector[2]);
	lst = *(scene->sp);
	while (lst)
	{
		inters = NULL;
		sp = (t_sphere *) lst->content;
//		printf("sp: coord %f,%f,%f \n", sp->coord[0], sp->coord[1], sp->coord[2]);
		inters = sect_sphere(data->vector, scene->C.coord, sp->coord, sp->d / 2.0);
//		if (inters)
//		printf("inters: %f,%f,%f\n", inters[0], inters[1], inters[2]);
		len_c = distance_inters(inters, scene->C.coord);
		if ( inters && (data->len_c < 0.0 || len_c < data->len_c))
		{
			data->type = SPHERE;
			data->obj = lst->content;
			data->point = inters;
			data->len_c = len_c;
		}
		lst = lst->next;
	}
	/*
	lst = scene->pl;
	while (*lst)
	{
		lst = lst->next;
	}
	lst = scene->cy;
	while (*lst)
	{
		lst = lst->next;
	}
	*/
	return (0);
}

int	srchplane_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	t_plane		*pl;
	float		*inters;
	float		len_c;

	if (!data || !scene || !scene->pl)
		return (-1);
	lst = *(scene->pl);
	while (lst)
	{
		inters = NULL;
		pl = (t_plane *) lst->content;
		inters = sect_plane(data->vector, &(scene->C), pl);
		len_c = distance_inters(inters, scene->C.coord);
		if ( inters && (data->len_c < 0.0 || len_c < data->len_c))
		{
			data->type = PLANE;
			data->obj = lst->content;
			data->point = inters;
			data->len_c = len_c;
		}
		lst = lst->next;
	}

	return (0);
}

int	srchcylinder_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	int			in;
	t_vector	origin;
	t_vector	inter;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	if (!data || !scene || !scene->cy)
		return (-1);
	lst = *(scene->cy);
	while (lst)
	{
		cy = (t_cylinder *) lst->content;
		in = is_pixel_incylinder(data->vector, scene->C.coord, scene);
		if (in == 1)
		{
			data->type = CYLINDER;
			data->obj = lst->content;
			inter = cy_inter(data->vector, gen_v(origin), cy);
			data->point = gen_v(inter);
			data->len_c = dot_dot_distance(inter, origin);
		}
		lst = lst->next;
	}
	return (0);
}


		
	

float	distance_inters(float *vector, float *camera)
{
	float	res;
	int		i;
	if (!vector || !camera)
		return (-1.0);
	i = -1;
	res = 0;
	while (++i < 3)
		res += pow(camera[i] - vector[i], 2);
	return (sqrt(res));
}
