#include <miniRT.h>

int	error_params(int n_line, int mode, char **v1, char **v2)
{
	free_arg(v1);
	free_arg(v2);
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
		return (error_params(n_line, 0, NULL, NULL));
	if (check_all_nb(line_content[1]) == 1)
		return (error_params(n_line, 0, NULL, NULL));
	rgb = ft_split(line_content[2], ',');
	if (double_pointier_len(rgb) != 3)
		return (error_params(n_line, 0, rgb, NULL));
	while (rgb[i])
		if (check_all_nb(rgb[i++]) == 1)
			return (error_params(n_line, 0, rgb, NULL));
	i = 0;
	while (i < 3)
	{
		if (check_range((float)ft_atoi(rgb[i]), (float)0, (float)255) == 1)
			return (error_params(n_line, 1, rgb, NULL));
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
		return (error_params(n_line, 0, NULL, NULL));
	coor = ft_split(line_content[1], ',');
	if (double_pointier_len(coor) != 3)
		return (error_params(n_line, 0, coor, NULL));
	while (coor[i])
		if (check_all_nb(coor[i++]) == 1)
			return (error_params(n_line, 0, coor, NULL));
	i = 0;
	v = ft_split(line_content[2], ',');
	if (double_pointier_len(v) != 3)
		return (error_params(n_line, 0, coor, v));
	while (v[i])
		if (check_all_nb(v[i++]) == 1)
			return (error_params(n_line, 0, coor, v));
	if (check_range(atofelio(line_content[3]), 0, 180) == 1 || check_all_nb(line_content[3]))
		return (error_params(n_line, 0, coor, v));
	fill_camera(coor, v, line_content[3], scene);
	return (0);
}

int	light(char	**line_content, t_scene *scene, int n_line)
{
	char	**coor;
	float	rate;
	int		i;

	if (double_pointier_len(line_content) != 3)
		return (error_params(n_line, 0, NULL, NULL));
	coor = ft_split(line_content[1], ',');
	if (double_pointier_len(coor) != 3)
		return (error_params(n_line, 0, coor, NULL));
	i = 0;
	while (i < 3)
		if (check_all_nb(coor[i++]) == 1)
			return (error_params(n_line, 0, coor, NULL));
	rate = atofelio(line_content[2]);
	if (check_range(rate, 0, 1) == 1)
			return (error_params(n_line, 0, coor, NULL));
	fill_light(coor, rate, scene);
	return (0);
}

int	sphere_check(char	**line_content, t_scene *scene, int n_line)
{
	(void)scene;
	char	**coor;
	t_sphere	*sp;
	char	**rgb;

	if (double_pointier_len(line_content) != 4)
		return (error_params(n_line, 0, NULL, NULL));
	coor = ft_split(line_content[1], ',');
	if (check_vec3d(coor) == 1)
		return (error_params(n_line, 0, coor, NULL));
	rgb = ft_split(line_content[3], ',');
	if (check_vec3d(rgb) == 1)
		return (error_params(n_line, 0, coor, rgb));
	if (check_all_nb(line_content[2]) == 1)
		return (error_params(n_line, 0, coor, rgb));
	sp = malloc(sizeof(t_sphere));
	fill_sphere(coor, line_content[2], rgb, sp);
	return (0);
}



