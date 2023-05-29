#include <miniRT.h>

t_shadows	*get_shadows(float *v, t_inters *inter, t_scene *scene)
{
	t_shadows	*s;
	t_inters	*res;
	int		i;

	s = ft_calloc(sizeof(t_shadows), 1);
	res = ft_calloc(sizeof(t_inters), 1);
	(void)inter;
	(void)res;
	s->point = inter->point;
	s->len_l = dot_dot_distance(v_gen(inter->point), v_gen(scene->L.coord));
	s->type = 3;
	s->shadow = 0;
	i = 0;
	while (i < 3)
	{
		s->light[i] = scene->L.coord[i];
		i++;
	}
	if (scene->sp)
		shsphere(s, v_gen(v), scene);
	if (scene->cy)
		shcylinder(s, v_gen(v), scene);
	if (scene->pl)
		shplane(s, v_gen(v), scene);
	/*
	if (res->type == SPHERE)
	{
		cy_clearsh(scene, res, 0);
		pl_clearsh(scene, res, 0);
		sp_clearsh(scene, res, 23);
	}
	else if (res->type == CYLINDER)
	{
		cy_clearsh(scene, res, 420);
		pl_clearsh(scene, res, 0);
		sp_clearsh(scene, res, 0);
	}
	else if (res->type == PLANE)
	{
		cy_clearsh(scene, res, 0);
		pl_clearsh(scene, res, 69);
		sp_clearsh(scene, res, 0);
	}
*/
	return (s);
}
