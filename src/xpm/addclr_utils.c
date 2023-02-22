/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addclr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:40:48 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 10:19:30 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <xpm.h>

char	*getclr_str(char *rgb, char *dfclr)
{
	char	**dfln;
	int		clrind;
	char	**clr;
	char	*res;

	if (!rgb || !dfclr)
		return (NULL);
	res = NULL;
	dfln = ft_split(dfclr, '\n');
	clrind = -1;
	while (dfln[++clrind])
	{
		clr = ft_split(dfln[clrind], ' ');
		if (!ft_strncmp(rgb, clr[1], ft_strlen(rgb)))
			break ;
		split_free(clr);
	}
	if (dfln[clrind])
	{
		res = ft_substr(clr[0], 0, ft_strlen(clr[0]));
		split_free(clr);
	}
	split_free(dfln);
	return (res);
}
//esta funion, buscar el str de la ult clr en dfclr
//y usara create_dfclr() para crear
//la nueva definicion del color, y la añadira a xpm->dfclr
//y devolvera el str del color para
//posteriormente añadir estos caracteres al mapa

char	*add_newclrdf(t_xpm *xpm, char *rgb)
{
	char	**clrln;
	int		i;
	char	**lstdf;
	char	*newdf;
	char	*aux;

	clrln = ft_split(xpm->dfclr, '\n');
	if (!xpm || !rgb || !xpm->dfclr || !clrln)
		return (NULL);
	i = -1;
	while (clrln[++i + 1])
		;
	lstdf = ft_split(clrln[i], ' ');
	split_free(clrln);
	if (!lstdf)
		return (NULL);
	newdf = create_dfclr(xpm, lstdf[0], rgb);
	if (!newdf)
		return (split_free(lstdf), NULL);
	aux = xpm->dfclr;
	xpm->dfclr = ft_strjoin(aux, newdf);
	free(aux);
	aux = ft_substr(newdf, 0, xpm->inf.chpx);
	return (free(newdf), split_free(lstdf), aux);
}

char	*first_clr(char *rgb, t_xpm *xpm)
{
	char	*res;
	char	*aux;

	if (!rgb || !xpm || xpm->dfclr || xpm->inf.chpx != 1)
		return (NULL);
	res = ft_strjoin("0 ", rgb);
	aux = res;
	res = ft_strjoin(aux, "\n");
	free(aux);
	return (res);
}
