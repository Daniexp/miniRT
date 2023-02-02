#include <miniRT.h>

void	process_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return ;
}

int	fill_scene(int fd, t_scene *scene)
{
	char	*line;
	int	n_line;

	n_line = 1;
	line = get_next_line(fd);
	while (line)
	{
		process_line(line);
		n_line++;
	}
	return (0);
}
