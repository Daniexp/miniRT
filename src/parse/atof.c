#include <miniRT.h>


int	check_all_nb(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return (1);
		i++;
	}
	return (0);
}
	
/* Resulta que en la libreria stdlib (creo) o en cualquier otra de las que usamos ya tiene una funcion llamada atof. Nombre provisional si te parece*/

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
