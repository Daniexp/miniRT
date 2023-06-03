/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:18:44 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:47:47 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	counter(char	*id, t_scene *scene, int n_line)
{
	if (ft_strncmp(id, "A", ft_strlen(id)) == 0)
		scene->n_a++;
	else if (ft_strncmp(id, "L", ft_strlen(id)) == 0)
		scene->n_l++;
	else if (ft_strncmp(id, "C", ft_strlen(id)) == 0)
		scene->n_c++;
	else if (ft_strncmp(id, "sp", ft_strlen(id)) == 0)
		scene->n_sp++;
	else if (ft_strncmp(id, "cy", ft_strlen(id)) == 0)
		scene->n_cy++;
	else if (ft_strncmp(id, "pl", ft_strlen(id)) == 0)
		scene->n_pl++;
	else
		return (error_id(n_line, 0));
	return (0);
}

int	analyze_content(char *line, t_scene *scene, int n_line)
{
	char	**line_content;

	if (line[0] == '\n')
	{
		free(line);
		return (0);
	}
	line_content = ft_split(line, ' ');
	free(line);
	if (counter(line_content[0], scene, n_line) == 1)
	{
		free_arg(line_content);
		return (1);
	}
	free_arg(line_content);
	return (0);
}

int	check_elements(t_scene *scene, int n_line)
{
	if (scene->n_a != 1 || scene->n_l != 1 || scene->n_c != 1)
		return (error_id(n_line, 1));
	return (0);
}

int	pre_read(int fd, t_scene *scene)
{
	char	*line;
	int		n_line;

	line = get_next_line(fd);
	n_line = 1;
	while (line)
	{
		if (analyze_content(line, scene, n_line) == 1)
			return (1);
		line = get_next_line(fd);
		n_line++;
	}
	if (check_elements(scene, n_line) == 1)
		return (1);
	return (0);
}
