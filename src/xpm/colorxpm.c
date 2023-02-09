/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorxpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:51:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/09 20:38:15 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <miniRT.h>

static void	split_free(char **split)
{
	char **aux;

	if (!split)
		return ;
	aux = split;
	while(*aux)
	{
		free(*aux);
		aux++;
	}
	free(split);
	return ;
}
int	new_clr(t_xpm* xpm, char *rgb)
{
	char	**chclr;
	char	**clr;
	int		i;
	int		res;
	if (!xpm || !rgb)
		return (-1);
	chclr = ft_split(xpm->dfclr, '\n');
	if (!chclr)
		return (-2);
	i = -1;
	res = 1;
	while (res != 0 && chclr[++i])
	{
		clr = ft_split(chclr[i], ' ');
		printf("tras todo los split clr es: %s\n", *clr);
		if (!clr)
			return (split_free(chclr), -2);
		//IMPORTANTE EL 0 AQUI ES SOLO PORQUE SE ESTA PROBANDO CON UN DFCLR SIN DEFINICION DE CARACTERES PARA EL COLOR
		res = ft_strncmp(clr[0], rgb, ft_strlen(rgb));
		printf("la comparacion de las stings devuelve: %d\n", res);
		split_free(clr);
	}
	split_free(chclr);
	return (res);
}
