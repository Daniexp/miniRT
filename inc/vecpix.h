#include <miniRT.h>

float	*screen_center(float camera[3], float v_u[3], float alpha, float weidth);
float	coor_x(int i, int j, float weidht);
float	coor_y(int i, int j, float weidht);
float	*add_vec(float v1[3], float v2[3]);
float	*generate_3dvec(float x, float y);
float	*sect_sphere(float *vector, float *camera, float *sphere, float sphere_radius);
float	lens_radius(float alpha, float weidth);
float	*vectorial_prod(float  v1[3], float v2[3]);
float	*normal_vector(float v1[3]);
float	*modtouni(float *uni, float mod);
float	escalar_prod(float v1[3], float v3[3]);
float	*plane_ecuation(float v1[3], float v2[3]);
float	ctorad(float alpa);
float	v_angle(float v1[3], float v2[3]);
float	**matrix_prod(float **m1, float **m2);
float	*subs_vec(float v1[3], float v2[3]);
float	*add_vec(float v1[3], float v2[3]);
float	*plane_ecuation(float n[3], float p[3]);
float	*v_from_plane(float *p, int r);
