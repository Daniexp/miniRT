/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/14 17:27:44 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <xpm.h>

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
	char *df = ft_strjoin("5 ", xpm->dfclr);
	free(xpm->dfclr);
	xpm->dfclr = df;
	char *nuevo = rgbHex(255, 255, 255);
	printf("DFCLR = %s %zu\nNUEVO = %s %zu\n", xpm->dfclr,ft_strlen(xpm->dfclr), nuevo, ft_strlen(nuevo));
	if (!new_clr(xpm, nuevo))
		printf("THE COLORS ARE THE SAME\n");
	else
		printf("THERE ARE DIFFERENTS COLORS\n");
	printf("TESTS MODIFY_DFLCLR()\n");
	printf("Nueva def: essss-->: %s\n", modify_dfclr(xpm));
	printf("------------\n");
	printf("xpm inf chpx: %d\n " , xpm->inf.chpx);
	char* nuevo_color = create_dfclr(xpm, xpm->dfclr, nuevo);
	printf("EL NUEVO  COLOR TRAS CREATE_DFCLR ES : %s\n", nuevo_color);
	free(nuevo_color);
	printf("------------\n");
	free(xpm->dfclr);
	free(nuevo);
	free(xpm);
	xpm = new_xpm(NULL, "Prebasjffsjlf");
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	xpm = new_xpm(mlx, NULL);
	if (!xpm)
		printf("NO HA SIDO POSIBLE GUARDAR LOS DATOS DEL XPM\n");
	test_indexbase();
	return (0);
}
int test_indexbase(void)
{
	//test index_base() que dado una base númerica y un str que representa un número en esta base
	//calcular su correspondiente en base decimal
	char *base;
	char *prueba;
	base = ft_substr("abcdefg", 0, 7);
	prueba = ft_substr("gfedcbaz", 0, 8);
	if (!base || !prueba)
		return (-1);
	char *aux;
	aux = prueba;
	while (*aux)
	{
		printf("%c esta en la pos: %d de %s\n", *aux, index_base(*aux, base), base); 
		aux++;
	}
	free(base);
	free(prueba);
	printf("---------------\n");
	printf("TEST CONVERT_DEC\n");
	base = ft_substr("0123456789ABCDEF", 0, 16);
	prueba = ft_substr("A0", 0, 2);
	printf("%s según la base %s, corresponde a %d en decimal.\n", prueba, base, convert_dec(prueba, base));
	free(prueba);
	prueba = ft_substr("100", 0, 3);
	printf("%s según la base %s, corresponde a %d en decimal.\n", prueba, base, convert_dec(prueba, base));
	free(prueba);
	prueba = ft_substr("400", 0, 3);
	printf("%s según la base %s, corresponde a %d en decimal.\n", prueba, base, convert_dec(prueba, base));
	free(prueba);
	prueba = ft_substr("D0", 0, 2);
	printf("%s según la base %s, corresponde a %d en decimal.\n", prueba, base, convert_dec(prueba, base));
	free(prueba);
	prueba = ft_substr("A", 0, 1);
	printf("%s según la base %s, corresponde a %d en decimal.\n", prueba, BASEXPMCHR, convert_dec(prueba, BASEXPMCHR));
	free(prueba);
	free(base);
	return (0);
}
int	test_clrxpm(t_xpm *xpm, char *rgb)
{
	if (!xpm || !rgb)
		return (-1);	
	return (0);
}
