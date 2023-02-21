#include <miniRT.h>

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

int	count_dots(char *s)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	while (s[i])
	{
		if (s[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}

int	check_extension(char *s)
{
	int	i;
	char	*ext;

	i = 0;
	if (count_dots(s) != 1)
	{
		error_msg("Wrong extension of input file");
		return (1);
	}
	while (s[i])
	{
		if (s[i] == '.')
		{
			ext = ft_strdup(&s[i + 1]);
			if (ft_strncmp(ext, "rt", 2) == 0)
				return (0);
		}
		i++;
	}
	error_msg("Extension must be .rt");
	return (1);
}
