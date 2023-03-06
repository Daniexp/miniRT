/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testplane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:02:03 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/06 13:23:51 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <test.h>
#include <intersection.h>

void	test_pl_equation(void)
{
	float	point[3];	
	float	normal[3];	
	float	*res;


	point[0] = 2.0;
	point[1] = -2.0;
	point[2] = 1.0;
	normal[0] = 3.0;
	normal[1] = 4.0;
	normal[2] = -5.0;
	res = pl_equation(point, normal);
	printf("point : %f,%f,%f\nnormal: %f,%f,%f\n", point[0], point[1], point[2], normal[0], normal[1], normal[2]);
	printf("plane equation: %fx %fy %fz +%f\n", res[0], res[1], res[2], res[3]),
	free(res);
	point[0] = 5.0;
	normal[1] = 3.0;
	res = pl_equation(point, normal);
	printf("point : %f,%f,%f\nnormal: %f,%f,%f\n", point[0], point[1], point[2], normal[0], normal[1], normal[2]);
	printf("plane equation: %fx %fy %fz +%f\n", res[0], res[1], res[2], res[3]),
	free(res);
}
