/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_dfclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:54:30 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/23 12:02:45 by dexposit         ###   ########.fr       */
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
		printf("func_rt es: %s\n", func_rt);
		if (!func_rt)
			return (NULL);
		if (splitdf[i + 1])
			i++;
	}
	return (func_rt);
}

char	*modify_dfclr(t_xpm *xpm)
{
	char	**olddf;
	char	*aux;

	if (!xpm)
		return (NULL);
	olddf = ft_split (xpm->dfclr, ' ');
	aux = iter_dfclr(olddf, &addfirstbase_dfclr);
	free(xpm->dfclr);
	xpm->dfclr = iter_dfclr(olddf, &join_dfclr);
	split_free(olddf);
	return (xpm->dfclr);
}
