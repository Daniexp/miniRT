#include <miniRT.h>

int	error_id(int n_line, int ref)
{
	if (ref == 0)
	{
		error_msg("error: Invalid identifier in row: ");
		write(2, &n_line, 1);
		error_msg("\n");
		return (1);
	}
	else if (ref == 1)
	{
		error_msg("error: Missing or more than one of capital letter elements in row: ");
		ft_putnbr_fd(n_line, 2);
		error_msg("\n");
		return (1);
	}
	return (1);
}


int	process_id(char **line_content, int n_line, t_scene *scene)
{
	if (ft_strncmp(line_content[0], "A", ft_strlen(line_content[0])) == 0)
	{
		if (ambient(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "C", ft_strlen(line_content[0])) == 0)
	{
		if (camera(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "L", ft_strlen(line_content[0])) == 0)
	{
		if (light(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "sp", ft_strlen(line_content[0])) == 0)
	{
		if (sphere_check(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "pl", ft_strlen(line_content[0])) == 0)
	{
		if (plane_check(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "cy", ft_strlen(line_content[0])) == 0)
	{
		if (cylinder_check(line_content, scene, n_line) == 1)
			return (1);
	}
	else
		return (0);
	/*
	else
		error_id(n_line);*/
	return (0);
}	

int	split_line(char *line, int n_line, t_scene *scene)
{
	int		i;
	char	**line_content;
	char	*neo_line;

	i = 0;
	if (line[i] == '\n')
		return (0);
//	neo_line = quit_c(line, '\n');
	neo_line = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	line_content = ft_split(neo_line, ' ');
	free(neo_line);
	if (process_id(line_content, n_line, scene) == 1)
		return (1);
	return (0);
}

int	fill_scene(int fd, t_scene *scene)
{
	//(void)scene;
	char	*line;
	int	n_line;

	n_line = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (split_line(line, n_line, scene) == 1)
			return (1);
		line = get_next_line(fd);
		n_line++;
	}
	return (0);
}
