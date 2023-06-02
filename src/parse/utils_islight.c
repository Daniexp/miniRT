/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_islight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:52:22 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:17:00 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_light_cylinder(t_scene *scene)
{
	int			res;
	t_list		*lst;
	t_cylinder	*cy;

	res = 0;
	lst = *(t_list **)scene->cy;
	while (lst)
	{
		cy = (t_cylinder *)lst->content;
		res = (islight_incylinder(scene, cy));
		lst = lst->next;
	}
	return (res);
}

float	*fdup(float *v)
{
	float	*u;

	if (!v)
		return (NULL);
	u = (float *) ft_calloc(sizeof(float ), 3);
	u[0] = v[0];
	u[1] = v[1];
	u[2] = v[2];
	return (u);
}

int	is_normalize(float *vector)
{
	if (!vector)
		return (0);
	return (sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2))
		- 1.0 <= 0.00001);
}
