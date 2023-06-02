/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calculus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:20:05 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:20:17 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	mult_k(t_vector v, float k)
{
	t_vector	v2;

	v2.x = v.x * k;
	v2.y = v.y * k;
	v2.z = v.z * k;
	return (v2);
}

float	dotprod(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	crossprod(t_vector u, t_vector v)
{
	t_vector	sol;

	sol.x = u.y * v.z - u.z * v.y;
	sol.y = -1 * (u.x * v.z - u.z * v.x);
	sol.z = u.x * v.y - u.y * v.x;
	return (sol);
}

float	vector_module(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
