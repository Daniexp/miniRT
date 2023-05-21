#include <miniRT.h>

t_vector	*obtain_y(t_vector	v)
{
	float		theta;
	t_vector	*matrix;

	matrix = malloc(sizeof(t_vector) * 4);
	theta = atan2(v.x, v.z);
	matrix[0].x = cos(theta);
	matrix[0].y = 0;
	matrix[0].z = -sin(theta);
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[2].x = sin(theta);
	matrix[2].y = 0;
	matrix[2].z = cos(theta);
	return (matrix);
}

t_vector	*obtain_x(t_vector v)
{
	float		phi;
	t_vector	*m;

	m = malloc(sizeof(t_vector) * 4);
	phi = acos(v.y / sqrt(v.x * v.x + v.y * v.y + v.z * v.z)) - M_PI/2;
	m[0].x = 1;
	m[0].y = 0;
	m[0].z = 0;
	m[1].x = 0;
	m[1].y = cos(phi);
	m[1].z = -sin(phi);
	m[2].x = 0;
	m[2].y = sin(phi);
	m[2].z = cos(phi);
	return (m);
}

void	rotate_camera(t_camera *C, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector aux;

	aux = subs_vector(v_gen(C->coord), v);
	aux  = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	vectoflo(C->coord, aux);
	aux = matrix_vector_product(ry, v_gen(C->vec));
	aux = matrix_vector_product(rx, aux);
	vectoflo(C->vec, aux);
}

void	rotate_light(t_light *L, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector aux;

	aux = subs_vector(v_gen(L->coord), v);
	aux = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	vectoflo(L->coord, aux);
}

void	rotate_cylinder(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;
	t_list		*lst;
	t_cylinder	*cy;

	lst = *(t_list **)scene->cy;
	cy = (t_cylinder *) lst->content;
	aux = subs_vector(v_gen(cy->coord), v);
	aux = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	vectoflo(cy->coord, aux);
	aux = matrix_vector_product(ry, v_gen(cy->vec));
	aux = matrix_vector_product(rx, aux);
	vectoflo(cy->vec, aux);
}

int	check_camera(t_camera C)
{
	t_vector	v;

	v = v_gen(C.vec);
	if (v.x == 0 && v.y == 0 && v.z == -1)
		return (0);
	return (1);
}	

void	rotate_scene(t_scene *scene)
{
	t_vector	*ry;
	t_vector	*rx;
	t_vector	c;

	if (check_camera(scene->C) == 0)
	{
		subs_camera(scene);
		return ;
	}
	c = v_gen(scene->C.coord);
	ry = obtain_y(v_gen(scene->C.vec));
	rx = obtain_x(v_gen(scene->C.vec));
	rotate_camera(&scene->C, ry, rx, c);
	rotate_light(&scene->L, ry, rx, c);
	rotate_cylinder(scene, ry, rx, c);
	free(ry);
	free(rx);
}
