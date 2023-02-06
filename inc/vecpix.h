#include <miniRT.h>

float	*screen_center(float camera[3], float v_u[3], float alpha, float weidth);
int	coor_x(int i, int j, float weidht);
int	coor_y(int i, int j, float weidht);
float	*add_vec(float v1[3], float v2[3]);
float	*generate_3dvec(float x, float y);
float	*sect_sphere(float *vector, float *camera, float *sphere, float sphere_radius);
float	lens_radius(float alpha, float weidth);
