/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:59:54 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/04 13:04:07 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_rgba(char **vec)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (vec[i])
	{
		while (vec[i][y])
		{
			if (vec[i][y] == '-' || vec[i][y] == '.')
				return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

int	check_vec3d(char **vec, int c)
{
	int		i;
	float	v[3];

	i = 0;
	if (double_pointier_len(vec) != 3)
		return (1);
	while (i < 3)
		if (check_all_nb(vec[i++]) == 1)
			return (1);
	if (c == 'v')
	{
		i = 0;
		while (i < 3)
		{
			v[i] = atofelio(vec[i]);
			i++;
		}
		if (vector_module(v_gen(v)) == 0)
			return (1);
	}
	else if (c == 'r')
		return (check_rgba(vec));
	return (0);
}

int	check_norm(t_vector v)
{
	if (fabs(vector_module(v) - 1) >= THETA)
		return (1);
	return (0);
}

int	check_all_normalized(t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_plane		*pl;

	if (scene->cy)
	{
		lst = *(t_list **)scene->cy;
		cy = (t_cylinder *)lst->content;
		if (check_norm(v_gen(cy->vec)) == 1)
			return (error_msg("error: A cylinder vector is not normalized\n"));
	}
	if (scene->pl)
	{
		lst = *(t_list **)scene->pl;
		pl = (t_plane *)lst->content;
		if (check_norm(v_gen(pl->vec)) == 1)
			return (error_msg("error: A plane vector is not normalized\n"));
	}
	if (check_norm(v_gen(scene->c.vec)) == 1)
		return (error_msg("error: Camera vector is not normalized\n"));
	return (0);
}
