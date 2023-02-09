/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/09 15:36:05 by dexposit         ###   ########.fr       */
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
	free(xpm);
	xpm = new_xpm(NULL, "Prebasjffsjlf");
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	xpm = new_xpm(mlx, NULL);
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	return (0);
}
