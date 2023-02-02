/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:14:45 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/02 14:25:36 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	pixel_size(float lens_radius, float image_width)
{
	return (2.0 * lens_radius / image_width);
}
float	lens_radius(float fov_rad, float image_height)
{
	return (image_height / (2.0 * tan(fov_rad / 2.0)));
}
float	fov_rad(int FOV)
{
	return (FOV * M_PI / 180.0);
}
