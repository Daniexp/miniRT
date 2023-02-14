#include <miniRT.h>
#include <vecpix.h>

float *matrix_prod_3x1(float **v1, float *v2)
{
	int	i;
	float	sum;
	float	*sam;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	sam = ft_calloc(3, sizeof(float));
	i = 0;
	sum = 0;
	while (i < 3)
	{
		while (j < 3)
			sum += v1[i][j++] * v2[k++];
		sam[i] = sum;
		i++;
		k = 0;
		j = 0;
	}
	return (sam);
}


float	**rotate_matrix(float v[3])
{
	float	i[3];
	float	j[3];
	float	k[3];
	float	**m1;
	float	**m2;
	float	**r_z;
	float	**r_y;
	float	**r_x;
	(void)j;
	(void)i;

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	j[0] = 0;
	j[1] = 1;
	j[2] = 0;
	k[0] = 0;
	k[1] = 0;
	k[2] = 1;
	r_z = rotate_z(v_angle(v, k));
	r_y = rotate_y(v_angle(v, j));
	r_x = rotate_x(v_angle(v, i));
	m1 = matrix_prod(r_x, r_y);
	m2 = matrix_prod(m1, r_z);
	return (m2);
}
