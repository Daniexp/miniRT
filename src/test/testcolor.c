/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:18 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/24 13:13:18 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <test.h>

void	test_cmbclr(void)
{
	unsigned int	*clr1;
	unsigned int	*clr2;
	clr1 = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
	clr2 = (unsigned int *) ft_calloc(3, sizeof(unsigned int));
	clr1[0] = 0;
	clr1[2] = 255;
	clr1[1] = 255;
	clr2[0] = 255;
	clr2[1] = 255;
	clr2[2] = 0;
	combine_clrs(clr1, clr2);
}
