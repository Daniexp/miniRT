/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:20:28 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 15:21:24 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <miniRT.h>

t_util_plane	pleq(t_vector n, t_vector p);
float			dotprod(t_vector v1, t_vector v2);
float			vector_module(t_vector v);
float			dot_straight_distance(t_vector s, t_vector p, t_vector dot);
float			plane_dot_distance(t_vector dot, t_vector n, t_vector pplane);
t_vector		mult_k(t_vector	v, float k);
t_vector		crossprod(t_vector u, t_vector v);
t_vector		subs_vector(t_vector v, t_vector u);
t_vector		add_vector(t_vector v, t_vector u);
t_vector		v_gen(float *v);
t_vector		normalize(t_vector v);
t_vector		compare(t_vector u, t_vector v, t_scene *scene);
float			*gen_v(t_vector tuk);

#endif
