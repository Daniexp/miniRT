#include <miniRT.h>

#include <math.h>

int intersect_ray_cylinder(float *ray_origin, float *ray_direction, float *cylinder_center, float cylinder_radius, float cylinder_height, float *t)
{
    // Calcula los coeficientes del sistema de ecuaciones lineales
    float a = ray_direction[0]*ray_direction[0] + ray_direction[1]*ray_direction[1];
    float b = 2*(ray_direction[0]*(ray_origin[0]-cylinder_center[0]) +
                  ray_direction[1]*(ray_origin[1]-cylinder_center[1]));
    float c = (ray_origin[0]-cylinder_center[0])*(ray_origin[0]-cylinder_center[0]) +
               (ray_origin[1]-cylinder_center[1])*(ray_origin[1]-cylinder_center[1]) -
               cylinder_radius*cylinder_radius;

    // Calcula la discriminante del sistema de ecuaciones lineales
    float discriminant = b*b - 4*a*c;

    // Si la discriminante es negativa, la recta no intersecta el cilindro
    if (discriminant < 0)
	{
		printf("NO INTERSECTA\n");
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
        return 0;
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

