/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_ii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:09:33 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/23 18:15:16 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_cylinder_ii(char **line_content, t_cylinder *cy)
{
	cy->d = atofelio(line_content[3]);
	cy->h = atofelio(line_content[4]);
}

void	fill_plane(char **coor, char **vec, char **rgb, t_plane *pl)
{
	int	i;

	if (!pl)
		return ;
	i = -1;
	while (++i < 3)
		pl->coord[i] = atofelio(coor[i]);
	i = -1;
	while (++i < 3)
		pl->vec[i] = atofelio(vec[i]);
	i = -1;
	while (++i < 3)
		pl->rgb[i] = atoi(rgb[i]);
}
