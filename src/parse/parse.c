/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:18:29 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/23 19:18:40 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	parse(char *s, t_scene *scene)
{
	int	fd;

	if (!s || !scene)
		return (-1);
	scene->sp = NULL;
	scene->cy = NULL;
	scene->pl = NULL;
	if (check_extension(s) == 1)
		return (1);
	fd = open_file(s);
	if (pre_read(fd, scene) == 1)
		return (1);
	close(fd);
	fd = open_file(s);
	if (fill_scene(fd, scene) == 1)
		return (1);
	return (0);
}
