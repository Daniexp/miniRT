/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:17:56 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:20:49 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	subs_vector(t_vector v, t_vector u)
{
	t_vector	sol;

	sol.x = v.x - u.x;
	sol.y = v.y - u.y;
	sol.z = v.z - u.z;
	return (sol);
}

t_vector	add_vector(t_vector v, t_vector u)
{
	t_vector	sol;

	sol.x = v.x + u.x;
	sol.y = v.y + u.y;
	sol.z = v.z + u.z;
	return (sol);
}

t_vector	v_gen(float *v)
{
	t_vector	sol;

	sol.x = v[0];
	sol.y = v[1];
	sol.z = v[2];
	return (sol);
}

t_vector	normalize(t_vector v)
{
	t_vector	norm;
	float		mod;

	mod = vector_module(v);
	norm.x = v.x / mod;
	norm.y = v.y / mod;
	norm.z = v.z / mod;
	return (norm);
}

float	*gen_v(t_vector tuk)
{
	float	*sol;

	sol = (float *) ft_calloc(3, sizeof(float));
	sol[0] = tuk.x;
	sol[1] = tuk.y;
	sol[2] = tuk.z;
	return (sol);
}
