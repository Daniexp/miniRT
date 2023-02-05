/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:35:12 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/05 19:06:20 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H
# include <miniRT.h>
# define HEADERXPM42 "!XPM42"
typedef struct	s_primitive_xpm_file
{
	char*	name;
	int		width;
	int		height;
	int		nclr;
	char	*dfclr;
	char	*map;
}	t_xpm;
/*	xmp.c	*/
char*	file_xpm( void );
t_xpm*	new_xpm( void );
int		add_color(int i, int j);
//crear xpmfile
//guardar xpm
//modificar xpm
//	añadir color
#endif
