/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:59:54 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/23 17:59:56 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_vec3d(char **vec, int c)
{
	int		i;
	float	v[3];

	i = 0;
	if (double_pointier_len(vec) != 3)
		return (1);
	while (i < 3)
		if (check_all_nb(vec[i++]) == 1)
			return (1);
	if (c == 'v')
	{
		i = 0;
		while (i < 3)
		{
			v[i] = atofelio(vec[i]);
			i++;
		}
		if (vector_module(v_gen(v)) == 0)
			return (1);
	}
	return (0);
}
