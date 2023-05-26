#include <miniRT.h>

int	error_msg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	return (1);
}
