#include <miniRT.h>

int	check_vec3d(char **vec)
{
	int	i;

	i = 0;
	if (double_pointier_len(vec) != 3)
		return (1);
	while (i < 3)
		if (check_all_nb(vec[i++]) == 1)
			return (1);
	return (0);
}
