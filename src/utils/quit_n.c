#include <miniRT.h>

char	*quit_c(char *s, char c)
{
	int		i;
	int		y;
	char	*new_s;

	i = 0;
	y = 0;
	new_s = malloc(sizeof(char ) * ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			i++;
		new_s[y++] = s[i++];
	}
	return (new_s);
}
