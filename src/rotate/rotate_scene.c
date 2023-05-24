#include <miniRT.h>

t_vector	*obtain_y(t_vector	v)
{
	float		theta;
	int		i;
	t_vector	*matrix;

	i = 0;
	matrix = malloc(sizeof(t_vector) * 4);
	theta = atan2(-v.x, v.z);
	matrix[0].x = cos(theta);
	matrix[0].y = 0;
	matrix[0].z = sin(theta);
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[2].x = -sin(theta);
	matrix[2].y = 0;
	matrix[2].z = cos(theta);
	printf("--RY--\n");
	while (i < 3)
	{
		printf("%f    %f    %f\n", matrix[i].x, matrix[i].y, matrix[i].z);
		i++;
	}
	
	return (matrix);
}

t_vector	*obtain_x(t_vector v)
{
	float		phi;
	int		i;
	t_vector	*m;

	i = 0;
	m = malloc(sizeof(t_vector) * 4);
	phi = M_PI/2 - atan2(sqrt(v.x * v.x + v.z * v.z), v.y);
	m[0].x = 1;
	m[0].y = 0;
	m[0].z = 0;
	m[1].x = 0;
	m[1].y = cos(phi);
	m[1].z = -sin(phi);
	m[2].x = 0;
	m[2].y = sin(phi);
	m[2].z = cos(phi);
	printf("--RX--\n");
	while (i < 3)
	{
		printf("%f    %f    %f\n", m[i].x, m[i].y, m[i].z);
		i++;
	}

	return (m);
}

t_vector	rotate_yaxis(t_vector v)
{
	t_vector	*m;
	t_vector	t;

	m = malloc(sizeof(t_vector) * 3);
	m[0].x = cos(M_PI);
	m[0].y = 0;
	m[0].z = -sin(M_PI);
	m[1].x = 0;
	m[1].y = 1;
	m[1].z = 0;
	m[2].x = sin(M_PI);
	m[2].y = 0;
	m[2].z = cos(M_PI);
	t = matrix_vector_product(m, v);
	return (t);
}

void	rotate_camera(t_camera *C, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector aux;

	aux = subs_vector(v_gen(C->coord), v);
	aux  = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	vectoflo(C->coord, aux);
	printf("aux1: (%f, %f, %f)\n", aux.x, aux.y, aux.z);
	aux = matrix_vector_product(ry, v_gen(C->vec));
	aux = matrix_vector_product(rx, aux);
	aux = rotate_yaxis(aux);
	printf("aux2: (%f, %f, %f)\n", aux.x, aux.y, aux.z);
	vectoflo(C->vec, aux);
}

void	rotate_light(t_light *L, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector aux;

	aux = subs_vector(v_gen(L->coord), v);
	aux = matrix_vector_product(ry, aux);
	aux = matrix_vector_product(rx, aux);
	aux = rotate_yaxis(aux);
	vectoflo(L->coord, aux);
}

void	rotate_cylinder(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;
	t_list		*lst;
	t_cylinder	*cy;
	
	lst = *(t_list **)scene->cy;
	if (!scene->cy)
		return ;
	while (lst)
	{
		cy = (t_cylinder *) lst->content;
		aux = subs_vector(v_gen(cy->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(cy->coord, aux);
		aux = matrix_vector_product(ry, v_gen(cy->vec));
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(cy->vec, aux);
		lst = lst->next;
	}
}

void	rotate_sphere(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_list		*lst;
	t_sphere	*sp;
	t_vector	aux;
	
	if (!scene->sp)
		return ;
	lst = *(t_list**)scene->sp;
	while (lst)
	{
		sp = (t_sphere *)lst->content;
		aux = subs_vector(v_gen(sp->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(sp->coord, aux);
		lst = lst->next;
	}
}

void	rotate_plane(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v)
{
	t_vector	aux;
	t_list		*lst;
	t_plane		*pl;

	if (!scene->pl)
		return ;
	lst = *(t_list **)scene->pl;
	while (lst)
	{
		pl = (t_plane *)lst->content;
		aux = subs_vector(v_gen(pl->coord), v);
		aux = matrix_vector_product(ry, aux);
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(pl->coord, aux);
		aux = matrix_vector_product(ry, v_gen(pl->vec));
		aux = matrix_vector_product(rx, aux);
		aux = rotate_yaxis(aux);
		vectoflo(pl->vec, aux);
		lst = lst->next;
	}
}

int	check_camera(t_camera C)
{
	t_vector	v;

	v = v_gen(C.vec);
	if (v.x == 0 && v.y == 0 && v.z == -1)
		return (0);
	return (1);
}	

void	rotate_data(t_scene *scene, t_vector *ry, t_vector *rx, t_vector c)
{
	rotate_camera(&scene->C, ry, rx, c);
	rotate_light(&scene->L, ry, rx, c);
	rotate_cylinder(scene, ry, rx, c);
	rotate_sphere(scene, ry, rx, c);
	rotate_plane(scene, ry, rx, c);
}


void	rotate_scene(t_scene *scene)
{
	t_vector	*ry;
	t_vector	*rx;
	t_vector	c;
	t_vector	v;

	v = normalize(v_gen(scene->C.vec));
	vectoflo(scene->C.vec, v);
	if (check_camera(scene->C) == 0)
	{
		subs_camera(scene);
		return ;
	}
	c = v_gen(scene->C.coord);
	ry = obtain_y(normalize(v_gen(scene->C.vec)));
	rx = obtain_x(normalize(v_gen(scene->C.vec)));
	rotate_data(scene, ry, rx, c);
	free(ry);
	free(rx);
}
