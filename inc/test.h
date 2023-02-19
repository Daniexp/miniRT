/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:06 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/19 17:09:16 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <miniRT.h>
# include <MLX42.h>
# include <xpm.h>
typedef struct	s_hookparam
{
	mlx_t*			mlx;
	mlx_image_t*	img;
}	t_mlxdata;
/*	testsphere.c	*/
mlx_image_t*	imgWhite(mlx_t* mlx);
int				paint_sphere(const t_mlxdata* inf);
/* testvector.c	*/
void			print_vector(float x, float y, float z);
void			test_vector(void);
/*	testxpm.c	*/
int				test_xpm(mlx_t* mlx);
int				test_clrxpm(t_xpm *xpm, char *rgb);
int				test_indexbase(void);
int				test_modifymap(void);
int				test_fillmap(void);
/*	testxpm1.c	*/
int				test_addclrxpm(void);
#endif
