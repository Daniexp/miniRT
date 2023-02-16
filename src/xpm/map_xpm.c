/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:06:56 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/16 19:54:56 by dexposit         ###   ########.fr       */
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
			aux = res;
			if (aux)
			{
				res = ft_strjoin(clr, aux);
				free(aux);
			}
			else
				res = ft_substr(clr, 0, ft_strlen(clr));
			free(clr);		
			j -= xpm->inf.chpx;
		}
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
//TO TEST
char*	fill_map(t_xpm *xpm,char *chrclr, int i, int j) 
{
	char	*newmap;
	char	*prevclr;
	char	*aftclr;
	int		lendf;
	int		indclr;
	if (!xpm->map || !chrclr || i < 0 || j < 0 || i >= xpm->inf.width || j >= xpm->inf.height)
		return (NULL);
	lendf = ft_strlen(chrclr);
	indclr = xpm->inf.width * j * lendf + j + i * lendf;
	prevclr = ft_substr(xpm->map, 0, indclr);
	aftclr = ft_substr(xpm->map, indclr + lendf, ft_strlen(xpm->map) - (indclr + lendf));
	printf("------------------------\n");
	printf("xpm->map %s\n, chrclr: %s\n, i %d, j %d\nprevclr: %s\n, afterclr: %s\n", xpm->map, chrclr, i ,j, prevclr, aftclr);
	if (prevclr)
	{
		newmap = ft_strjoin(prevclr, chrclr);
		free(prevclr);
		prevclr = newmap;
	}
	if (aftclr)
		newmap = ft_strjoin(prevclr, aftclr);
	free(prevclr);
	free(aftclr);
	printf("------------------------\n");
	printf("EL NWE MAP ES: \n%s", newmap);
	printf("------------------------\n");
	free(xpm->map);
	xpm->map = newmap;
	return (newmap);
}
