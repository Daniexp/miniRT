#ifndef	VECTOR_H
# define VECTOR_H

# include <miniRT.h>

t_vector	mult_k(t_vector	v, float k);
float		dotprod(t_vector v1, t_vector v2);
t_vector	crossprod(t_vector u, t_vector v);
t_vector	subs_vector(t_vector v, t_vector u);
float		vector_module(t_vector v);
t_vector	add_vector(t_vector v, t_vector u);
t_vector	v_gen(float *v);
t_vector	normalize(t_vector v);
t_util_plane	pleq(t_vector n, t_vector p);
float		dot_straight_distance(t_vector s, t_vector p, t_vector dot);
float		plane_dot_distance(t_vector dot, t_vector n, t_vector pplane);
float		*gen_v(t_vector tuk);
t_vector	compare(t_vector u, t_vector v, t_scene *scene);


#endif
