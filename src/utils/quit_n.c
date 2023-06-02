/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:31:20 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:31:42 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
static int	count_c(char *s, char c)
{
	int		cnt;
	char	*lst_c;

	if (!s || c == '\0')
		return (-1);
	cnt = 0;
	lst_c = s;
	while (ft_strchr(lst_c,c))
	{
		lst_c = ft_strchr(lst_c, c);
		cnt++;		
	}
	return (cnt);
}
*/
char	*quit_c(char *s, char c)
{
	int		i;
	int		y;
	char	*new_s;

	i = 0;
	y = 0;
	new_s = (char *) malloc(sizeof(char ) * ft_strlen(s));
	while (s[i])
	{
		if (s[i] != c)
			new_s[y++] = s[i++];
		i++;
	}
	return (new_s);
}
