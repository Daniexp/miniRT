/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_calculus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:28:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:29:01 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_util_plane	pleq(t_vector n, t_vector p)
{
	t_util_plane	plane;
	float			d;

	d = -1 * (n.x * p.x + n.y * p.y + n.z * p.z);
	plane.a = n.x;
	plane.b = n.y;
	plane.c = n.z;
	plane.d = d;
	return (plane);
}
