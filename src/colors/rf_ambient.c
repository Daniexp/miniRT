/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_ambient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:37:40 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/05 19:01:36 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ambientColor(t_ambient* A)
{
	return (get_rgba(A->rgb[0], A->rgb[1], A->rgb[2], A->rate));	// There the 0.0 is the alpha channel of the rgb, that represent the opacity of the colour....
}
// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
	if (a < 0 )
		return (-1);
    return (r << 24 | g << 16 | b << 8);
}
char	*rgbHex(int r, int g, int b)
{
	char	*res;
	char	*aux;
	char	*aux2;

	res = change_base(r, "0123456789ABCDEF");
	printf("EL PRIMER RESULTADO ES : %s\n", res);
	aux = res;
	aux2 = change_base(g, "0123456789ABCDEF");
	res = ft_strjoin(aux, aux2);
	free(aux);
	free(aux2);
	aux = res;
	aux2 = change_base(b, "0123457689ABCDEF");
	res = ft_strjoin(aux, aux2);
	free(aux);
	free(aux2);
	aux = res;
	res = ft_strjoin("0x", aux);
	free(aux);
	return (res);
}
char*	change_base(int nmb, char *base)
{
	int leng_base;

	printf("NMB: %d\n", nmb);
	if (nmb < 0 || !base)
		return (NULL);
	leng_base = ft_strlen(base);
	char *res;
	char *aux;
	char *c;
	res = NULL;
	while (nmb > 0)
	{
		printf("LENG: %d, NMB: %d, resto: %d, RES: %s\n", leng_base, nmb, nmb % leng_base, res);
		if (!res)
			res = ft_substr(base, nmb % leng_base, sizeof(char));
		else
		{
			c = ft_substr(base, nmb % leng_base, sizeof(char));
			aux = ft_strjoin(c, res);
			free (res);
			free(c);
			res = aux;
		}
		nmb = nmb / leng_base;
	}
	printf("Al cambiar de base el resultado es: %s\n", res);
	return (res);
}