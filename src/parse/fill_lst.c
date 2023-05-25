/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:23:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/25 11:31:32 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	threeforfree(char **a, char **b, char **c)
{
	if (a)
		free_arg(a);
	if (b)
		free_arg(b);
	if (c)
		free_arg(c);
}

int	add_cy(t_scene *scene, t_cylinder *cy)
{
	if (!scene->cy)
	{
		scene->cy = ft_calloc(sizeof(t_list *), 1);
		*(scene->cy) = ft_lstnew((void *) cy);
	}
	else
		ft_lstadd_front(scene->cy, ft_lstnew((void *)cy));
	return (0);
}

int	add_pl(t_scene *scene, t_plane *pl)
{
	if (!scene->pl)
	{
		scene->pl = ft_calloc(sizeof(t_list *), 1);
		*(scene->pl) = ft_lstnew((void *) pl);
	}
	else
		ft_lstadd_front(scene->pl, ft_lstnew((void *)pl));
	return (0);
}

int	cylinder_check(char **line_content, t_scene *scene, int n_line)
{
	char		**coor;
	char		**rgb;
	t_cylinder	*cy;
	char		**vec;

	if (double_pointier_len(line_content) != 6)
		return (error_params(n_line, 0, NULL, NULL));
	coor = ft_split(line_content[1], ',');
	if (check_vec3d(coor, 0) == 1)
		return (error_params(n_line, 0, coor, NULL));
	vec = ft_split(line_content[2], ',');
	if (check_vec3d(vec, 'v') == 1)
		return (error_params(n_line, 0, coor, vec));
	if (check_all_nb(line_content[3]) == 1)
		return (error_params(n_line, 0, coor, vec));
	if (check_all_nb(line_content[4]) == 1)
		return (error_params(n_line, 0, coor, vec));
	rgb = ft_split(line_content[5], ',');
	if (check_vec3d(rgb, 0) == 1)
	{
		threeforfree(coor, vec, rgb);
		return (error_params(n_line, 0, NULL, NULL));
	}
	cy = (t_cylinder *) malloc(sizeof(t_cylinder));
	fill_cylinder(coor, vec, rgb, cy);
	fill_cylinder_ii(line_content, cy);
	return (add_cy(scene, cy));
}

int	plane_check(char **line_content, t_scene *scene, int n_line)
{
	char	**coor;
	char	**vec;
	t_plane	*pl;
	char	**rgb;

	if (double_pointier_len(line_content) != 4)
		return (error_params(n_line, 0, NULL, NULL));
	coor = ft_split(line_content[1], ',');
	if (check_vec3d(coor, 0) == 1)
		return (error_params(n_line, 0, coor, NULL));
	vec = ft_split(line_content[2], ',');
	if (check_vec3d(vec, 'v') == 1)
		return (error_params(n_line, 0, coor, vec));
	rgb = ft_split(line_content[3], ',');
	if (check_vec3d(rgb, 0) == 1)
	{
		free_arg(rgb);
		return (error_params(n_line, 0, coor, vec));
	}
	pl = (t_plane *) malloc(sizeof(t_plane));
	fill_plane(coor, vec, rgb, pl);
	add_pl(scene, pl);
	return (0);
}
