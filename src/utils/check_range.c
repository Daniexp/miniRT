#include <miniRT.h>

int	check_range(float n, float origin, float last)
{
	if (n < origin || n > last)
		return (1);
	return (0);
}
