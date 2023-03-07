#include <miniRT.h>

int	parse(char *s, t_scene *scene)
{
	//(void)scene;
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
