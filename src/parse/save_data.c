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
	i = 0;
	while (i < 3)
	{
		if (check_range((float)ft_atoi(rgb[i]), (float)0, (float)255) == 1)
			return (error_params(n_line, 1));
		i++;
	}
	fill_ambient(rgb, line_content[1], scene);
	return (0);
}

int	camera(char **line_content, t_scene *scene, int n_line)
{
	char	**coor;
	char	**v;
	int		i;

	i = 0;
	if (double_pointier_len(line_content) != 4)
		return (error_params(n_line, 0));
	coor = ft_split(line_content[1], ',');
	if (double_pointier_len(coor) != 3)
		return (error_params(n_line, 1));
	while (coor[i])
		if (check_all_nb(coor[i++]) == 1)
			return (error_params(n_line, 1));
	i = 0;
	v = ft_split(line_content[2], ',');
	if (double_pointier_len(v) != 3)
	while (v[i])
		if (check_all_nb(v[i++]) == 1)
			return (error_params(n_line, 1));
	if (check_range(atofelio(line_content[3]), 0, 180) == 1 || check_all_nb(line_content[3]))
		return (error_params(n_line, 1));
	fill_camera(coor, v, line_content[3], scene);
	return (0);
}

int	light(char	**line_content, t_scene *scene, int n_line)
{
	char	**coor;
	float	rate;
	int		i;

	if (double_pointier_len(line_content) != 3)
		return (error_params(n_line, 0));
	coor = ft_split(line_content[1], ',');
	if (double_pointier_len(coor) != 3)
		return (error_params(n_line, 1));
	i = 0;
	while (i < 3)
		if (check_all_nb(coor[i++]) == 1)
			return (error_params(n_line, 1));
	rate = atofelio(line_content[2]);
	if (check_range(rate, 0, 1) == 1)
		return (error_params(n_line, 1));
	fill_light(coor, rate, scene);
	return (0);
}
