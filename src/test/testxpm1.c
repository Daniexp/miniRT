/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxpm1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:08:11 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/23 13:17:43 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
# include <test.h>
# include <xpm.h>
void printxpm(t_xpm *xpm)
{
	printf("DFCLR:\n%s\nMAP:\n%s", xpm->dfclr, xpm->map);
}
int	test_addclrxpm(void)
{
	t_xpm xpm;
	xpm.inf.width = 5;
	xpm.inf.height = 5;
	xpm.inf.nclr = 0;
	xpm.inf.chpx = 1;
	xpm.inf.mode = 'A';
	xpm.dfclr = NULL;
	xpm.map = NULL;
	printf("El resultado de la funcion add_clr_xpm es: %d\n", add_clr_xpm(&xpm, "0xFFFFFFFF", 0, 0));
	printxpm(&xpm);
	printf("El resultado de la funcion add_clr_xpm es: %d\n", add_clr_xpm(&xpm, "0xFF00FFFF", xpm.inf.width - 1,xpm.inf.height - 1));
	printxpm(&xpm);
	printf("El resultado de la funcion add_clr_xpm es: %d\n", add_clr_xpm(&xpm, "0xFFFFFFFF", 0, 1));
	printxpm(&xpm);
	modify_dfclr(&xpm);
	modify_map(&xpm);
	xpm.inf.chpx++;
	printxpm(&xpm);
	return (0);
}
