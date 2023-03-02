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

/*
int intersect_ray_cylinder(float *v, float *p,  float *dir, float *center, float radius, float height)
{*/
