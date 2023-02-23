/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:01:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/23 09:02:13 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <xpm.h>

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
