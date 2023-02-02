#include <miniRT.h>

void	error_msg(char *s)
{
	int	i;

	i = 0;
	write(2, "error: ", 7);
	while (s[i])
		write(2, &s[i++], 1);
}
