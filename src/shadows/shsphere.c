#include <miniRT.h>

int	same_in(float *v, t_vector point)
{
	t_vector subs;

	if (!v)
		return (0);
	subs = subs_vector(v_gen(v), point);
	if (fabs(subs.x) <= EPSILON && fabs(subs.y) <= EPSILON && fabs(subs.z) <= EPSILON)
		return (1);
	return (0);
}

float	*sect_plane_sh(float *vector, float *light, t_plane *pl)
{
	float	*inters;
	float	d;
	float	proj;
	int		i;

	inters = ft_calloc(sizeof(float), 3);
	normalize_vector(pl->vec);
	normalize_vector(vector);
	if (!inters)
		return (NULL);
	if (!vector || !light || !pl)
		return (free(inters), NULL);
	d = -pl->coord[0] * pl->vec[0] - pl->coord[1] * pl->vec[1]
		- pl->coord[2] * pl->vec[2];
	proj = (light[0] * pl->vec[0] + light[1] * pl->vec[1]
			+ light[2] * pl->vec[2] + d) / (vector[0] * pl->vec[0]
			+ vector[1] * pl->vec[1] + vector[2] * pl->vec[2]);
	if (isnan(proj))
		return (free(inters), NULL);
	i = -1;
	while (++i < 3)
		inters[i] = light[i] + proj * vector[i];
	return (inters);
}

float	distance_shadow(float *in, t_vector light)
{
	if (!in)
		return (-1);
	return (dot_dot_distance(v_gen(in), light));
}

void	shsphere(t_shadows *s, t_vector v, t_scene *scene)
{
	float		*in;
	float		len_l;
	t_list		*lst;
	t_sphere 	*sp;

	if (!scene->sp)
		return ;
	if (s->shadow == 1)
		return ;
	lst = *(scene->sp);
	while (lst)
	{
		in = NULL;
		sp = (t_sphere *)lst->content;
		//if (sp->shthis != 1)
	//	{
			in = sect_sphere(gen_v(v), s->light, sp->coord, sp->d / 2);
			len_l = distance_shadow(in, v_gen(s->light));
			if (in &&  len_l < s->len_l && same_in(in, v_gen(s->point)) == 0 )
			{
				if (isinscreen(in, scene) == 1)
					s->shadow = 1;
			}
	//	}
		lst = lst->next;
	}
}


void	shcylinder(t_shadows *s, t_vector v, t_scene *scene)
{
	float		*in;
	t_list		*lst;
	t_cylinder	*cy;
	float		len_l;

	if (!scene->cy)
		return ;
	lst = *(scene->cy);
	while (lst)
	{
		in = NULL;
		cy = (t_cylinder *)lst->content;
	//	if (cy->shthis != 1)
	//	{
			in = cylinder_sh(normalize(v), scene, cy);
			len_l = distance_shadow(in, v_gen(scene->L.coord));
			if (in &&  len_l < s->len_l && same_in(in, v_gen(s->point)) == 0 )
			{
				if (isinscreen(in, scene) == 1)
					s->shadow = 1;
			}
	//	}
		lst = lst->next;
	}
}




void	shplane(t_shadows *s, t_vector v, t_scene *scene)
{
	float		*in;
	t_list		*lst;
	t_plane		*pl;
	float		len_l;

	if (!scene->pl)
		return ;
	if (s->shadow == 1)
		return ;
	lst = *(scene->pl);
	while (lst)
	{
		in = NULL;
		pl = (t_plane *)lst->content;
	//	if (pl->shthis != 1)
	//	{
			in = sect_plane_sh(gen_v(v), scene->L.coord, pl);
			len_l = distance_shadow(in, v_gen(scene->L.coord));
			if (in && fabs(len_l - s->len_l) >= EPSILON && len_l < s->len_l && same_in(in, v_gen(s->point)) == 0)
			{
				if (isinscreen(in, scene) == 1)
					s->shadow = 1;
			}
	//	}
		lst = lst->next;
	}
}

