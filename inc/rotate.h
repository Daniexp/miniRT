#ifndef ROTATE_H
#define ROTATE_H

void		rotate_scene(t_scene *scene);
t_vector	matrix_vector_product(t_vector *matrix, t_vector v);
void		vectoflo(float f[3], t_vector v);
void		subs_camera(t_scene *scene);

#endif
