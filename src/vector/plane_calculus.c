#include <miniRT.h>

t_util_plane	pleq(t_vector n, t_vector p)
{
	t_util_plane	plane;
	float	d;

	d = -1 * (n.x * p.x + n.y * p.y + n.z * p.z);
	plane.a = n.x;
	plane.b = n.y;
	plane.c = n.z;
	plane.d = d;
	return (plane);
}
