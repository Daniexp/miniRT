/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorxpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:51:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 11:20:59 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	split_free(char **split)
{
	char	**aux;

	if (!split)
		return ;
	aux = split;
	while (*aux)
	{
		free(*aux);
		aux++;
	}
	free(split);
	return ;
}

int	new_clr(t_xpm *xpm, char *rgb)
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
		res = ft_strncmp(clr[1], rgb, ft_strlen(rgb));
		printf("la comparacion de las stings devuelve: %d\n", res);
		split_free(clr);
	}
	split_free(chclr);
	return (res);
}

int	check_addclr(t_xpm *xpm)
{
	if (!xpm)
		return (-1);
	return (pow(ft_strlen(BASEXPMCHR), xpm->inf.chpx) > xpm->inf.nclr + 1);
}
//añade siemmpre sero  a las definiciones antiguas

char	*modify_dfclr(t_xpm *xpm)
{
	char	**olddf;
	char	*res;
	char	*aux;
	char	*auxspc;
	char	*auxres;
	int		i;

	if (!xpm)
		return (NULL);
	olddf = ft_split (xpm->dfclr, ' ');
	i = -1;
	while (olddf[++i])
	{
		printf("La combinación inicial es: %s\n", olddf[i]);
		aux = olddf[i];
		auxres = ft_strnjoin(BASEXPMCHR[0], aux, 1);
		free(aux);
		olddf[i] = auxres;
		if (olddf[i + 1])
			i++;
	}
	i = -1;
	res = NULL;
	while (olddf[++i])
	{
		auxspc = olddf[i];
		auxspc = ft_strjoin(auxspc, " ");
		aux = ft_strjoin(auxspc, olddf[i + 1]);
		free(auxspc);
		auxres = res;
		res = ft_strjoin(auxres, aux);
		if (!res)
			res = ft_substr(aux, 0, ft_strlen(aux));
		else
			free(auxres);
		free(aux);
		if (olddf[i + 1])
			i++;
	}
	split_free(olddf);
	free(xpm->dfclr);
	xpm->dfclr = res;
	return (res);
}

char	*create_dfclr(t_xpm *xpm, char *lastdf, char *rgb)
{
	char	*res;
	char	*aux;
	int		len_df;

	if (!xpm || !lastdf || !rgb)
		return (NULL);
	len_df = convert_dec(lastdf, BASEXPMCHR);
	aux = change_base(++len_df, BASEXPMCHR);
	len_df = xpm->inf.chpx - ft_strlen(aux);
	res = aux;
	if (len_df > 0)
	{
		aux = ft_strnjoin(BASEXPMCHR[0], aux, len_df);
		free(res);
	}
	res = ft_strjoin(aux, " ");
	free(aux);
	aux = res;
	res = ft_strjoin(aux, rgb);
	free(aux);
	aux = res;
	res = ft_strjoin(aux, "\n");
	free(aux);
	return (res);
}
