/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/10 17:32:30 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <miniRT.h>

void	print_xpm(t_xpm *xpm)
{
	if (!xpm)
		return ;
	ft_putstr_fd("---XPM STRUCTURE DATA---\n", 1);
	printf("Name-> %s\n", xpm->name);
	printf("Width: %d, Height: %d, Nclr: %d, Chpx: %d, Mode: %c\n", xpm->inf.width, xpm->inf.height,xpm->inf.nclr, xpm->inf.chpx, xpm->inf.mode);
	printf("Def colours: %s\nChars Map: %s\n", xpm->dfclr, xpm->map);
}
int	exp_pow(int base, int res)
{
	int exp;
	
	exp = -1;
	if (base >= 0 || res >= 0)
	{
		exp = 0;
		while (res >= base)
		{
			res /= base;
			exp++;
		}
	}
	return (exp);
}
