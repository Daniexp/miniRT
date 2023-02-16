/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:06:56 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/16 16:55:02 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
# include <xpm.h>

/*	
 *	MODIFY MAP: 
 *	dado chrclr y las dimensione width y height de la imagen	
 * 	ej de mapa 
 * 	0 0xFFFFFFFF
 * 	00000\n
 * 	00000\n
 * 	     \n
 * 	00000
 * 	' ' para nosotros es no color
 * 	todos los colores
 *
 * 	iterar por el mapa dado el tamaño viejo (tener cuidado con los \n)
 * 		por cada substring de estos 
 * 			si es todo ' ' es un pixel vacío por lo que añadimos un espacio
 * 			si es la def de un color le añadimos el primer cáracter de la base
 * 		con todos los modificamos los unimos y reconstruimos map.
 */
/*	tested looks great	*/
char*	modify_map(t_xpm *xpm)
{
	int		i;
	int		j;
	char	**mapline;
	char	*clr;
	char	*aux;
	char	*res;

	if (!xpm || !xpm->map)
		return (NULL);
	mapline = ft_split(xpm->map, '\n');
	if (mapline)
	{
		free(xpm->map);
		xpm->map = NULL;
	}
	i = -1;
	while (mapline[++i])
	{
		res = NULL;
		clr = NULL;
		j = ft_strlen(mapline[i]);
		while (j >= 0)
		{
			if (mapline[i][j])
			{
				clr = ft_substr(mapline[i] + j, 0, xpm->inf.chpx);
	//			printf("i: %d j: %d clr{%s}\n", i, j, clr);
				if (clr)
				{
				//construimos la nueva def
					if (ft_strchr(clr, ' ') != NULL)
						aux = ft_strjoin(" ", clr);
					else
						aux = ft_strnjoin(BASEXPMCHR[0], clr, 1);
					free(clr);
					clr = aux;
				}
			}
			else
				clr = ft_substr("\n", 0 , 1);
			//empezamos unir lo anterior al nuevo def
			aux = res;
			if (aux)
			{
				res = ft_strjoin(clr, aux);
				free(aux);
			}
			else
				res = ft_substr(clr, 0, ft_strlen(clr));
			free(clr);		
			//comprobar clr con las definiciones de clr
			j -= xpm->inf.chpx;
		}
//res tiene una linea
		aux = xpm->map;
		if (!aux)
			xpm->map = ft_substr(res,0, ft_strlen(res)); 
		else
		{
			xpm->map = ft_strjoin(aux, res);
			free(aux);
		}
		free(res);
		res = NULL;
	}
	return (xpm->map);
}
