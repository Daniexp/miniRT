#include <miniRT.h>
/*
float	*ln_equation(float *point, float *vector)
{
	float	*equation;
	int		i;

	equation = ft_calloc(sizeof(float), 3);
	if (!equation)
		return (NULL);
	if (!point || !vector)
		return (free(equation), NULL);
	return (equation);
}
	Vector intersection(Vector c, Vector u, Plane p) {
    // Encontrar la ecuación del plano
    double d = -p.point.x * p.normal.x - p.point.y * p.normal.y - p.point.z * p.normal.z;
    // Encontrar la proyección del vector que va desde C en la dirección de U en el plano
    double proj = (c.x * p.normal.x + c.y * p.normal.y + c.z * p.normal.z + d) / (u.x * p.normal.x + u.y * p.normal.y + u.z * p.normal.z);
    Vector projection = {proj * u.x, proj * u.y, proj * u.z};
    // Encontrar la intersección
    Vector intersection = {c.x + projection.x, c.y + projection.y, c.z + projection.z};
    return intersection;
	}
*/

/*}}}}
float determinante_2x2(float **matrix) {
    float det = 0.0;
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return det;
}


float	*plane_equation(float *n, float *p)
{
	float	*eq;
	float	d;

	d = -1 * (n[0]*p[0] + n[1]*p[1] + n[2] * p[2]);
	eq = ft_calloc(4, sizeof(float));
	//if (!eq)
	//	return (NULL);
	eq[0] = n[0];
	eq[1] = n[1];
	eq[2] = n[2];
	eq[3] = d;
	return (eq);
}

float	**matrix_generator(float *v1, float *v2, float *v3)
{
	float	**matrix;
	int	i;

	i = 0;
	matrix = malloc(sizeof(float *) * 3);
	while (i < 3)
		matrix[i++] = ft_calloc(3, sizeof(float));
	matrix[0][0] = v1[0];
	matrix[0][1] = v2[0];
	matrix[0][2] = v3[0];
	matrix[1][0] = v1[1];
	matrix[1][1] = v2[1];
	matrix[1][2] = v3[1];
	matrix[2][0] = v1[2];
	matrix[2][1] = v2[2];
	matrix[2][2] = v3[2];
	return (matrix);
}

float	distance_point_plane(float *plane, float *p)
{
	float	num;
	float	den;
	float	res;

	num = plane[0] * p[0] + plane[1] * p[1] + plane[2] * p[2] + plane[3];
	if (num < 0)
		num *= -1;
	den = sqrt(plane[0] * plane[0] + plane[1] * plane[1] + plane[2] * plane[2]);
	res = num / den;
	return (res);
}

float	vec_module(float *v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

float	parallel(float *v, float *ab)
{
	float	num;
	float	den;
	float	res;

	num = vec_module(vectorial_prod(ab, v));
	den = vec_module(v);
	res = num / den;
	//printf("%f, %f, %f distancia: %f\n\n", v[0], v[1], v[2], res);
	return (res);
}

float	straight_intersect(float *v1, float *p, float *v2, float *q)
{
	float	*n;
	float	*plane;
	float	z_axis[3];

	z_axis[0] = 0;
	z_axis[1] = 0;
	z_axis[2] = 1;

	if (vec_module(vectorial_prod(v2, z_axis)) == 0)
		return (0);
	n = vectorial_prod(v1, v2);
	plane = plane_equation(n, p);
	if (plane[0] * q[0] + plane[1] * q[1] + plane[2] * q[2] + plane[3] == 0)
		return (1);
	return (0);
}

	*t = (p[1] - q[1]) / (v1[1] - v1[0]) + (p[0] - q[0]) / (v2[0]*(v1[1] - v1[0]));
	t2 = ((p[0] - q[0]) + t * v1[0] ) / v2[0];
	//inter = ft_calloc(3, sizeof(float));
	inter[0] = p[0] + t * v1[0];
	inter[1] = p[1] + t * v1[1];
	inter[2] = p[2] + t * v1[2];

	coor[0] = q[0] + t * v2[0];
	coor[1] = q[1] + t * v2[1];
	coor[2] = q[2] + t * v2[2];

	if (inter[0] != coor[0] || inter[1] != coor[1] || inter[2] != coor[2])
		return (0);
	return (1);
}*/

float	cylinder(t_vector ray, t_vector point, t_cylinder *cy)
{
		float	num;
		float	den;

		//printf("ray: (%f, %f, %f); point: (%f, %f, %f)\n", ray.x, ray.y, ray.z, point.x, point.y, point.z);
		if (cos(dotprod(ray, v_gen(cy->vec))) == 0)
		{
			num = vector_module(crossprod(subs_vector(point, v_gen(cy->coord)), ray));
			den = vector_module(ray);
			return (num / den);
		}
		else
		{
			num = dotprod(ray, crossprod(v_gen(cy->vec), subs_vector(v_gen(cy->coord), point)));
			if (num < 0)
				num *= -1;
			den = vector_module(crossprod(ray, v_gen(cy->vec)));
			return (num / den);
		}
		return -1;
}

/*
int	cylinder(float x[2], float *ray, float *p, t_cylinder *cy)
{
	t_vector	v;
	t_vector	u;
	t_vector	radyi;
	t_vector	pos;
	t_vector	ray_pos;
	t_vector	cy_dir;
	float	a;
	float	b;
	float	c;

	ray_pos = v_gen(p);
	pos = v_gen(cy->coord);
	cy_dir = v_gen(cy->vec);
	radyi = v_gen(ray);
	v = mult_k(cy_dir, dotprod(radyi, cy_dir));
	v = subs_vector(radyi, v);
	u = mult_k(cy_dir, dot_product(sub_vect(ray_pos, pos), cy_dir));
	u = sub_vect(sub_vect(ray_pos, pos), u);
	a = dotprod(v, v);
	b = 2 * dotprod(v, u);
	c = dotprod(u, u) - pow(cy->d / 2, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
		return (0);
	return (1);
}
*/

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



int	is_pixel_incylinder(float *v, float *p, t_scene *scene)
{
	t_vector	aux;
	t_vector	n;
	t_vector	mid;
	t_vector	middy;
	t_vector	ray;
	t_vector	rpinter;
	t_list		*lst;
	t_cylinder	*cy;
	float		d1;

	if (check_cy_bases(v, p, scene) == 1)
		return (2);
	lst = *(scene->cy);
	cy = (t_cylinder *) lst->content;
	ray = v_gen(v);
	aux = crossprod(ray, v_gen(cy->vec));
	n = crossprod(v_gen(cy->vec), aux);
	rpinter = plane_straight_inter(ray, v_gen(p), n, v_gen(cy->coord));
	//direccion la de aux. 
	d1 = dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), rpinter);

	ray = v_gen(cy->coord);
	n = (v_gen(cy->vec));
	n = normalize(n);
	aux = normalize(aux);
	middy.x = ray.x + (cy->h / 2) * n.x;
	middy.y = ray.y + (cy->h / 2) * n.y;
	middy.z = ray.z + (cy->h / 2) * n.z;
	mid.x = rpinter.x + d1 * aux.x;
	mid.y = rpinter.y + d1 * aux.y;
	mid.z = rpinter.z + d1 * aux.z;
	if (d1 > cy->d / 2)
		return (0);
	if (dot_dot_distance(middy, mid) > cy->h / 2)
		return (0);
	return (1);
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


t_vector	cy_inter(float	*v, float *p, t_scene *scene)
{
	t_list		*lst;
	t_vector	aux;
	t_vector	n;
	float		*base;
	t_vector	ray;
	t_vector	top;
	t_vector	rpinter;
	t_vector	intera;
	t_vector	interb;
	t_vector	v_normalize;
	t_cylinder	*cy;
	t_vector	origin;
	float		d1;
	float		d2;
	t_util_plane	plane;	

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	ray = v_gen(cy->coord);
	origin = v_gen(cy->vec);

	top.x = ray.x + cy->h * origin.x;
	top.y = ray.y + cy->h * origin.y;
	top.z = ray.z + cy->h * origin.z;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	ray = v_gen(v);
	aux = crossprod(ray, v_gen(cy->vec));
	n = crossprod(v_gen(cy->vec), aux);
	rpinter = plane_straight_inter(ray, v_gen(p), n, v_gen(cy->coord));
	//direccion la de aux. 
	base = cy_bases(v, p, scene);
	d1 = dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), rpinter);
	d2 = sqrt(pow(cy->d / 2, 2) - pow(d1, 2));
	v_normalize = normalize(ray);
	intera.x = rpinter.x + v_normalize.x * d2;
	intera.y = rpinter.y + v_normalize.y * d2;
	intera.z = rpinter.z + v_normalize.z * d2;

	interb.x = rpinter.x - v_normalize.x * d2;
	interb.y = rpinter.y - v_normalize.y * d2;
	interb.z = rpinter.z - v_normalize.z * d2;
	
	if (base && check_cy_bases(v, p, scene) == 2)
	{
		plane = pleq(v_gen(cy->vec), v_gen(cy->coord));
		if (subs_in_plane(plane, intera) > 0)
		{
			if (dot_dot_distance(intera, origin) > dot_dot_distance(v_gen(base), origin))
				return (v_gen(base));
			return (intera);
		}
		else if (subs_in_plane(plane, interb) > 0)
		{
			if (dot_dot_distance(interb, origin) > dot_dot_distance(v_gen(base), origin))
				return (v_gen(base));
			return (interb);
		}
	}
	else if (base && check_cy_bases(v, p, scene) == 3)
	{
		plane = pleq(invert(v_gen(cy->vec)), top);
		if (subs_in_plane(plane, intera) > 0)
		{
			if (dot_dot_distance(intera, origin) > dot_dot_distance(v_gen(base), origin))
				return (v_gen(base));
			return (intera);
		}
		else if (subs_in_plane(plane, interb) > 0)
		{
			if (dot_dot_distance(interb, origin) > dot_dot_distance(v_gen(base), origin))
				return (v_gen(base));
			return (interb);
		}
	}
		
	if (dot_dot_distance(intera, origin) > dot_dot_distance(interb, origin))
		return (interb);
	return (intera);
}

int	check_cy_bases(float *v, float *p, t_scene *scene)
{
	t_list		*lst;
	t_vector	inter;
	t_vector	up_inter;
	t_vector	base;
	t_vector	dir;
	t_vector	up_base;
	t_cylinder	*cy;
	(void)p;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	base = v_gen(cy->coord);
	dir = v_gen(cy->vec);
	up_base.x = base.x + cy->h * dir.x;
	up_base.y = base.y + cy->h * dir.y;
	up_base.z = base.z + cy->h * dir.z;

	inter = plane_straight_inter(v_gen(v), v_gen(scene->C.coord), v_gen(cy->vec), base);
	up_inter = plane_straight_inter(v_gen(v), v_gen(scene->C.coord), invert(v_gen(cy->vec)), up_base);
	if (dot_dot_distance(inter, v_gen(cy->coord)) < cy->d / 2 && dot_dot_distance(up_inter, up_base) < cy->d / 2)
		return (1);
	else if (dot_dot_distance(inter, v_gen(cy->coord)) <= cy->d / 2)
		return (2);
	else if (dot_dot_distance(up_inter, up_base) < cy->d / 2)
		return (3);
	return (0);
}


float	*cy_bases(float *v, float *p, t_scene *scene)
{
	t_list		*lst;
	t_vector	inter;
	t_vector	up_inter;
	t_vector	base;
	t_vector	dir;
	t_vector	up_base;
	t_cylinder	*cy;

	lst = *(scene->cy);
	cy = (t_cylinder *)lst->content;
	dir = v_gen(cy->coord);
	base = v_gen(cy->coord);
	up_base.x = base.x + cy->h * dir.x;
	up_base.y = base.y + cy->h * dir.y;
	up_base.z = base.z + cy->h * dir.z;

	inter = plane_straight_inter(v_gen(v), v_gen(scene->C.coord), v_gen(cy->vec), base);
	up_inter = plane_straight_inter(v_gen(v), v_gen(scene->C.coord), invert(v_gen(cy->vec)), up_base);
	if (check_cy_bases(v, p, scene) == 2)
	{
		if (dot_dot_distance(inter, v_gen(scene->C.coord)) < dot_dot_distance(up_inter, v_gen(scene->C.coord)))
			return (gen_v(inter));
		return (gen_v(up_inter));
	}
	
	if (dot_dot_distance(inter, base) <= cy->d / 2)
		return (gen_v(inter));
	else if (dot_dot_distance(up_inter, up_base) < cy->d / 2)
		return (gen_v(up_inter));
	return (NULL);
}


t_vector	obtain_mid_point(float *v, float *p, t_scene *scene)
{
	t_vector	aux;
	t_vector	n;
	t_vector	ray;
	t_vector	mid1;
	t_vector	mid2;
	float		*base;
	t_vector	rpinter;
	t_list		*lst;
	t_cylinder	*cy;
	float		d1;

	lst = *(scene->cy);
	cy = (t_cylinder *) lst->content;
	ray = v_gen(v);
	aux = crossprod(ray, v_gen(cy->vec));
	n = crossprod(v_gen(cy->vec), aux);
	rpinter = plane_straight_inter(ray, v_gen(p), n, v_gen(cy->coord));
	//direccion la de aux. 
	d1 = dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), rpinter);
	aux = normalize(aux);
	mid1.x = rpinter.x + d1 * aux.x;
	mid1.y = rpinter.y + d1 * aux.y;
	mid1.z = rpinter.z + d1 * aux.z;

	mid2.x = rpinter.x - d1 * aux.x;
	mid2.y = rpinter.y - d1 * aux.y;
	mid2.z = rpinter.z - d1 * aux.z;

	base = cy_bases(v, p, scene);

	if (dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), mid1) > dot_straight_distance(v_gen(cy->vec), v_gen(cy->coord), mid2))
	{
		if (base && dot_dot_distance(v_gen(base), v_gen(scene->C.coord)) < dot_dot_distance(mid2, v_gen(scene->C.coord)))
			return (v_gen(base));
		return (mid2);
	}
	if (base && dot_dot_distance(v_gen(base), v_gen(scene->C.coord)) < dot_dot_distance(mid1, v_gen(scene->C.coord)))
		return (v_gen(base));
	return (mid1);
}

/*
t_vector	normal_cylinder(float *p, t_vector mid)
{
	return (subs_vector(v_gen(p), mid));
}
*/
t_vector normal_cylinder(float *p, t_scene *scene)
{
    t_vector point;
    t_vector v;
    t_vector proj;
    t_vector center;
	t_vector	mid;
	t_vector	dir;
    t_list *lst;
    t_cylinder *cy;


    lst = *(scene->cy);
    cy = (t_cylinder *)lst->content;
	dir = v_gen(cy->vec);
	center = v_gen(cy->coord);
    point = v_gen(p);
    mid.x = center.x + (cy->h / 2) * dir.x;
    mid.y = center.y + (cy->h / 2) * dir.y;
    mid.z = center.z + (cy->h / 2) * dir.z;
    v = subs_vector(point, mid);
    proj = subs_vector(v, mult_k(v, dotprod(v, v_gen(cy->vec))));
    proj = normalize(proj);
    return (proj);
}

	
	/*
	point = v_gen(p);
	center = mult_k(v_gen(cy->coord), cy->h / 2);
	v = subs_vector(point, center);
	proj = subs_vector(v, mult_k(v, dotprod(v, v_gen(cy->vec))));
	proj = normalize(proj);
	return (mult_k(proj, cy->d / 2));
	*/
