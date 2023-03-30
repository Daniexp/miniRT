#include <miniRT.h>

#include <math.h>
/*
int intersect_ray_cylinder(float *ray_origin, float *ray_direction, float *cylinder_center, float cylinder_radius, float cylinder_height, float *t)
{
    // Calcula los coeficientes del sistema de ecuaciones lineales
    float a = ray_direction[0]*ray_direction[0] + ray_direction[1]*ray_direction[1];
    float b = 2*(ray_direction[0]*(ray_origin[0]-cylinder_center[0]) + ray_direction[1]*(ray_origin[1]-cylinder_center[1]));
    float c = (ray_origin[0]-cylinder_center[0])*(ray_origin[0]-cylinder_center[0]) +(ray_origin[1]-cylinder_center[1])*(ray_origin[1]-cylinder_center[1]) - cylinder_radius*cylinder_radius;

    // Calcula la discriminante del sistema de ecuaciones lineales
    float discriminant = b*b - 4*a*c;

    // Si la discriminante es negativa, la recta no intersecta el cilindro
    if (discriminant < 0)
	{
        return 0;
	}

    // Calcula las soluciones del sistema de ecuaciones lineales
    float t1 = (-b + sqrt(discriminant)) / (2*a);
    float t2 = (-b - sqrt(discriminant)) / (2*a);

    // Verifica si las soluciones están dentro del rango de altura del cilindro
    float z1 = ray_origin[2] + t1*ray_direction[2] - cylinder_center[2];
    float z2 = ray_origin[2] + t2*ray_direction[2] - cylinder_center[2];
    if (z1 < 0 || z1 > cylinder_height)
        t1 = -1;
    if (z2 < 0 || z2 > cylinder_height)
        t2 = -1;

    // Elige la solución más cercana al origen de la recta
    if (t1 < 0 && t2 < 0)
	{
        return 0;
	}
    else if (t1 < 0)
        *t = t2;
    else if (t2 < 0)
        *t = t1;
    else if (t1 < t2)
        *t = t1;
    else
        *t = t2;

    return 1;
}
*/

float	vector_module(float *v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

float	trans_height(float height, float *v, float *p, int coor, float alpha)
{
	return ((p[coor] + height * v[1]) * sin(alpha) + (p[coor] + height * v[coor]) * cos(alpha));
}
/*
int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{
	float	a;
	float	b;
	float	c;
	float	alpha;
	float	z_axis[3];
	float	t1;
	float	t2;
	float	determinante;
	float	base;

	(void)t1;
	(void)t2;
	(void)height;
	z_axis[0] = 0;
	z_axis[1] = 0;
	z_axis[2] = 1;
	alpha = acos(escalar_prod(dir, z_axis) / vector_module(dir));
	if (alpha == 0)
		return (0);
	a = v[0] * v[0] + v[1] * v[1] * cos(alpha) * cos(alpha) + 2 * v[1] * v[2] * cos(alpha) * sin(alpha);
	b = 2 * p[0] * v[0] - 2 * v[0] * center[0] + p[1] * v[1] * cos(alpha) + 2 * p[1] * v[2] * sin(alpha) + 2 * p[2] * v[1] * cos(alpha) - 2 * center[1] * v[1] * cos(alpha) + p[2] * v[2] * sin(alpha) - 2 * center[1] * v[2] * sin(alpha);
	c = p[0] * p[0] - 2 * p[0] * center[0] + center[0] * center[0] + p[1] * p[1] + 2 * p[1] * p[2] - 2 * p[1] * center[1] + p[2] * p[2] - 2 * p[2] * center[1] + center[1] * center[1] - radius * radius;
	
	determinante = b * b - 4 * a * c;
	if (determinante < 0)
		return (1);
	t1 = -b + sqrt(determinante) / 2 * a;
	t2 = -b - sqrt(determinante) / 2 * a;
	base = trans_height(height, dir, center, 2, alpha);
	if (t1 > 0)
	{
		if (trans_height(t1, v, p, 2, alpha) > base)
			return (1);
	}
	else if (t2 > 0)
	{
		if (trans_height(t2, v, p, 2, alpha) > base)
			return (1);
	}
	return (0);
}
*/

float	check_newton_raphson(float *v, float *p, float *dir, float *center, float radius, float t, float w)
{
	float	f_t_w;

	f_t_w = (pow((p[0] + w * v[0] - center[0] - dir[0] * t), 2) + pow((p[1] + w * v[1] - center[1] - dir[1] * t), 2) + pow((p[2] + w * v[2] - center[2] - dir[2] * t), 2) - pow(radius, 2));
	if (f_t_w < 0)
		f_t_w *= -1;
	return (f_t_w);
}

/*
int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{
	float a;
	float b;
	//float c;
	(void)height;
	float d;
	float e;
	float f;
	float g;
	float	t;
	float	w;
	float	x;
	float	y;
	float	z;
	int	i;

	i = 0;
	t = 0;
	w = 0;

	a = pow(dir[0], 2) + pow(dir[1], 2) + pow(dir[2], 2);
	b = -2 * (center[0] * dir[0] + center[1] * dir[1] + center[2] * dir[2] - (p[0] * v[0] + p[1] * v[1] + p[2] * v[2]));
	//c = pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2);
	d = -2 * (dir[0] * (center[0] - p[0]) + dir[2] * (center[1] - p[1]) + dir[2] * (center[2] - p[2]) - w * (v[0] * dir[0]) + v[1] * dir[1] + v[2] * dir[2]);
	e = dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2];
	f = -2 * (w * (v[0] * v[1] + v[1] * v[2] + v[2] * v[0]));
	g = pow((p[0] - center[0]), 2) + pow((p[1] - center[1]), 2) + pow((p[2] - center[2]), 2) - pow(radius, 2);


	while (check_newton_raphson(v, p, dir, center, radius, t, w)  >= 2 || i <= 10000)
	{
		i++;
		t = t - (a * t + b * w + d * t + e * w + g) / (2 * a * t + b * w + d);
		w = w - (b * t + e * w + f) / (b * t + 2 * e * w + f);
	}
	x = p[0] + t * v[0];
	y = p[1] + t * v[1];
	z = p[2] + t * v[2];

	if (pow((x - center[0]) - dir[0] * w, 2) + pow((y - center[1]) - dir[1] * w, 2) + pow((z - center[2]) - dir[2] * w, 2) - pow(radius, 2) <= 1)
		return (0);
	return (1);
}
*/
/*
int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{
	float	a;
	float	b;
	float	c;
	float	t;
	//float	x;
	//float	x_prima;
	float	w;
	//float	w_prima;
	float	t2;
	float	determinante;

	a = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	b = 2 * (p[0] * v[0] + p[1] * v[1] + p[2] * v[2]);
	c = p[0] * p[0] + p[1] * p[1] + p[2] * p[2] - radius * radius;
	determinante = b * b - 4 * a * c;

	if (determinante < 0)
		return (1);
	t = (-b + sqrt(determinante)) / 2 * a;
	t2 = (-b + sqrt(determinante)) / 2 * a;
	//x = p[0] + t * v[0];
	//x_prima = p[0] + t2 * v[0];
	if (dir[0] != 0)
		w = (p[0] + t * v[0] - center[0]) / dir[0];
	else if (dir[1] != 0)
		w = (p[1] + t * v[1] - center[1]) / dir[1];
	else if (dir[2] != 0)
		w = (p[2] + t * v[2] - center[2]) / dir[2];
	//printf("w: %f", w);
	//if (w < 0)
	//	w *= -1;
	if (w <= height)
		return (1);
	if (dir[0] != 0)
		w = (p[0] + t2 * v[0] - center[0]) / dir[0];
	else if (dir[1] != 0)
		w = (p[1] + t2 * v[1] - center[1]) / dir[1];
	else if (dir[2] != 0)
		w = (p[2] + t2 * v[2] - center[2]) / dir[2];
	//printf("w2: %f\n", w);
	//if (w <= 0)
	//	w *= -1;
	if (w <= height)
		return (1);
	return (0);
}



*/

float	plane_straight_inters(float *plane, float *v, float *p)
{
	float	t;

	t = - (plane[0] * p[0] + plane[1] * p[1] + plane[2] * p[2] + plane[3]) / (plane[0] * v[0] + plane[1] * v[1] + plane[2] * v[2]);
	return (t);
}

float	point_point_distance(float *p, float *q)
{
	float	*ab;

	ab = subs_vec(p, q);
	return (sqrt(ab[0] * ab[0] + ab[1] * ab[1] + ab[2] * ab[2]));
}


/*
int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{
	float	*plane;
	float	*neo_center;
	float	*neo_plane;
	float	t;
	float	neo_t;
	float	*point;
	float	*neo_point;
	float	*ab;

	neo_center = ft_calloc(3, sizeof(float));
	point = ft_calloc(3, sizeof(float));
	neo_point = ft_calloc(3, sizeof(float));
	neo_center[0] = center[0] + height * dir[0];
	neo_center[1] = center[1] + height * dir[1];
	neo_center[2] = center[2] + height * dir[2];
	plane = plane_equation(dir, center);
	neo_plane = plane_equation(dir, neo_center);
	t = plane_straight_inters(plane, v, p);
	neo_t = plane_straight_inters(neo_plane, v, p);
	point[0] = p[0] + v[0] * t;
	point[1] = p[1] + v[1] * t;
	point[2] = p[2] + v[2] * t;
	

	neo_point[0] = p[0] + v[0] * neo_t;
	neo_point[1] = p[1] + v[1] * neo_t;
	neo_point[2] = p[2] + v[2] * neo_t;
	ab = subs_vec(point, neo_point);
	if (cylinder(ab, p, dir, center) <= radius)
		return (1);
	return (0);
}
*/
/*
float *system_two(float *x, float *y) {
    float a = x[0];
    float b = x[1];
    float c = x[2];
    float d = y[0];
    float e = y[1];
    float f = y[2];
    float det = a*e - b*d;  // calcula el determinante

    if (det == 0) {
        printf("El sistema no tiene solución única\n");
        return NULL;
    } else {
        float *soluciones = malloc(2 * sizeof(float));
        soluciones[0] = (c*e - b*f) / det;
        soluciones[1] = (a*f - c*d) / det;
        return soluciones;
    }
}
*/
float	*obtain_b(float *dir)//, float *mid, float r)
{
	float	*b;
	float	*ox;

	ox = ft_calloc(3, sizeof(float));
	ox[0] = 1;
	ox[1] = 1;
	ox[2] = 1;
	b = vectorial_prod(ox, dir);
	return (b);
}

int	check_perpendicular(float *dir, int ref)
{
	float	*axis;

	axis = ft_calloc(3, sizeof(float));
	if (ref == 0)
	{
		axis[0] = 1;
		axis[1] = 0;
		axis[2] = 0;
	}
	else if (ref == 1)
	{
		axis[0] = 0;
		axis[1] = 1;
		axis[2] = 0;
	}
	else if (ref == 2)
	{
		axis[0] = 0;
		axis[1] = 0;
		axis[2] = 1;
	}
	else 
		return (-1);
	if (escalar_prod(dir, axis) == 0)
		return (1);
	return (0);
}

int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{
	float	*mid_pixel;
	float	*b;
	float	*proj;
	float	*of_proj;
	float	mid[3];
	(void)p;
	(void)radius;

	/*
	mid[0] = center[0] + (height / 2) * dir[0];
	mid[1] = center[1] + (height / 2) * dir[1];
	mid[2] = center[2] + (height / 2) * dir[2];
	*/

	mid[0] = center[0] + (height / 2) * dir[0];
	mid[1] = center[1] + (height / 2) * dir[1];
	mid[2] = center[2] + (height / 2) * dir[2];

	mid_pixel = subs_vec(v, mid);
	//b = obtain_b(dir);
	b = ft_calloc(3, sizeof(float));
	b[0] = dir[0];
	b[1] = dir[1];
	b[2] = dir[2];
	normalize_vector(b);
	proj = ft_calloc(3, sizeof(float));
	proj[0] = (escalar_prod(mid_pixel, b) / escalar_prod(b, b)) * b[0];
	proj[1] = (escalar_prod(mid_pixel, b) / escalar_prod(b, b)) * b[1];
	proj[2] = (escalar_prod(mid_pixel, b) / escalar_prod(b, b)) * b[2];
	of_proj = proj;
	if (check_perpendicular(dir, 2) == 0)
		of_proj = subs_vec(proj, mid_pixel);
//	printf("-%f, %f, %f-\n", mid_pixel[0], mid_pixel[1], mid_pixel[2]);
	//printf("%f\n", vec_module(of_proj));
	if (vec_module(of_proj) > height / 2)
		return (0);
	return (1);
}
