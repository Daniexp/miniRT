#include <miniRT.h>

int	process_id(char **line_content, int n_line)
{
	if (ft_strncmp(line_content[0], "A", ft_strlen(line_content[0])) == 0)
		ambient(line_content);
	else if (ft_strncmp(line_content[0], "C", ft_strlen(line_content[0])) == 0)
		camera(line_content);
	else if (ft_strncmp(line_content[0], "L", ft_strlen(line_content[0])) == 0)
		light(line_content);
	else if (ft_strncmp(line_content[0], "sp", ft_strlen(line_content[0])) == 0)
		sphere(line_content);
	else if (ft_strncmp(line_content[0], "pl", ft_strlen(line_content[0])) == 0)
		plane(line_content);
	else if (ft_strncmp(line_content[0], "cy", ft_strlen(line_content[0])) == 0)
		cylinder(line_content);
	else
	{
		error_msg("Invalid identifier in row: ");
		error_msg((char *)n_line);
		error_msg("\n");
		return (1);
	}
	return (0);
}	

void	split_line(char *line, int n_line)
{
	int		i;
	char	**line_content;

	i = 0;
	if (line[i] == '\n')
		return ;
	line_content = ft_split(line, ' ');
	if (process_id(line_content, n_line) == 1)
		return (1);
	return (0);
}

int	fill_scene(int fd, t_scene *scene)
{
	char	*line;
	int	n_line;

	n_line = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (split_lane(line, n_line) == 1)
			return ;
		n_line++;
	}
	return (0);
}
