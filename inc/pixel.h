/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:16:45 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/03 19:03:02 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include <miniRT.h>
/*	px_sixe.c	*/
float	pixel_size(float lens_radius, float image_width);
float	lens_radius(float fov_rad, float image_height);
float	fov_rad(int FOV);
/*	vector.c	*/
float	image_x(int i, float image_width, float pixel_size);
float	image_y(int i, float image_height, float pixel_size);
float*	px_vector(float image_x, float image_y, float camera_x, float camera_y, float lens_radius);
float*	px_vec(float image_x, float image_y, t_camera* C, float lens_radius);
void	normalize_vector(float *vector);
#endif
