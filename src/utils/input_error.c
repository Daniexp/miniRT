#include <miniRT.h>

int input_error(int arg)
{
	if (arg < 2)
	{
		error_msg("Insert an input file");
		return (1);
	}
	else if (arg > 2)
	{
		error_msg("Insert just one input file");
		return (1);
	}
	return (0);
}
