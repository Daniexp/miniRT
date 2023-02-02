#include <miniRT.h>

void	vcpy(float src[3], float dst[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		dst[i] = src[i];
		i++;
	}
}
