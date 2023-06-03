/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printscene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:38:51 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 18:47:05 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	print_plane(t_scene *scene)
{
	t_list	*lst;
	t_plane	*pl;

	if (scene->pl)
	{
		lst = *(t_list **) scene->pl;
		while (lst)
		{
			pl = (t_plane *) lst->content;
			printf("pl: %f,%f,%f %f,%f,%f, %d,%d,%d\n",
				pl->coord[0], pl->coord[1], pl->coord[2],
				pl->vec[0], pl->vec[1], pl->vec[2],
				pl->rgb[0], pl->rgb[1],
				pl->rgb[2]);
			lst = lst->next;
		}
		printf("A %f %d,%d,%d\n", scene->a.rate, scene->a.rgb[0],
			scene->a.rgb[1], scene->a.rgb[2]);
		printf("L %f,%f,%f %f\n", scene->l.rate, scene->l.coord[0],
			scene->l.coord[1], scene->l.coord[2]);
		printf("C %f,%f,%f %f,%f,%f, %d\n", scene->c.vec[0],
			scene->c.vec[1], scene->c.vec[2], scene->c.coord[0],
			scene->c.coord[1], scene->c.coord[2],
			scene->c.fov);
	}
}

void	print_sphere(t_scene *scene)
{
	t_list		*lst;
	t_sphere	*sp;

	if (scene->sp)
	{
		lst = *(t_list **) scene->sp;
		while (lst)
		{
			sp = (t_sphere *) lst->content;
			printf("sp	%f,%f,%f %f %d,%d,%d\n", sp->coord[0],
				sp->coord[1], sp->coord[2], sp->d,
				sp->rgb[0], sp->rgb[1], sp->rgb[2]);
			lst = lst->next;
		}
	}
}

void	print_cylinder(t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;

	if (scene->cy)
	{
		lst = *(t_list **) scene->cy;
		while (lst)
		{
			cy = (t_cylinder *) lst->content;
			printf("cy: (%f, %f, %f); (%f ,%f, %f)\n", cy->coord[0],
				cy->coord[1], cy->coord[2], cy->vec[0],
				cy->vec[1], cy->vec[2]);
			printf(" radius: %f, height: %f\n", cy->d, cy->h);
			lst = lst->next;
		}
	}
}
