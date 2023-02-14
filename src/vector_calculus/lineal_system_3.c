#include <miniRT.h>
#include <vecpix.h>

float* system_lineal(float* a, float* b, float* c)
{
	float detA, detX, detY, detZ;
	float* result = (float*)malloc(3 * sizeof(float));

	detA = a[0] * b[1] * c[2] + b[0] * c[1] * a[2] + c[0] * a[1] * b[2] - a[2] * b[1] * c[0] - b[2] * c[1] * a[0] - c[2] * a[1] * b[0];
	detX = a[3] * b[1] * c[2] + b[3] * c[1] * a[2] + c[3] * a[1] * b[2] - a[2] * b[1] * c[3] - b[2] * c[1] * a[3] - c[2] * a[1] * b[3];
	detY = a[0] * b[3] * c[2] + b[0] * c[3] * a[2] + c[0] * a[3] * b[2] - a[2] * b[3] * c[0] - b[2] * c[3] * a[0] - c[2] * a[3] * b[0];
	detZ = a[0] * b[1] * c[3] + b[0] * c[1] * a[3] + c[0] * a[1] * b[3] - a[3] * b[1] * c[0] - b[3] * c[1] * a[0] - c[3] * a[1] * b[0];
	result[0] = detX / detA;
	result[1] = detY / detA;
	result[2] = detZ / detA;
	return (result);
}

float* three_one(float** three, float* one)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
     	float* result = (float*)malloc(sizeof(float) * 3); // Reservamos memoria para el resultado
							   //
	while (i < 3)
	{
       		result[i] = 0;
		j = 0;
		while (j < 3)
		{
			result[i] += three[i][j] * one[j];
			j++;
		}
	       	i++;
	 }

      	 return (result);
}
