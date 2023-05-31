#ifndef SHADOWS_H
#define SHADOWS_H

#include <miniRT.h>

typedef	struct s_shadows{
	int	type;
	float	*point;
	float	len_l;
	float	light[3];
	int	shadow;
}	t_shadows;

t_shadows *get_shadows(float *v, t_inters *inter, t_scene *scene, t_inters *res);
void	shsphere(t_shadows *s, float *v, t_scene *scene, t_inters *res);
void	shcylinder(t_shadows *s, t_vector v, t_scene *scene, t_inters *res);
void	shplane(t_shadows *s, float *v, t_scene *scene, t_inters *res);
float	*cylinder_sh(t_vector v, t_scene *scene, t_cylinder *cy);
t_vector	compare_sh(t_vector u, t_vector v, t_scene *scene);
void	cy_clearsh(t_scene *scene, t_inters *res, int ref);
void	pl_clearsh(t_scene *scene, t_inters *res, int ref);
void	sp_clearsh(t_scene *scene, t_inters *res, int ref);
float		*the_bases_ii_sh(t_vector v, t_scene *scene, t_cylinder *cy);

#endif
