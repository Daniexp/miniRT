/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:21 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/28 09:39:12 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include <miniRT.h>

/*	sphere.c	*/
float	*sect_sphere(float *vector, float *camera, float *sphere,
			float sphere_radius);
float	*sp_normal(t_sphere *sp, float *p);
#endif
