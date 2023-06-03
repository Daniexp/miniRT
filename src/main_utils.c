/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:10:58 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/03 18:33:54 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	leaks(void)
{
	system("leaks miniRT");
}

void	freelist(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

void	freescene(t_scene *scene)
{
	if (scene->sp)
	{
		freelist(*(scene->sp));
		free(scene->sp);
	}
	if (scene->cy)
	{
		freelist(*(scene->cy));
		free(scene->cy);
	}
	if (scene->pl)
	{
		freelist(*(scene->pl));
		free(scene->pl);
	}
}

void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
