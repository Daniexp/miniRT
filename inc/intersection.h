/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:21 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 13:07:33 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include <miniRT.h>
/*	sphere.c	*/
float	*sect_sphere(float* vector, float* camera, float *sphere, float sphere_radius);
void	paint_cylinder(float ***sv, mlx_image_t *img);
float	***vec_space_camera(float *camera_screen, float weidth, float height);
float	*cylinder_intersec(float *v, float *center, float *dir, float radius);
float	escalar_prod(float v1[3], float v2[3]);

# endif
