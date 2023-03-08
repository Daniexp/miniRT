/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:50:50 by ndonaire          #+#    #+#             */
/*   Updated: 2023/02/23 08:58:01 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

float	*vectorial_prod(float v1[3], float v2[3]);
float	*subs_vec(float v1[3], float v2[3]);
float	*add_vec(float v1[3], float v2[3]);
float	*system_two(float c1, float c2, float c3, float d1, float d2, float d3);
float	point_lane_distance(float *p, float *v, float *q);

#endif
