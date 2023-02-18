/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addclr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:40:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/18 17:49:48 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
# include <xpm.h>

char	*getclr_str(char *rgb, char *dfclr)
{
	if (!rgb || !dfclr)
		return (NULL);
	return (NULL);
}
//esta funion, buscar el str de la ult clr en dfclr  y usara create_dfclr() para crear
//la nueva definicion del color, y la añadira a xpm->dfclr y devolvera el str del color para
//posteriormente añadir estos caracteres al mapa
char	*add_newclrdf(t_xpm *xpm, char *rgb)
{
	char	**clrln;
	int		i;
	char	**lstdf;
	char	*newdf;
	char	*aux;

	if (!xpm || !rgb || !xpm->dfclr)
		return (NULL);
	clrln = ft_split(xpm->dfclr, '\n');
	if (!clrln)
		return (NULL);
	i = -1;
	while (clrln[++i + 1]);
	lstdf = ft_split(clrln[i], ' ');
	split_free(clrln);
	if (!lstdf)
		return (NULL);
	newdf = create_dfclr(xpm, lstdf[0], rgb);
	if (!newdf)
		return (split_free(clrln), split_free(lstdf), NULL);
	aux = xpm->dfclr;
	xpm->dfclr = ft_strjoin(aux, newdf);
	free(aux);
	free(newdf);
	aux = ft_substr(lstdf[0], 0, xpm->inf.chpx);
	split_free(lstdf);
	return (aux);
}
char	*first_clr(char *rgb, t_xpm *xpm)
{
	char	*res;
	char	*aux;
	if (!rgb || !xpm || xpm->dfclr || xpm->inf.chpx != 1)
		return (NULL);
	res = ft_strjoin("0 " , rgb);
	aux = res;
	res = ft_strjoin(aux, "\n");
	free(aux);
	return (res);
}
