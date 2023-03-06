/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:32:02 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/06 19:36:06 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <intersection.h>

/*
 * PARA CALCULAR LA INTERSECCION DE UN PLANO CON UNA RECTA
 * LA RECTA LA CONFORMAN VECTOR Y EL PUNTO DE ORIGEN DE LA CAMARA
 * ecuacion vectorial de al recta la tenemos
 * necesitamos las parametricas
 * las reemplazamos en la ecuacion del plano
 * 	despejamos alpha y sustituimos en las ecuaciones de la recta para obtener
 * 	el punto de interseccion
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
/*
float	*ln_equation(float *point, float *vector)
{
	float	*equation;
	int		i;

	equation = ft_calloc(sizeof(float), 3);
	if (!equation)
		return (NULL);
	if (!point || !vector)
		return (free(equation), NULL);
	return (equation);
}
	Vector intersection(Vector c, Vector u, Plane p) {
    // Encontrar la ecuación del plano
    double d = -p.point.x * p.normal.x - p.point.y * p.normal.y - p.point.z * p.normal.z;
    // Encontrar la proyección del vector que va desde C en la dirección de U en el plano
    double proj = (c.x * p.normal.x + c.y * p.normal.y + c.z * p.normal.z + d) / (u.x * p.normal.x + u.y * p.normal.y + u.z * p.normal.z);
    Vector projection = {proj * u.x, proj * u.y, proj * u.z};
    // Encontrar la intersección
    Vector intersection = {c.x + projection.x, c.y + projection.y, c.z + projection.z};
    return intersection;
	}
*/

float	*sect_plane(float *vector, t_camera *C, t_plane *pl)
{
	float	*inters;
	float	d;
	float	proj;
	int		i;

	inters = ft_calloc(sizeof(float), 3);
	if (!inters)
		return (NULL);
	if (!vector || !C || !pl)
		return (free(inters), NULL);
	d = -pl->coord[0] * pl->vec[0] - pl->coord[1] * pl->vec[1]
		- pl->coord[2] * pl->vec[2];
	proj = (C->coord[0] * pl->vec[0] + C->coord[1] * pl->vec[1]
			+ C->coord[2] * pl->vec[2] + d) / (vector[0] * pl->vec[0]
				+ vector[1] * pl->vec[1] + vector[2] * pl->vec[2]);
	if (isnan(proj))
		return (free(inters), NULL);
	i = -1;
	while (++i < 3)
		inters[i] = C->coord[i] + proj * vector[i];
	return (inters);
}
