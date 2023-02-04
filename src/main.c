#include <miniRT.h>

void	print_int(void	*content)
{
	printf("--%d--\n", *((int *)content));
}

int	main(int argc, char **argv)
{
	(void)argv;
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
	scene = malloc(sizeof(t_scene));
	if (input_error(argc) == 1)
		return (0);
	if (parse(argv[1], scene) == 1)
		return (0);
	printf("--%f--\n", scene->L.coord[1]);
	printf("--%f--", scene->L.rate);
	//printf("--%f--\n", atofelio("23.45667"));
	//printf("--%d--", check_all_nb("23.4566,7"));
	return (0);
}	

