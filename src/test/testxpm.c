/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/09 20:38:43 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	test_xpm(mlx_t* mlx)
{
	if (!mlx)
		return (-1);
	t_xpm*	xpm;
	xpm = new_xpm(mlx, "PRUEBAXPM");
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	//test_clrxpm
		//test new_clr() check if it's a new color for the xpm or not
	xpm->dfclr = rgbHex(255, 255, 255);
	char *nuevo = rgbHex(255, 255, 255);
	printf("DFCLR = %s %zu\nNUEVO = %s %zu\n", xpm->dfclr,ft_strlen(xpm->dfclr), nuevo, ft_strlen(nuevo));
	if (!new_clr(xpm, nuevo))
		printf("THE COLORS ARE THE SAME\n");
	else
		printf("THERE ARE DIFFERENTS COLORS\n");
	free(xpm->dfclr);
	free(nuevo);
	free(xpm);
	xpm = new_xpm(NULL, "Prebasjffsjlf");
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	xpm = new_xpm(mlx, NULL);
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	return (0);
}
int	test_clrxpm(t_xpm *xpm, char *rgb)
{
	if (!xpm || !rgb)
		return (-1);	
	return (0);
}
