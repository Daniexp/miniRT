/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:30:55 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:31:11 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	input_error(int arg)
{
	if (arg < 2)
	{
		error_msg("Insert an input file");
		return (1);
	}
	else if (arg > 2)
	{
		error_msg("Insert just one input file");
		return (1);
	}
	return (0);
}
