/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:16:14 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:04:39 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>
#include <intersection.h>

void	free_res_shadow(t_inters *inter);

unsigned int	*get_pxclr(float *ambclr, float *difclr)
{
	int		i;
	unsigned int	*px_clr;

	i = -1;
	px_clr = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
	while (++i < 3)
			px_clr[i] = round((ambclr[i] + difclr[i]));
	return (px_clr);
}

float	*zero_dif(void)
{
	float	*dif;

	dif = (float *) ft_calloc(sizeof(float), 3);
	dif[0] = 0;
	dif[1] = 0;
	dif[2] = 0;
	return (dif);
}

unsigned int	*get_pnt_clr(t_inters *inters, t_scene *scene)
{
	unsigned int			*px_clr;

	if (!inters || !scene)
		return (NULL);
	if (inters->type == SPHERE)
		px_clr = color_sphere(inters, scene);
	else if (inters->type == PLANE)
		px_clr = color_plane(inters, scene);
	else if (inters->type == CYLINDER)
		px_clr = color_cylinder(inters, scene);
	else
		nothing(scene);
	return (px_clr);
}
