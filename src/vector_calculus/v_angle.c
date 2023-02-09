//#include <miniRT.h>
//#include <vecpix.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
/*
float	v_angle(float v1[3], float v2[3])
{
	float	angle;

	angle = escalar_prod(v1, v2) / (sqrt(escalar_prod(v1, v1)) * sqrt(escalar_prod(v2, v2)));
	return (angle);
}
*/
float	**matrix_prod(float **m1, float **m2)
{
	int	i;
	int	j;
	int	k;
	float	sum;
	float	**m3;

	m3 = malloc(sizeof(float *) * 3);
	i = 0;
	j = 0;
	k = 0;
	sum = 0;
	while (i < 3)
		m3[i++] = malloc(sizeof(float) * 3);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			sum = 0;
			k = 0;
			while (k < 3)
			{
				sum += m1[i][k] * m2[k][j];
				k++;
			}
			m3[i][j] = sum;
			j++;
		}
		i++;
	}
	return (m3);
}

int	main()
{
	 float **A = (float **)malloc(3 * sizeof(float *));
  for (int i = 0; i < 3; i++) {
    A[i] = (float *)malloc(3 * sizeof(float));
  }
  A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
  A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
  A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

  float **B = (float **)malloc(3 * sizeof(float *));
  for (int i = 0; i < 3; i++) {
    B[i] = (float *)malloc(3 * sizeof(float));
  }
  B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
  B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
  B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;
	float **c;

	c = matrix_prod(A, B);
	int	i, j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			printf("%f   ", c[i][j++]);
		}
		j = 0;
		i++;
		printf("\n");
	}
	return (0);
}
