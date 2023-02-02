#include <miniRT.h>

void	print_int(void	*content)
{
	printf("--%d--\n", *((int *)content));
}

int	main(int argc, char **argv)
{
	t_scene *scene;
/*	t_list	**sp;
	int	i;
	int	*dec;

	i = 0;
	sp = malloc(sizeof(t_list ) * 10);
	while (i < 10)
	{
		dec = malloc(sizeof(int) * 1);
		*dec = i;
		ft_lstadd_front(sp, ft_lstnew((void *)dec));
		i++;
	}
	ft_lstiter(*sp, print_int);
	(void)argv;
*/	
	if (input_error(argc) == 1)
		return (0);
	if (parse(argv[1], &scene) == 1)
	/	return (0);
	return (0);
}	

