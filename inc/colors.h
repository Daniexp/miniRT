/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:38:03 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/23 13:15:10 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# include <miniRT.h>
# include <math.h>

typedef struct	s_difuse_params
{
	t_light		*light;
	float		*point;
	float		*N;
	float		kd;
	unsigned int	rgb;
	int		shadow;
} t_difuse;

/*	rf_ambient.c	*/
int					get_rgba(int r, int g, int b, int a);
float				*ambientcolor(t_ambient *A, float ka);
char				*change_base(int nmb, char *base);
char				*rgbhex(int r, int g, int b);
/*	rf_difuse.c		*/
float				*get_vector_light(t_light *L, float *inters_coord);
float				*difuse_color(t_light *L, float *p, float *N, float kd,
		unsigned int *rgb);
float				*difuse_shadow(t_inters *inters,
		t_scene *scene);
t_difuse			*get_difuse_params(t_inters *inters, t_scene *scene);
/*	colors.c		*/
int					get_r(int rgba);
int					get_b(int rgba);
int					get_a(int rgba);
char				*combine_clrs(unsigned int *clr1, unsigned int *clr2);
unsigned int		*rgb_combine_clrs(unsigned int *clr1, int a1,
		unsigned int *clr2, int a2);
uint32_t			combine_clrs_mlx(unsigned int *clr1, int a1,
		unsigned int *clr2, int a2);
/*	phong.c			*/
unsigned int		*get_pnt_clr(t_inters *inters, t_scene *scene);
#endif
