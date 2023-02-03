#include <miniRT.h>

int	error_params(int n_line, int mode)
{
	if (mode == 0)
	{
		error_msg("error: Invalid number of parameters in line: ");
		n_line += 48;
		write(2, &n_line, 1);
		error_msg("\n");
		return (1);
	}
	else if (mode == 1)
	{
		error_msg("error: Invalid parameter in line: ");
		n_line += 48;
		write(2, &n_line, 1);
		error_msg("\n");
		return (1);
	}
	return (0);
}

int	ambient(char **line_content, t_scene *scene, int n_line)
{
	char	**rgb;
	int		i;

	(void)scene;
	i = 0;
	if (double_pointier_len(line_content) != 3)
		return (error_params(n_line, 0));
	if (check_all_nb(line_content[1]) == 1)
		return (error_params(n_line, 1));
	rgb = ft_split(line_content[2], ',');
	if (double_pointier_len(rgb) != 3)
		return (error_params(n_line, 1));
	while (rgb[i])
		if (check_all_nb(rgb[i++]) == 1)
			return (error_params(n_line, 1));
	scene->A.rate = atofelio(line_content[1]);
	i = 0;
	while (i < 3)
	{
		scene->A.rgb[i] = ft_atoi(rgb[i]);
		i++;
	}
	return (0);
}
