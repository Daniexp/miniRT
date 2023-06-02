/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:18:07 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/02 21:01:12 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

int	count_dots(char *s)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	while (s[i])
	{
		if (s[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}

int	check_extension(char *s)
{
	int		i;
	int		y;
	char	*ext;

	i = 0;
	if (count_dots(s) != 1)
		return (error_msg("Wrong extension of input file"), 1);
	y = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			ext = ft_strdup(&s[i + 1]);
			y = fmax(ft_strlen(ext), 2);
			if (ft_strncmp(ext, "rt", y) == 0 && ft_strlen(ext) > 0)
				return (free(ext), 0);
		}
		i++;
	}
	if (ext)
		free(ext);
	error_msg("Extension must be .rt");
	return (1);
}
