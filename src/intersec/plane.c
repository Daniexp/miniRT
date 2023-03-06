/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:32:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/06 13:19:26 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>

/*
 * PARA CALCULAR LA INTERSECCION DE UN PLANO CON UNA RECTA
 * LA RECATA LA CONFORMAN VECTOR Y EL PUNTO DE ORIGEN DE LA CAMARA
 * Y EL PLANO ESTA LIMITADO POR UN PUNTO DE ORIGEN Y UN VECTOR  NORMAL A ESTE
 * HALLAR LA ECUACION DEL PLANO (CUAL¿?)
 */
/*
 *	pl_equation devuelve un arrray de 4 floats correspondientes a la fórmula de
 *	un plano de la siguiente forma : Ax By Cy + D = 0. Donde la solución en el
 *	array es: A,B,C,D
 */
float	*pl_equation(float *point, float *normal)
{
	float	*equation;
	int		i;

	equation = ft_calloc(sizeof(float), 4);
	if (!equation)
		return (NULL);
	if (!point || !normal)
		return (free(equation), NULL);
	i = -1;
	while (++i < 3)
		equation[i] = normal[i];
	equation[i] = 0;
	i = -1;
	while (++i < 3)
		equation[3] += normal[i] * (-1 * point[i]);
	return (equation);
}
float	*sect_plane(float *vector, t_camera *C, t_plane *pl)
{
	float	*inters;

	inters = ft_calloc(sizeof(float), 3);
	if (!inters)
		return (NULL);
	if (!vector || !C || !pl)
		return (free(inters), NULL);
	return (inters);
}
