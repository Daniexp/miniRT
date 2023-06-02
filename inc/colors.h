/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:38:03 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 20:21:06 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define KDNOTYPE 0.0
# define KANOTYPE 0.0

# define KDSPHERE 1.0
# define KASPHERE 1.0

# define KDPLANE 1.0
# define KAPLANE 1.0

# define KDCYLINDER 1.0
# define KACYLINDER 1.0

# include <miniRT.h>
# include <math.h>

typedef struct	s_phong_params
{
	t_light		*light;
	t_ambient	*ambient;
	float		*point;
	float		*N;
	float		kd;
	float		ka;
	unsigned int	*rgb;
	int		shadow;
} t_phong;

/*	rf_ambient.c	*/
int					get_rgba(int r, int g, int b, int a);
float				*ambientcolor(t_ambient *A, float ka);
char				*change_base(int nmb, char *base);
char				*rgbhex(int r, int g, int b);
/*	rf_difuse.c		*/
float				*get_vector_light(t_light *L, float *inters_coord);
float				*difuse_color(t_light *L, float *p, float *N, float kd,
		unsigned int *rgb);
/*	colors.c		*/
int					get_r(int rgba);
int					get_b(int rgba);
int					get_a(int rgba);
unsigned int		*rgb_combine_clrs(unsigned int *clr1, int a1,
		unsigned int *clr2, int a2);
uint32_t			combine_clrs_mlx(unsigned int *clr1, int a1,
		unsigned int *clr2, int a2);
/*	phong.c			*/
unsigned int		*get_pnt_clr(t_inters *inters, t_scene *scene);
#endif
