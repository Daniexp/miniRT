/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:10:58 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 11:52:08 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
typedef struct s_camera
{
	float			coord[3];
	float			vec[3];
	unsigned int	fov;
	
}	t_camera;

typedef struct s_ambient_light
{
	float	rate;
	unsigned int	rgb[3];
}	t_ambient;

# include <libft.h>
# include <MLX42.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <test.h>
# include <intersection.h>
# include <MLX42.h>
# include <pixel.h>
# include <colors.h>
# include <xpm.h>
# include <utils.h>
/*	STRUCTURES	*/
typedef struct s_light
{
	float			coord[3];
	float	rate;
}	t_light;

typedef struct s_sphere
{
	float			coord[3];
	float 	d;
	unsigned int	rgb[3];
}	t_sphere;

typedef struct s_plane
{
	float			coord[3];
	float			vec[3];
	unsigned int	rgb[3];
}	t_plane;

typedef struct s_cylinder
{
	float			coord[3];
	float			vec[3];
	float	d;
	float	h;
	unsigned int	rgb[3];
}	t_cylinder;

typedef struct	s_scene
{
	t_list**	sp;
	t_list**	cy;
	t_list**	pl;
	t_light		L;
	t_camera	C;
	t_ambient	A;
	int		n_A;
	int		n_C;
	int		n_L;
	int		n_sp;
	int		n_pl;
	int		n_cy;
}	t_scene;
# include <parse.h>
#endif
