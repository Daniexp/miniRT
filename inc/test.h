/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:06 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/02 14:23:21 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <miniRT.h>
# include <MLX42.h>
typedef struct	s_hookparam
{
	mlx_t*			mlx;
	mlx_image_t*	img;
}	t_mlxdata;
/*	testsphere.c	*/
mlx_image_t*	imgWhite(mlx_t* mlx);
int				paint_sphere(const t_mlxdata* inf);
#endif
