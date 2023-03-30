#include <miniRT.h>

float	*normal_cylinder(float *p, float *dir, float *center)
{
	float 	*v;
	float	*proj;
	float	*component;

	v = subs_vec(center, p);
	component = ft_calloc(3, sizeof(float));
	component[0] = escalar_prod(v, dir) * dir[0];
	component[1] = escalar_prod(v, dir) * dir[1];
	component[2] = escalar_prod(v, dir) * dir[2];
	proj = subs_vec(component, v);
	return (proj);
}

float *cylinder_ray_param(float *of_v, float *p, float *dir, float *q, float r)
{
	float	*v;
	float	a;
	float	b;
	float	c;
	float	*n_v;
	float	*n_u;
	float	*u;
	float	*t;

	v = ft_calloc(3, sizeof(float));
	u = ft_calloc(3, sizeof(float));
	v[0] = dir[0] * escalar_prod(of_v, dir);
	v[1] = dir[1] * escalar_prod(of_v, dir);
	v[2] = dir[2] * escalar_prod(of_v, dir);
	n_v = subs_vec(of_v, v);
	u[0] = dir[0] * escalar_prod(dir, subs_vec(p, q));
	u[1] = dir[1] * escalar_prod(dir, subs_vec(p, q));
	u[2] = dir[2] * escalar_prod(dir, subs_vec(p, q));
	n_u = subs_vec(u, subs_vec(p, q));
	a = escalar_prod(n_v, n_v);
	b = 2 * escalar_prod(n_v, n_u);
	c = escalar_prod(n_u, n_u) - pow(r, 2);
	t = ft_calloc(3, sizeof(float));
	t[0] = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	t[1] = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	return (t);
}



/*
float cylinder_lane_t(float *v, float *p, float *dir, float *q, float r) {
    float a = dir[0];
    float b = dir[1];
    float c = dir[2];
    float e = p[0] - q[0];
    float f = p[1] - q[1];
    float g = p[2] - q[2];
    float A = a*a + b*b + c*c;
    float B = 2*(a*e + b*f + c*g);
    float C = e*e + f*f + g*g - r*r;
    float D = B*B - 4*A*C;

    if (D < 0) {
        // La recta no intersecta el cilindro
        return -1;
    } else {
        // Encuentra los dos posibles valores de t
        float t1 = (-B - sqrt(D)) / (2*A);
        float t2 = (-B + sqrt(D)) / (2*A);
        
        // Encuentra los puntos de intersección
        float x1 = p[0] + t1*v[0];
        float y1 = p[1] + t1*v[1];
        float z1 = p[2] + t1*v[2];
        float x2 = p[0] + t2*v[0];
        float y2 = p[1] + t2*v[1];
        float z2 = p[2] + t2*v[2];

        // Elije el valor de t que corresponde al punto de intersección más cercano al origen
        float d1 = sqrt(x1*x1 + y1*y1 + z1*z1);
        float d2 = sqrt(x2*x2 + y2*y2 + z2*z2);
        if (d1 < d2) {
            return t1;
        } else {
            return t2;
        }
    }
}
*/

/*
float cylinder_lane_t(float *v, float *p, float *dir, float *q, float r) {
    float a = dir[0];
    float b = dir[1];
    float c = dir[2];
    float d = -(a*q[0] + b*q[1] + c*q[2]);
    float e = p[0] - q[0];
    float f = p[1] - q[1];
    float g = p[2] - q[2];
    float A = (b*v[1] + c*v[2])*(b*v[1] + c*v[2]) + (a*v[1] - b*v[0])*(a*v[1] - b*v[0]);
    float B = 2*((b*f + c*g)*(b*v[1] + c*v[2]) + (a*f - b*e)*(a*v[1] - b*v[0]));
    float C = (b*f + c*g)*(b*f + c*g) + (a*f - b*e)*(a*f - b*e) - r*r;
    float D = B*B - 4*A*C;
    (void)d;

    if (D < 0) {
        // La recta no intersecta el cilindro
        return -1;
    } else {
        // Encuentra los dos posibles valores de t
        float t1 = (-B - sqrt(D)) / (2*A);
        float t2 = (-B + sqrt(D)) / (2*A);
        float z1 = p[2] + t1*v[2];
        float z2 = p[2] + t2*v[2];

        // Elije el valor de t que corresponde al punto de intersección más cercano al origen
        if (z1 >= q[2] && z1 <= q[2]+dir[2]) {
            return t1;
        } else if (z2 >= q[2] && z2 <= q[2]+dir[2]) {
            return t2;
        } else {
            // La recta no intersecta el cilindro
            return -1;
        }
    }
}
*/

float	*ray_cylinder_intersection(float *v, float *p, float *dir, float *center, float r)
{
	float	a;
	float	b;
	float	c;
	float	*intersection;
	float	discriminante;
	float	t;
	float	t2;
	(void)t2;

	/*
	a = pow(dir[0], 2) * pow(v[0], 2) + pow(dir[1], 2) * pow(v[1], 2) + pow(dir[2], 2) * pow(v[2], 2);
	b = 2 * (dir[0] * (center[0] - p[0]) * v[0] + dir[1] * (center[1] - p[1]) * v[1] + dir[2] * (center[2] - p[2]) * v[2] - dir[0] * v[0] * p[0] - dir[1] * v[1] * p[1] - dir[2] * v[2] * p[2] + dir[0] * v[0] * center[0] + dir[1] * v[1] * center[1] + dir[2] * v[2] * center[2]);
	c = (dir[0] * dir[0] * pow((p[0] - center[0]), 2) + dir[1] * dir[1] * pow((p[1] - center[1]),2) + dir[2] * dir[2] * pow((p[2] - center[2]),2) - 2 * dir[0] * dir[1] * (p[0] - center[0]) * (p[1] - center[1]) - 2 * dir[0] * dir[2] * (p[0] - center[0]) * (p[2] - center[2]) - 2 * dir[1] * dir[3] * (p[1] - center[1]) * (p[2] - center[2]));
	*/

	a = pow(dir[0], 2) + pow(dir[1], 2) + pow(dir[2], 2) - pow(r, 2) * (pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));

	b = 2 * (dir[0] * (center[0] - p[0]) * v[0] + dir[1] * (center[1] - p[1]) * v[1] + dir[2] * (center[2] - p[2]) * v[2]);

c = pow((p[0] - center[0]), 2) + pow((p[1] - center[1]), 2) + pow((p[2] - center[2]), 2) - pow(r, 2) - pow((dir[0] * (p[0] - center[0]) + dir[1] * (p[1] - center[1]) + dir[2] * (p[2] - center[2])), 2);

	discriminante = b * b - 4 * a * c;
	if (discriminante < 0)
		return (NULL);
	intersection = ft_calloc(3, sizeof(float));
	t = (-b + discriminante) / (2 * a);
	t2 = (-b - discriminante) / (2 * a);
	intersection[0] = p[0] + t * v[0];
	intersection[1] = p[1] + t * v[1];
	intersection[2] = p[2] + t * v[2];
	return (intersection);
}
