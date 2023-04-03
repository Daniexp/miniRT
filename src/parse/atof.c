#include <miniRT.h>


int	check_all_nb(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '-')
			i++;
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
	
/* Resulta que en la libreria stdlib (creo) o en cualquier otra de las que usamos ya tiene una funcion llamada atof. Nombre provisional si te parece*/
/*
float	atofelio(char *s)
{
	float	res;
	char	*quote;
	char	*prev;
	char	*after;

	if (!s)
		return (-0.0);
	quote = ft_strchr(s,'.');
	if (quote)
		prev = ft_substr(s,0,ft_strlen(s) - (quote - s + 1));
				11.20*/
/*
	else
		prev = ft_substr(s,0, ft_strlen(s));	
	res = (float) ft_atoi(prev);
	free(prev);
	after = ft_substr(quote, 1, ft_strlen(s) - (quote - s - 1));
	if (after)
	{
		res +=  (float) ft_atoi(after) / pow(10, ft_strlen(after));
		free(after);
	}
	return (res);
}
*/

float	atofelio(char *s)
{
	int		i;
	float	f;
	char	*integer;
	char	*decimal;

	i = 0;
	decimal = malloc(sizeof(char ) * (ft_strlen(s) + 1));
	while (s[i] && s[i] != '.')
	{
		decimal[i] = s[i];
		i++;
	}
	decimal[i] = '\0';
	integer = ft_strdup(decimal);
	free(decimal);
	decimal = ft_strdup(&s[i + 1]);
	f = ((float)ft_atoi(integer) * (pow(10, ft_strlen(decimal))) + (float)(ft_atoi(decimal))) / pow(10, ft_strlen(decimal));
	return (f);
}
