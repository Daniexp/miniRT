/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:35:12 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/09 15:22:40 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H
# include <miniRT.h>
# define HEADERXPM42 "!XPM42"
# define RUTEIMAGES "img/"
typedef struct	s_xpm_general_info
{
	int	width;
	int	height;
	int	nclr;
	int	chpx;
	char mode;
}	t_xpm_inf;
typedef struct	s_primitive_xpm_file
{
	char*		name;
	t_xpm_inf	inf;
	char		*dfclr;
	char		*map;
}	t_xpm;
/*	xmp.c	*/
char*	file_xpm( void );
t_xpm*	new_xpm(mlx_t *mlx, char *name);
int		add_color(int i, int j);
//crear xpmfile
//guardar xpm
//modificar xpm
//	añadir color
#endif
