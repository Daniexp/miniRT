/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:38:11 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/09 15:34:09 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
static void	print_xpm(t_xpm *xpm)
{
	if (!xpm)
		return ;
	ft_putstr_fd("---XPM STRUCTURE DATA---\n", 1);
	printf("Name-> %s\n", xpm->name);
	printf("Width: %d, Height: %d, Nclr: %d, Chpx: %d, Mode: %c\n", xpm->inf.width, xpm->inf.height,xpm->inf.nclr, xpm->inf.chpx, xpm->inf.mode);
	printf("Def colours: %s\nChars Map: %s\n", xpm->dfclr, xpm->map);
}
static int	exp_pow(int base, int res)
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
t_xpm*	new_xpm(mlx_t*	mlx, char * name)
{
	t_xpm* xpm;

	xpm = NULL;
	if (mlx && name)
		xpm = ft_calloc(1, sizeof(t_xpm));
	if (xpm)
	{
		xpm->inf.width = mlx->width;
		xpm->inf.height = mlx->height;
		xpm->inf.nclr = 0;
		xpm->inf.mode = 'C';
		xpm->name = NULL;
		xpm->dfclr = NULL;
		xpm->map = NULL;
		xpm->inf.chpx = exp_pow(2, mlx->width * mlx->height);
		if (xpm->inf.chpx >= 0)
			xpm->name = ft_substr(name, 0, ft_strlen(name));
		if (!xpm->name)
			free(xpm);
	}
	print_xpm(xpm);
	return (xpm);
}
char	*file_xpm( void )
{
	return (NULL);
}
