/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorxpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:51:49 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/14 12:21:39 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <miniRT.h>

static void	split_free(char **split)
{
	char **aux;

	if (!split)
		return ;
	aux = split;
	while(*aux)
	{
		free(*aux);
		aux++;
	}
	free(split);
	return ;
}
int	new_clr(t_xpm* xpm, char *rgb)
{
	char	**chclr;
	char	**clr;
	int		i;
	int		res;
	if (!xpm || !rgb)
		return (-1);
	chclr = ft_split(xpm->dfclr, '\n');
	if (!chclr)
		return (-2);
	i = -1;
	res = 1;
	while (res != 0 && chclr[++i])
	{
		clr = ft_split(chclr[i], ' ');
		printf("tras todo los split clr es: %s\n", *clr);
		if (!clr)
			return (split_free(chclr), -2);
		//IMPORTANTE EL 0 AQUI ES SOLO PORQUE SE ESTA PROBANDO CON UN DFCLR SIN DEFINICION DE CARACTERES PARA EL COLOR
		res = ft_strncmp(clr[1], rgb, ft_strlen(rgb));
		printf("la comparacion de las stings devuelve: %d\n", res);
		split_free(clr);
	}
	split_free(chclr);
	return (res);
}
//TO TESTT
int	check_addclr(t_xpm *xpm)
{
	if (!xpm)
		return (-1);
	return (pow(ft_strlen(BASEXPMCHR), xpm->inf.chpx) > xpm->inf.nclr + 1);
}
//TO TESTT
//BAD IMPLEMENT¿????

char*	modify_dfclr(t_xpm *xpm)
{
	char	**olddf;
	char	*res;
	char	*aux;
	char	*auxspc;
	char	*auxres;
	int 	i;

	if (!xpm)
		return (NULL);
	//ahora es chpx es chpx++ y tenemos que reescribir todos las líneas de df_cl r  basandonos en nuesra BASEXPMCHR que es nuestra base de caracteres para crear esta dfclr del xpm 
//tenemos que convertir las definiciones a enteros sumarles 1 y aplicarles change_base para convertirlos a la base correspondiente	
//hay que añadir el primer caracter de la base a todas las definiciones de colores que existan
	olddf = ft_split (xpm->dfclr, ' ');
	i = -1;
	while (olddf[++i])
	{
		printf("La combinación inicial es: %s\n", olddf[i]);
		aux = olddf[i];
		auxres = ft_strjoin("0", aux);
		free(aux);
		olddf[i] = auxres;
		if (olddf[i + 1])
			i++;
	}
	i = -1;
	res = NULL;
	while (olddf[++i])
	{
		auxspc = olddf[i];
		auxspc = ft_strjoin(auxspc, " ");
		aux = ft_strjoin(auxspc, olddf[i+1]);
		free(auxspc);
		auxres = res;
		res = ft_strjoin(auxres, aux);
		if (!res)
			res = ft_substr(aux, 0, ft_strlen(aux));
		else
			free(auxres);
		free(aux);
		if (olddf[i + 1])
			i++;
	}
	split_free(olddf);
	free(xpm->dfclr);
	xpm->dfclr = res;
	xpm->inf.chpx++;
	return (res);
}
//TO TESTT
		/*
		bsnmb = convert_dec(olddf[1], BASEXPMCHR);
		free(olddf[i]);
		olddf[i] = change_base(++bsnmb, BASEXPMCHR);
		printf("al sumar uno a la comb queda: %s\n", olddf[i]);
		*/
char*	create_dfclr(t_xpm* xpm, char *lastdf, char *rgb)
{
	char*	res;
	char*	aux;
	int		len_df;
	if (!xpm || !lastdf || !rgb)
		return (NULL);
	aux = change_base(convert_dec(lastdf, BASEXPMCHR) + 1, BASEXPMCHR);
	//completar con primero de la base tantas veces como diferencia de caracteres a usar con los del número
	len_df = xpm->inf.chpx - ft_strlen(aux);
	//añadir primero base tantas veces como len_df a aux....
	res = aux;
	aux = ft_strnjoin(BASEXPMCHR[0], aux, len_df);
	free(res);
	printf("xpm->inf.chpx: %d, Aux: %s aux len: %zu, len_df--->%d\n",xpm->inf.chpx, aux,ft_strlen(aux), len_df);
	printf("Lastdf: %s\n", lastdf);
	res = ft_strjoin(aux , " ");
	free(aux);
	aux = res;
	res = ft_strjoin(aux, rgb);
	free(aux);
	aux = res;
	res = ft_strjoin(aux, "\n");
	free(aux);
	printf("The lastdf whas: %s, and the new is: %s\n", lastdf, res);
	return (res);
}
