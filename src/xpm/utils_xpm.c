/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/22 11:26:13 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	print_xpm(t_xpm *xpm)
{
	if (!xpm)
		return ;
	ft_putstr_fd("---XPM STRUCTURE DATA---\n", 1);
	printf("Name-> %s\n", xpm->name);
	printf("Width: %d, Height: %d, Nclr: %d, Chpx: %d, Mode: %c\n",
		xpm->inf.width, xpm->inf.height, xpm->inf.nclr,
		xpm->inf.chpx, xpm->inf.mode);
	printf("Def colours: %s\nChars Map: %s\n", xpm->dfclr, xpm->map);
}

int	exp_pow(int base, int res)
{
	int	exp;

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

int	index_base(char chr, char *base)
{
	char	*aux;
	int		ind;
	int		len_bs;

	if (!base)
		return (-1);
	len_bs = (int) ft_strlen(base);
	aux = base;
	ind = -1;
	while (base[++ind] && base[ind] != chr)
		;
	if (ind < len_bs)
		return (ind);
	else
		return (-1);
}
//convert_dec convierte nmb dado base a un decimal,
//si el nmb no es valido devuelve -1

int	convert_dec(char *nmb, char *base)
{
	int	i;
	int	res;
	int	lennmb;
	int	lenbs;

	i = -1;
	if (!nmb || !base)
		return (i);
	res = 0;
	lennmb = ft_strlen(nmb);
	lenbs = ft_strlen(base);
	while (nmb[++i] && index_base(nmb[i], base) != -1)
		res += pow(lenbs, (lennmb - 1 - i)) * index_base(nmb[i], base);
	if (nmb[i])
		res = -1;
	return (res);
}

char	*ft_strnjoin(char chr, char *src, int times)
{
	char	*res;
	char	*aux;
	char	*strchr;

	if (!src || times <= 0 || chr == '\0')
		return (NULL);
	strchr = ft_calloc(1, sizeof(char));
	*strchr = chr;
	res = ft_strjoin(strchr, src);
	aux = NULL;
	while (--times > 0)
	{
		aux = res;
		res = ft_strjoin(&chr, aux);
		free(aux);
	}
	free(strchr);
	return (res);
}
