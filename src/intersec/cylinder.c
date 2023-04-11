#include <miniRT.h>

t_vector	plane_straight_inter(t_vector s, t_vector p, t_vector normal, t_vector pplane)
{
	float			t;
	float			num;
	float			den;
	t_vector		point;
	t_util_plane	plane;

	plane = pleq(normal, pplane);
	num = -1 * (plane.d + plane.a * p.x + plane.b * p.y + plane.c * p.z);
	den = dotprod(normal, s);
	t = num / den;
	point.x = p.x + t * s.x;
	point.y = p.y + t * s.y;
	point.z = p.z + t * s.z;
	return (point);
}

float	plane_dot_distance(t_vector dot, t_vector n, t_vector pplane)
{
	t_util_plane	plane;
	float	num;
	float	den;

	plane = pleq(n, pplane);
	num = plane.a * dot.x + plane.b * dot.y + plane.c * dot.z + plane.d;
	if (num < 0)
		num *= -1;
	den = sqrt(dotprod(n, n));
	return (num / den);
}

float	dot_straight_distance(t_vector s, t_vector p, t_vector dot)
{
	t_vector	vectorial;
	float		num;
	float		den;

	vectorial = crossprod(subs_vector(p, dot), s);
	num = vector_module(vectorial);
	den = vector_module(s);
	return (num / den);
}

float	dot_dot_distance(t_vector p, t_vector q)
{
	t_vector	tuk;

	tuk = subs_vector(p, q);
	return (vector_module(tuk));
}

int	check_inter(t_vector inter, t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_vector	top;
	t_vector	bot;
	t_util_plane	real_top;
	t_util_plane	real_bot;
	t_vector	dir;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	bot = v_gen(cy->coord);
	dir = v_gen(cy->vec);
	top.x = bot.x + cy->h * dir.x;
	top.y = bot.y + cy->h * dir.y;
	top.z = bot.z + cy->h * dir.z;
	real_bot = pleq(v_gen(cy->vec), v_gen(cy->coord));
	real_top = pleq(invert(v_gen(cy->vec)), top);
	if (subs_in_plane(real_bot, inter) >= 0 && subs_in_plane(real_top, inter) >= 0)
		return (1);
	return  (0);
}

t_vector	invert(t_vector a)
{
	t_vector	q;

	q.x = -a.x;
	q.y = -a.y;
	q.z = -a.z;
	return (q);
}

float	subs_in_plane(t_util_plane plane, t_vector p)
{
	return (plane.a * p.x + plane.b * p.y + plane.c * p.z + plane.d);
}

t_vector	compare(t_vector u, t_vector v, t_scene *scene)
{
	if (dot_dot_distance(u, v_gen(scene->C.coord)) < dot_dot_distance(v, v_gen(scene->C.coord)))
		return (u);
	return (v);
}

float	*the_bases_I(t_vector v, t_scene *scene)
{
	t_list		*lst;
	t_vector	top;
	t_vector	top_inter;
	t_vector	bot_inter;
	float		d1;
	float		d2;
	t_cylinder	*cy;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	top = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,  v_gen(scene->C.coord), invert(v_gen(cy->vec)), top);
	bot_inter = plane_straight_inter(v,  v_gen(scene->C.coord), v_gen(cy->vec), v_gen(cy->coord));
	d1 = dot_dot_distance(bot_inter, v_gen(cy->coord));
	d2 = dot_dot_distance(top_inter, top);
	if (d1 <= cy-> d / 2  && d2 <= cy-> d / 2)
	{
		top_inter = compare(top_inter, bot_inter, scene);
		return (gen_v(top_inter));
	}
	return (NULL);
}



	
float	*the_bases_II(t_vector v, t_scene *scene)
{
	t_list		*lst;
	t_vector	top;
	t_vector	top_inter;
	t_vector	bot_inter;
	t_cylinder	*cy;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	top = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h));
	top_inter = plane_straight_inter(v,  v_gen(scene->C.coord), invert(v_gen(cy->vec)), top);
	bot_inter = plane_straight_inter(v,  v_gen(scene->C.coord), v_gen(cy->vec), v_gen(cy->coord));
	if (dot_dot_distance(top_inter, top) <= cy->d / 2)
		return (gen_v(top_inter));
	if (dot_dot_distance(bot_inter, v_gen(cy->coord)) <= cy->d / 2)
		return (gen_v(bot_inter));
	return (NULL);
}

float	*cylinder(t_vector v, t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_vector	aux;
	t_vector	n;
	float		*bases;
	t_vector	dir;
	t_vector	aux_inter;
	t_vector	rpinter;
	t_vector	mid;
	t_vector	inter;
	float		d1;
	float		d2;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	mid = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h / 2));
	bases = the_bases_I(v, scene);
	if (bases)
		return (bases);
	dir = normalize(v_gen(cy->vec));
	aux = crossprod(v, dir);
	n = crossprod(dir, aux);
	rpinter = plane_straight_inter(v, v_gen(scene->C.coord), n, v_gen(cy->coord));
	d1 = dot_straight_distance(dir, v_gen(cy->coord), rpinter);
	if (d1 > cy->d / 2)
		return (NULL);
	d2 = sqrt(pow(cy->d / 2, 2) - pow(d1, 2));
	inter = subs_vector(rpinter, mult_k(normalize(v), d2));
	aux_inter = plane_straight_inter(v_gen(cy->vec), v_gen(cy->coord), v_gen(cy->vec), inter);
	//printf("--%f--\n", dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), aux_inter));
	//printf("%f, %f, %f\n", aux_inter.x, aux_inter.y, aux_inter.z);
	bases = the_bases_II(normalize(v), scene);
	if (bases)
	{
		//printf("%f, %f, %f\n", bases[0], bases[1], bases[2]);
		inter = compare(v_gen(bases), inter, scene);
		return (gen_v(inter));
	}
	if (dot_dot_distance(aux_inter, mid) > cy->h / 2)
		return (NULL);
	return (gen_v(inter));
}

int	normal_for_bases(t_vector inter, t_scene *scene)
{
	t_list		*lst;
	t_cylinder	*cy;
	t_vector	top;
	t_util_plane	bottom;
	t_util_plane	topo;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	top = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h));
	topo = pleq(invert(v_gen(cy->vec)), top);
	bottom = pleq(v_gen(cy->vec), v_gen(cy->coord));
	if (dot_dot_distance(inter, v_gen(cy->coord)) <= cy->d / 2 || dot_dot_distance(inter, top) <= cy->d / 2)
		return (1);
	return (0);
}
	



t_vector	normal_cylinder(t_vector inter, t_vector v, t_scene *scene)
{
	t_vector	mid;
	t_vector	dir;
	t_vector	top;
	t_vector	proj;
	t_vector	aux;
//	t_vector	aux2;
	t_list		*lst;
	t_cylinder	*cy;

	(void)v;
	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	top = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h));

	aux = subs_vector(v_gen(cy->coord), inter);
	//aux2 = subs_vector(top, inter);
	if (dotprod(aux, v_gen(cy->vec)) <= EPSILON && dotprod(aux, v_gen(cy->vec)) >= -EPSILON)
		return (invert(v_gen(cy->vec)));
	//if (dotprod(aux2, v_gen(cy->vec)) <= EPSILON && dotprod(aux2, v_gen(cy->vec)) >= -EPSILON)
	//	return (v_gen(cy->vec));


	mid = add_vector(v_gen(cy->coord), mult_k(normalize(v_gen(cy->vec)), cy->h / 2));
	mid = subs_vector(inter, mid);
	dir = normalize(v_gen(cy->vec));
	proj.x = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.x;
	proj.y = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.y;
	proj.z = (dotprod(mid, dir) / dotprod(dir, dir)) * dir.z;
	proj = subs_vector(mid, proj);
	return (normalize(proj));
}

