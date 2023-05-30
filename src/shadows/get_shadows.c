#include <miniRT.h>

t_shadows	*get_shadows(float *v, t_inters *inter, t_scene *scene, t_inters *res)
{
	t_shadows	*s;
	int		i;

	s = ft_calloc(sizeof(t_shadows), 1);
	(void)inter;
	(void)res;
	s->point = fdup(inter->point);
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
		shsphere(s, normalize(v_gen(v)), scene, res);
	if (scene->cy) //&& res->type != CYLINDER)
		shcylinder(s, normalize(v_gen(v)), scene, res);
	if (scene->pl)
		shplane(s, normalize(v_gen(v)), scene, res);
	free(v);
	return (s);
}
