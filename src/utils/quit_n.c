#include <miniRT.h>

/*
static int	count_c(char *s, char c)
{
	int		cnt;
	char	*lst_c;

	if (!s || c == '\0')
		return (-1);
	cnt = 0;
	lst_c = s;
	while (ft_strchr(lst_c,c))
	{
		lst_c = ft_strchr(lst_c, c);
		cnt++;		
	}
	return (cnt);
}
*/
char	*quit_c(char *s, char c)
{
	int		i;
	int		y;
	char	*new_s;

	i = 0;
	y = 0;
	new_s = malloc(sizeof(char ) * ft_strlen(s));
/*
	new_s = ft_calloc(sizeof(char), ft_strlen(s) - count_c(s, c) + 1);
	if (!new_s)
		return (NULL);
	if (!s)
		return (free(new_s), NULL);
*/
	while (s[i])
	{
		if (s[i] != c)
			new_s[y++] = s[i++];
		i++;
	}
	printf("s: %s\nnew_s: %s\n", s, new_s);
	return (new_s);
}
