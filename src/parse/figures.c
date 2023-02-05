#include <miniRT.h>

/* Cada estructura queda libre para hacer los cálculos pertinentes para nuevas variables de utilidad. Es provisional este fill */
/*
t_sphere sphere(float coord[3], float d, unsigned int rgb[3])
{
	t_sphere sp;

	sp
	sp.d = d;
	sp.rgb = rgb;
	return (sp);
}

t_plane plane(float coord[3], float vec[3], unsigned int rgb[3])
{
	t_plane pl;

	pl.coord = vcpy(coord, pl.coord);
	pl.vec = vec;
	pl.rgb = rgb;
	return (pl);
}

t_cylinder cylinder(float coord[3], float vec[3], float d, float h)
{
	t_cylinder cy;

	cy.coord = coord;
	cy.vec = vec;
	cy.d = d;
	cy.h = h;
	return (cy);
}
*/
void	fill_ambient(char **rgb, char *line_content, t_scene *scene)
{
	int	i;

	i = 0;
	scene->A.rate = atofelio(line_content);
	while (i < 3)
	{
		scene->A.rgb[i] = ft_atoi(rgb[i]);
		i++;
	}
}

void	fill_camera(char **coord, char **v, char *fov, t_scene *scene)
{
	int i;

	i = 0;
	while (i < 3)
	{
		scene->C.coord[i] = atofelio(coord[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		scene->C.vec[i] = atofelio(v[i]);
		i++;
	}
	scene->C.fov = atofelio(fov);
}

void	fill_light(char **coor, float rate, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		scene->L.coord[i] = atofelio(coor[i]);
		i++;
	}
	scene->L.rate = rate;
}

void	fill_sphere(char **coor, char *d, char **rgb, t_sphere *sp)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		sp->coord[i] = atofelio(coor[i]);
		i++;
	}
	sp->d = atofelio(d);
	i = 0;
	while (i < 3)
	{
		sp->rgb[i] = ft_atoi(rgb[i]);
		i++;
	}
}

void	fill_cylinder(char **coor, char **vec, char **rgb, char **line_content, t_cylinder *cy)
{
	int	i;

	i = -1;
	while (++i < 3)
		cy->coord[i] = atofelio(coor[i]);
	i = -1;
	while (++i < 3)
		cy->vec[i] = atofelio(vec[i]);
	i = -1;
	while (++i < 3)
		cy->rgb[i] = atofelio(rgb[i]);
	cy->d = atofelio(line_content[3]);
	cy->h = atofelio(line_content[4]);
}
