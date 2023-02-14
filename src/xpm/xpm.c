/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:38:11 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/14 19:01:03 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
char	*file_xpm( void )
{
	return (NULL);
}
t_xpm*	new_xpm(mlx_t*	mlx, char * name)
{
	t_xpm* xpm;

	xpm = NULL;
	if (mlx && name)
		xpm = ft_calloc(1, sizeof(t_xpm));
	if (xpm)
	{
		xpm->inf.width = mlx->width;
		xpm->inf.height = mlx->height;
		xpm->inf.nclr = 0;
		xpm->inf.mode = 'C';
		xpm->name = NULL;
		xpm->dfclr = NULL;
		xpm->map = NULL;
		xpm->inf.chpx = 1;//exp_pow(2, mlx->width * mlx->height);
		if (xpm->inf.chpx >= 0)
			xpm->name = ft_substr(name, 0, ft_strlen(name));
		if (!xpm->name)
			free(xpm);
	}
	print_xpm(xpm);
	return (xpm);
}
int	add_clr_xpm(t_xpm* xpm, char *rgb, int i, int j)
{
	if (!xpm || !rgb || i < 0 || j < 0)
		return (-1);
//	if (new_clr(xpm->dfclr))
	//Comprobar si el color es nuevo o no
		//si es nuevo:
			// ver si podemos añadirlo con los caracteres actuales
				//si no se puede-> combiar toda la definicion de colores y el map correcpondiente
				
		//asignar nueva combinacion de chars al color
		//sustituir combinacion en map en la pos de i,j correspondiente
	return (0);
}
//asignar nueva combinacion de chars al color
//combiar toda la definicion de colores y el map correcpondiente
char*	fill_map(char *oldmap, char *src, int i, int j) 
{
	if (!oldmap || !src || i < 0 || j < 0)
		return (NULL);
	return (NULL);
}
char*	modify_map(t_xpm *xpm)
{
	int		mapsz;
	int	i;
	char	**map;
	if (!xpm || !xpm->map)
		return (NULL);
	mapsz = xpm->inf.height * xpm->inf.width + xpm->inf.height;
	map =  ft_split(xpm->map, ' ');
	i = -1;
	while (map[++i])
	{
	}

	return (NULL);
}
