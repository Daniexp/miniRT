/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:35:12 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/02 17:53:01 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H
# include <miniRT.h>
# define HEADERXPM42 "!XPM42"
# define RUTEIMAGES "img/"
# define BASEXPMCHR "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ\
	abcdefghijklmnñopqrstuvwxyz"

typedef struct s_xpm_general_info
{
	int		width;
	int		height;
	int		nclr;
	int		chpx;
	char	mode;
}	t_xpm_inf;
typedef struct s_primitive_xpm_file
{
	char		*name;
	t_xpm_inf	inf;
	char		*dfclr;
	char		*map;
}	t_xpm;
/*	xmp.c	*/
t_xpm	*create_xpm(mlx_t *mlx, t_scene *scene, char *filename);
t_xpm	*new_xpm(mlx_t *mlx, char *name);
int		add_clr_xpm(t_xpm *xpm, char *rgb, int i, int j);
/*	utils_xpm.c	*/
void	print_xpm(t_xpm *xpm);
int		exp_pow(int base, int res);
int		index_base(char chr, char *base);
int		convert_dec(char *nmb, char *base);
char	*ft_strnjoin(char chr, char *src, int times);
/*	utils1_xpm.c	*/
void	split_free(char **split);
/*	addclr_utils.c	*/
char	*getclr_str(char *rgb, char *dfclr);
char	*first_clr(char *rgb, t_xpm *xpm);
char	*add_newclrdf(t_xpm *xpm, char *rgb);
/*	colorxpm.c	*/
int		new_clr(t_xpm *xpm, char *rgb);
int		check_addclr(t_xpm *xpm);
char	*create_dfclr(t_xpm *xpm, char *lastdf, char *rgb);
/*	modify_dfclr.c	*/
char	*iter_dfclr(char **splitdf, char *(*f)(char **, int));
char	*addfirstbase_dfclr(char **split, int ind);
char	*join_dfclr(char **split, int ind);
char	*joinstrfree(char *fst, char *scd);
char	*modify_dfclr(t_xpm *xpm);
/*	map_xpm.c	*/
int		init_map(t_xpm *xpm);
//int		init_map(t_xpm *xpm, char *src);
char	*modify_map(t_xpm *xpm);
char	*fill_map(t_xpm *xpm, char *chrclr, int i, int j);

#endif
