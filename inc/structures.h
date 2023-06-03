/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:13:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 17:46:03 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <unistd.h>
# include <libft.h>
# include <sys/stat.h>
# include <string.h>
# include <math.h>
# include <float.h>

/*	STRUCTURES	*/
typedef struct s_plane
{
	float			coord[3];
	float			vec[3];
	unsigned int	rgb[3];
	int				shthis;
}	t_plane;

typedef struct s_cylinder
{
	float			coord[3];
	float			vec[3];
	float			d;
	float			h;
	unsigned int	rgb[3];
	int				shthis;
}	t_cylinder;

typedef struct s_camera
{
	float			coord[3];
	float			vec[3];
	unsigned int	fov;
}	t_camera;

typedef struct s_ambient_light
{
	float			rate;
	unsigned int	rgb[3];
}	t_ambient;

typedef struct s_light
{
	float			coord[3];
	float			rate;
}	t_light;

typedef struct s_sphere
{
	float			coord[3];
	float			d;
	unsigned int	rgb[3];
	int				shthis;
}	t_sphere;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	null;
}	t_vector;

typedef struct s_util_plane
{
	float	a;
	float	b;
	float	c;
	float	d;
}	t_util_plane;

typedef struct s_scene
{
	t_list		**sp;
	t_list		**cy;
	t_list		**pl;
	t_light		l;
	t_camera	c;
	t_ambient	a;
	int			n_a;
	int			n_c;
	int			n_l;
	int			n_sp;
	int			n_pl;
	int			n_cy;
	int			exit;
}	t_scene;
#endif
