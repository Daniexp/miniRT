/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:38:11 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 11:31:27 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

char	*file_xpm( void )
{
	return (NULL);
}

t_xpm	*new_xpm(mlx_t	*mlx, char *name)
{
	t_xpm	*xpm;

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
		xpm->inf.chpx = 1;
		if (xpm->inf.chpx >= 0)
			xpm->name = ft_substr(name, 0, ft_strlen(name));
		if (!xpm->name)
			free(xpm);
	}
	print_xpm(xpm);
	return (xpm);
}

//TO TEST WITH 
// ALL THE ADDCLR_UTILS.C FUNCTIONS	
int	add_clr_xpm(t_xpm *xpm, char *rgb, int i, int j)
{
	char	*df;

	if (!xpm || !rgb || i < 0 || j < 0)
		return (-1);
	df = NULL;
	if (xpm->dfclr && new_clr(xpm, rgb) > 0)
	{
		if (!check_addclr(xpm))
		{
			modify_dfclr(xpm);
			modify_map(xpm);
			xpm->inf.chpx++;
		}
		df = add_newclrdf(xpm, rgb);
	}
	else if (!xpm->dfclr)
	{
		xpm->dfclr = first_clr(rgb, xpm);
		if (!xpm->map)
			init_map(xpm);
	}
	if (!df)
		df = getclr_str(rgb, xpm->dfclr);
	fill_map(xpm, df, i, j);
	return (free(df), 0);
}
