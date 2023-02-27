/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:21 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/27 11:54:19 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include <miniRT.h>
/*	sphere.c	*/
float	*sect_sphere(float* vector, float* camera, float *sphere, float sphere_radius);
void	paint_cylinder(float ***sv, mlx_image_t *img);
float	***vec_space_camera(float *camera_screen, float weidth, float height);
//float	*cylinder_intersec(float *v, float *center, float *dir, float radius);
float	cylinder(float *v, float *p, float *dir, float *q);
float	escalar_prod(float v1[3], float v2[3]);
float	determinante(float **matrix);
float	cylinder_angle(float *v, float *center);
float	vec_module(float *v);
int		intersect_ray_cylinder(float *ray_origin, float *ray_direction, float *cylinder_center, float cylinder_radius, float cylinder_heightm, float *t);
# endif
