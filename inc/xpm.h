/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:35:12 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/12 13:57:19 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H
# include <miniRT.h>
# define HEADERXPM42 "!XPM42"
# define RUTEIMAGES "img/"
# define BASEXPMCHR "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyz"
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
int		add_clr_xpm(t_xpm *xpm, char *rgb, int i, int j);
char*	fill_map(char *oldmap, char *src, int i, int j);
char*	modify_map(t_xpm *xpm);
/*	utils_xpm.c	*/
void	print_xpm(t_xpm *xpm);
int		exp_pow(int base, int res);
int		index_base(char chr, char *base);
int		convert_dec(char *nmb, char *base);
/*	colorxpm.c	*/
int		new_clr(t_xpm* xpm, char *rgb);
int		check_addclr(t_xpm *xpm);
char*	create_dfclr(char *lastdf, char *rgb);
char*	modify_dfclr(t_xpm *xpm);
//crear xpmfile
//guardar xpm
//modificar xpm
//	añadir color
#endif
