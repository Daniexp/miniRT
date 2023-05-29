/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/05/25 10:52:13 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>
/* ref = 0 es para eliminar los shthis*/ 

void	sp_clearsh(t_scene *scene, t_inters *res, int ref)
{
	t_list		*lst;
	t_sphere	*sp;
	int		i;
	int		y;

	(void)res;
	i = 0;
	y = 0;
	if (ref == 0)
	{
		if (scene->sp)
		{
			lst = *(scene->sp);
			while (lst)
			{
				sp = (t_sphere *)lst->content;
				if (sp->shthis == 1)
					sp->shthis = 0;
				lst = lst->next;
			}
		}
		return ;
	}
	if (scene->sp)
	{
		lst = *(scene->sp);
		while (lst)
		{
			sp = (t_sphere *)lst->content;
			if (sp->shthis == 1)
			{
				sp->shthis = 0;
				i = i + y;
			}
			else
				y++;
			lst = lst->next;
		}
		lst = *(scene->sp);
		y = 0;
		while (y <= i)
		{
			if (y == i)
				sp->shthis = 1;
			y++;
			lst = lst->next;
		}
	}
}


void	cy_clearsh(t_scene *scene, t_inters *res, int ref)
{
	t_list		*lst;
	t_cylinder	*cy;
	int		i;
	int		y;

	(void)res;
	i = 0;
	y = 0;
	if (ref == 0)
	{
		if (scene->cy)
		{
			lst = *(scene->cy);
			while (lst)
			{
				cy = (t_cylinder *)lst->content;
				if (cy->shthis == 1)
					cy->shthis = 0;
				lst = lst->next;
			}
		}
		return ;
	}
	if (scene->cy)
	{
		lst = *(scene->cy);
		while (lst)
		{
			cy = (t_cylinder *)lst->content;
			if (cy->shthis == 1)
			{
				cy->shthis = 0;
				i = i + y;
			}
			else
				y++;
			lst = lst->next;
		}
		lst = *(scene->cy);
		y = 0;
		while (y <= i)
		{
			if (y == i)
				cy->shthis = 1;
			y++;
			lst = lst->next;
		}
	}
}


void	pl_clearsh(t_scene *scene, t_inters *res, int ref)
{
	t_list		*lst;
	t_plane		*pl;
	int		i;
	int		y;

	(void)res;
	i = 0;
	y = 0;
	if (ref == 0)
	{
		if (scene->pl)
		{
			lst = *(scene->pl);
			while (lst)
			{
				pl = (t_plane *)lst->content;
				if (pl->shthis == 1)
					pl->shthis = 0;
				lst = lst->next;
			}
		}
		return ;
	}
	if (scene->pl)
	{
		lst = *(scene->pl);
		while (lst)
		{
			pl = (t_plane *)lst->content;
			if (pl->shthis == 1)
			{
				pl->shthis = 0;
				i = i + y;
			}
			else
				y++;
			lst = lst->next;
		}
		lst = *(scene->pl);
		y = 0;
		while (y <= i)
		{
			if (y == i)
				pl->shthis = 1;
			y++;
			lst = lst->next;
		}
	}
}


void	shthisp(t_list *lst, int i, t_scene *scene)
{
	int	y;
	t_sphere	*sp;

	(void)scene;
	y = 0;
	if (i < 0)
	{
		while (lst)
		{
			sp = (t_sphere *)lst->content;	
			if (sp->shthis == 1)
				sp->shthis = 0;
			y++;
			lst = lst->next;
		}
		return ;
	}
	while (y < i && lst)
	{
		sp = (t_sphere *)lst->content;	
		if (sp->shthis == 1)
			sp->shthis = 0;
		y++;
		lst = lst->next;
	}
}

void	shthicy(t_list *lst, int i, t_scene *scene)
{
	int	y;
	t_cylinder	*cy;

	(void)scene;
	y = 0;
	if (i < 0)
	{
		while (lst)
		{
			cy = (t_cylinder *)lst->content;	
			if (cy->shthis == 1)
				cy->shthis = 0;
			y++;
			lst = lst->next;
		}
		return ;
	}
	while (y < i && lst)
	{
		cy = (t_cylinder *)lst->content;	
		if (cy->shthis == 1)
			cy->shthis = 0;
		y++;
		lst = lst->next;
	}
}

void	shthipl(t_list *lst, int i, t_scene *scene)
{
	int	y;
	t_plane		*pl;

	(void)scene;
	y = 0;
	if (i < 0)
	{
		while (lst)
		{
			pl = (t_plane *)lst->content;	
			if (pl->shthis == 1)
				pl->shthis = 0;
			y++;
			lst = lst->next;
		}
		return ;
	}
	while (y < i && lst)
	{
		pl = (t_plane *)lst->content;	
		if (pl->shthis == 1)
			pl->shthis = 0;
		y++;
		lst = lst->next;
	}
}

void	remove_shthis(t_scene *scene, int i, int type)
{
	t_list		*lst;

	if (type == SPHERE)
	{
		lst = *(scene->sp);
		shthisp(lst, i, scene);

	}
	if (type == PLANE)
	{
		lst = *(scene->pl);
		shthisp(lst, -1, scene);
		shthipl(lst, i, scene);
	}
	if (type == CYLINDER)
	{

		lst = *(scene->cy);
		shthisp(lst, -1, scene);
		shthipl(lst, -1, scene);
		shthicy(lst, i, scene);
	}
}

t_inters	*get_intersection(float *vector, t_scene *scene)
{
	t_inters	*res;
	if (!vector || !scene)
		return (NULL);
//	printf("LLega aqui\n");
	res = ft_calloc(sizeof(t_inters), 1);
	if (!res)
		printf("AIUDAAAAAAAAAAAA\n");
	res->type = 3;
	res->obj = NULL;
	res->point = NULL;
	res->len_c = -1.0;
	res->vector = vector;
	res->cy = NULL;
	res->shadow = 0;
	srchsphere_inters(res, scene);
	srchcylinder_inters(res, scene);
	srchplane_inters(res, scene);
	/*if (res->type == SPHERE)
	{
		cy_clearsh(scene, res, 0);
		pl_clearsh(scene, res, 0);
		sp_clearsh(scene, res, 23);
	}
	else if (res->type == CYLINDER)
	{
		cy_clearsh(scene, res, 420);
		pl_clearsh(scene, res, 0);
		sp_clearsh(scene, res, 0);
	}
	else if (res->type == PLANE)
	{
		cy_clearsh(scene, res, 0);
		pl_clearsh(scene, res, 69);
		sp_clearsh(scene, res, 0);
	}*/
	return (res);
}



int	srchsphere_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	t_sphere	*sp;
	float		*inters;
	float		len_c;
	int		i;

	i = 0;
	(void)i;
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
			if (isinscreen(inters, scene) == 1)
			{
				data->type = SPHERE;
				data->obj = lst->content;
				data->point = inters;
				data->len_c = len_c;
				//sp->shthis = 1;
				//remove_shthis(scene, i, data->type);
			}
		}
		i++;
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
	//printf("%f, %f, %f\n", scene->C.vec[0], scene->C.vec[1], scene->C.vec[2]); 
	while (lst)
	{
		inters = NULL;
		pl = (t_plane *) lst->content;
		inters = sect_plane(data->vector, &(scene->C), pl);
		len_c = distance_inters(inters, scene->C.coord);
		//if (inters)
		//	printf("%f, %f, %f\n", inters[0], inters[1], inters[2]);
			
		if ( inters && (data->len_c < 0.0 || len_c < data->len_c))
		{
			if (isinscreen(inters, scene) == 1)
			{
				data->type = PLANE;
				data->obj = lst->content;
				data->point = inters;
				data->len_c = len_c;
				//pl->shthis = 1;
				//remove_shthis(scene, i, data->type);
			}
		}
		lst = lst->next;
	}

	return (0);
}

int	srchcylinder_inters(t_inters *data, t_scene *scene)
{
	t_list		*lst;
	float		*in;
	t_cylinder	*cy;
	float		len_c;

	if (!data || !scene || !scene->cy)
		return (-1);
	lst = *(scene->cy);
	while (lst)
	{
		in = NULL;
		cy = (t_cylinder *)lst->content;
		in = cylinder(v_gen(data->vector),scene, cy);
		len_c = distance_inters(in, scene->C.coord);
		if ( in && (data->len_c < 0.0 || len_c < data->len_c) )
		{
			if (isinscreen(in, scene) == 1)
			{
				data->type = CYLINDER;
				data->obj = lst->content;
				data->point = in;
				data->len_c = len_c;
				data->cy = (t_cylinder *)lst->content;
				//cy->shthis = 1;
				//remove_shthis(scene, i, data->type);
			}
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
