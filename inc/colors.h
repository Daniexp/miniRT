/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:38:03 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/24 13:17:04 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# include <miniRT.h>
/*	rf_ambient.c	*/
int	get_rgba(int r,int g,int b, int a);
int	ambientColor(t_ambient* A);
char	*change_base(int nmb, char *base);
char	*rgbHex(int r, int g, int b);
/*	colors.c		*/
int		get_r(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);
char	*combine_clrs(unsigned int *clr1, unsigned int *clr2);
uint32_t	combine_clrs_mlx(unsigned int *clr1, unsigned int *clr2);
#endif
