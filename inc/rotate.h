#ifndef ROTATE_H
#define ROTATE_H

void		rotate_scene(t_scene *scene);
t_vector	matrix_vector_product(t_vector *matrix, t_vector v);
void		vectoflo(float f[3], t_vector v);
void		subs_camera(t_scene *scene);
void		rotate_camera(t_camera *C, t_vector *ry, t_vector *rx, t_vector v);
void		rotate_light(t_light *L, t_vector *ry, t_vector *rx, t_vector v);
void		rotate_cylinder(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v);
void		rotate_plane(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v);
void		rotate_sphere(t_scene *scene, t_vector *ry, t_vector *rx, t_vector v);
t_vector	rotate_yaxis(t_vector v);
t_vector	*obtain_y(t_vector v);
t_vector	*obtain_x(t_vector v);
int			check_camera(t_camera C);

#endif
