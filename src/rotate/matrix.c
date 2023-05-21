#include <miniRT.h>

t_vector	matrix_vector_product(t_vector *matrix, t_vector v)
{
	t_vector	new;

	new.x = matrix[1].x * v.x + matrix[1].y *v.y + matrix[1].z * v.z;
	new.y = matrix[2].x * v.x + matrix[2].y *v.y + matrix[2].z * v.z;
	new.z = matrix[3].x * v.x + matrix[3].y *v.y + matrix[3].z * v.z;
	return new;
}

void	vectoflo(float f[3], t_vector v)
{
	f[0] = v.x;
	f[1] = v.y;
	f[2] = v.z;
}
