/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_dfclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:54:30 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/24 09:27:19 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <xpm.h>

char	*addfirstbase_dfclr(char **split, int ind)
{
	char	*res;

	if (!split || ind < 0)
		return (NULL);
	res = ft_strnjoin(BASEXPMCHR[0], split[ind], 1);
	free(split[ind]);
	split[ind] = res;
	return (NULL);
}

char	*join_dfclr(char **split, int ind)
{
	char	*res;
	char	*aux;

	if (!split || ind < 0)
		return (NULL);
	aux = ft_strjoin(split[ind], " ");
	res = ft_strjoin(aux, split[ind + 1]);
	free(aux);
	return (res);
}

char	*iter_dfclr(char **splitdf, char *(*f)(char **, int))
{
	int		i;
	char	*func_rt;

	if (!splitdf)
		return (NULL);
	i = -1;
	func_rt = NULL;
	while (splitdf[++i])
	{
		func_rt = f(splitdf, i);
		if (!func_rt)
			return (NULL);
		if (splitdf[i + 1])
			i++;
	}
	return (func_rt);
}

char	*joinstrfree(char *fst, char *scd)
{
	char	*res;

	if (fst)
	{
		res = ft_strjoin(fst, scd);
		free(fst);
	}
	else
		res = ft_substr(scd, 0, ft_strlen(scd));
	free(scd);
	return (res);
}

char	*modify_dfclr(t_xpm *xpm)
{
	char	**olddf;
	char	*aux;
	char	**lndf;
	char	*newdf;
	int		i;

	if (!xpm || !xpm->map)
		return (NULL);
	lndf = ft_split(xpm->dfclr, '\n');
	free(xpm->dfclr);
	xpm->dfclr = NULL;
	i = -1;
	while (lndf[++i])
	{
		olddf = ft_split(lndf[i], ' ');
		iter_dfclr(olddf, &addfirstbase_dfclr);
		newdf = iter_dfclr(olddf, &join_dfclr);
		aux = ft_strjoin(newdf, "\n");
		free(newdf);
		xpm->dfclr = joinstrfree(xpm->dfclr, aux);
		split_free(olddf);
	}
	split_free(lndf);
	return (xpm->dfclr);
}
