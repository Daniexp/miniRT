#ifndef MINIRT_H
# define MINIRT_H
# include <libft.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

/*	STRUCTURES	*/
typedef struct s_ambient_light
{
	float	rate;
	unsigned int	rgb[3];
}	t_ambient;

typedef struct s_camera
{
	float			coord[3];
	float			vec[3];
	unsigned int	fov;
	
}	t_camera;

typedef struct s_light
{
	float			coord[3];
	float	rate;
}	t_light;

typedef struct s_sphere
{
	float			coord[3];
	float 	d;
	unsigned int	rgb[3];
}	t_sphere;

typedef struct s_plane
{
	float			coord[3];
	float			vec[3];
	unsigned int	rgb[3];
}	t_plane;

typedef struct s_cylinder
{
	float			coord[3];
	float			vec[3];
	float	d;
	float	h;
}	t_cylinder;

typedef struct	s_scene
{
	t_list**	obj_lst;
}	t_scene;
/*	PROTOTYPES	*/
void	kaaa(void);
#endif
