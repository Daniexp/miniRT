/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:21 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/06 13:10:26 by dexposit         ###   ########.fr       */
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
	float		len_c;
}	t_inters;
/*	sphere.c	*/
float	*sect_sphere(float *vector, float *camera, float *sphere,
			float sphere_radius);
float	*sp_normal(t_sphere *sp, float *p);
/*	plane.c		*/
float	*pl_equation(float *point, float *normal);
float	*sect_plane(float *vector, t_camera *C, t_plane *pl);
/*	vector.c	*/
int			print_inters(t_inters *data);
t_inters	*get_intersection(float *vector, t_scene *scene);
int			srchsphere_inters(t_inters *data, t_scene *scene);
float		distance_inters(float *vector, float *camera);
#endif
