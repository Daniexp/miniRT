/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:21 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 22:15:25 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# define NOTYPE		3
# define SPHERE		0
# define PLANE		1
# define CYLINDER	2
# include <miniRT.h>

typedef struct s_intersection
{
	int			type;
	void		*obj;
	float		*point;
	float		*vector;
	float		*rgb;
	t_cylinder	*cy;
	float		len_c;
	float		len_l;
	int			shadow;
}	t_inters;
/*	sphere.c	*/
float		*sect_sphere(float *vector, float *camera, float *sphere,
				float sphere_radius);
float		*sp_normal(t_sphere *sp, float *p);
/*	plane.c		*/
float		*pl_equation(float *point, float *normal);
//float	*ln_equation(float *point, float *vector);
float		*sect_plane(float *vector, t_camera *C, t_plane *pl);
/*	vector.c	*/
int			print_inters(t_inters *data);
t_inters	*get_intersection(float *vector, t_scene *scene);
int			srchsphere_inters(t_inters *data, t_scene *scene);
int			srchplane_inters(t_inters *data, t_scene *scene);
float		distance_inters(float *vector, float *camera);
t_vector	plane_straight_inter(t_vector s,
				t_vector p, t_vector normal, t_vector pplane);
int			is_pixel_incylinder(float *v, float *p, t_scene *scene);
t_vector	normal_cylinder(t_vector in, t_vector v,
				t_scene *scene, t_inters *inter);
t_vector	cy_inter(float *v, float *p, t_scene *scene);
float		dot_dot_distance(t_vector p, t_vector q);
int			srchcylinder_inters(t_inters *data, t_scene *scene);
t_vector	obtain_mid_point(float *v, float *p, t_scene *scene);
float		*cy_bases(float *v, float *p, t_scene *scene);
int			check_cy_bases(float *v, float *p, t_scene *scene);
float		subs_in_plane(t_util_plane plane, t_vector p);
t_vector	invert(t_vector a);
float		*cylinder(t_vector v, t_scene *scene, t_cylinder *cy);
float		*normal_plane(t_scene *scene, t_inters *res);
float		*the_bases_i(t_vector v, t_scene *scene, t_cylinder *cy);
float		*the_bases_ii(t_vector v, t_scene *scene, t_cylinder *cy);
int			isinscreen(float *in, t_scene *scene);
float		*cylinder_return(t_vector v, t_scene *scene,
				t_cylinder *cy, t_vector inter);
float		*fdup(float *v);

#endif
