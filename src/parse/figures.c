#include <miniRT.h>

/* Cada estructura queda libre para hacer los cálculos pertinentes para nuevas variables de utilidad. Es provisional este fill */

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
