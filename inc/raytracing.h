/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:39 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/03 18:26:23 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H
# include <miniRT.h>
# include <colors.h>
# include <intersection.h>

/*	raytracing.c	*/
mlx_image_t	*paint_img(mlx_t *mlx, t_scene *scene);
float		*get_vector(int i, int j, mlx_t *mlx, t_scene *scene);
#endif
