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
		printf("$$%f$$\n", atofelio(coord[i]));
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
