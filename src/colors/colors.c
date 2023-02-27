/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:15 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/27 09:48:35 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <colors.h>

int get_r(int rgba)
{
    // Move 3 bytes to the right and mask out the first byte.
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
    // Move 2 bytes to the right and mask out the first byte.
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
    // Move 1 byte to the right and mask out the first byte.
    return ((rgba >> 8) & 0xFF);
}
/*
 *	COMBINE_CLRS:
 *	CLR1 Y CLR2 SON LOS COLORES A COMBINAR con sus valorse de rgb de 0 a 255
 */
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
	hex = rgbHex(res[0], res[1], res[2]);
	free(res);
	printf("HEX: %s\n", hex);
	return (hex);
}

uint32_t	combine_clrs_mlx(unsigned int *clr1, unsigned int *clr2)
{
	int		*res;
	int		i;
	uint32_t sol;

	if (!clr1 || !clr2)
		return (0);
	res = ft_calloc(3, sizeof(float));
	i = -1;
	while (++i < 3)
		res[i] = roundl((clr1[i] + clr2[i]) / 2);
	sol = get_rgba(res[0], res[1], res[2], 255);
	free(res);
	return (sol);
}
