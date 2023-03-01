/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:15 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/01 13:42:46 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

char	*combine_clrs(unsigned int *clr1, unsigned int *clr2)
{
	int		*res;
	char	*hex;
	int		i;

	if (!clr1 || !clr2)
		return (NULL);
	res = ft_calloc(3, sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < 3)
		res[i] = (int) roundl((clr1[i] + clr2[i]) / 2);
	hex = rgbhex(res[0], res[1], res[2]);
	free(res);
	printf("HEX: %s\n", hex);
	return (hex);
}

unsigned int	*rgb_combine_clrs(unsigned int *clr1, int a1,
		unsigned int *clr2, int a2)
{
	unsigned int	*res;

	if (!clr1 || !clr2 || a1 < 0 || a2 < 0)
		return (NULL);
	res = ft_calloc(4, sizeof(unsigned int));
	if (!res)
		return (NULL);
	res[3] = 255 - (255 - a2) * (255 - a1);
	res[0] = clr2[0] * a2 / res[3] + clr1[0] * a1 * (255 - a2) / res[3];
	res[1] = clr2[1] * a2 / res[3] + clr1[1] * a1 * (255 - a2) / res[3];
	res[2] = clr2[2] * a2 / res[3] + clr1[2] * a1 * (255 - a2) / res[3];
	return (res);
}

uint32_t	combine_clrs_mlx(unsigned int *clr1, int a1, unsigned int *clr2, int a2)
{
	uint32_t				sol;
	unsigned int			*res;
	int						i;

	if (!clr1 || !clr2 || a1 < 0 || a2 < 0)
		return (0);
	res = ft_calloc(3, sizeof(float));
	i = -1;
	while (++i < 3)
		res[i] = roundl((clr1[i] + clr2[i]) / 2);
//	res = rgb_combine_clrs(clr1, a1, clr2, a2);
	if (!res)
		return (0);
//	sol = get_rgba(res[0], res[1], res[2], res[3]);
	sol = get_rgba(res[0], res[1], res[2], 255);
	free(res);
	return (sol);
}
