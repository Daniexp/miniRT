/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:14:45 by dexposit          #+#    #+#             */
/*   Updated: 2023/05/26 13:17:20 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>


float	pixel_size(float lens_radius, float image_width, float fov_rad)
{
	return ((2.0 * lens_radius * tan(fov_rad / 2)) / image_width);
}

float	lens_radius(float fov_rad, float image_height)
{
	if (tan(fov_rad / 2) <= 0)
		return (-1 * image_height / 2.0 * (tan(fov_rad / 2.0)));
	return ((image_height / 2.0) * (tan(fov_rad / 2.0)));
}

float	fov_rad(int FOV)
{
	return (FOV * M_PI / 180.0);
}
