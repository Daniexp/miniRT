#ifndef MINIRT_H
# define MINIRT_H
# include <libft.h>
# include <MLX42.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

/*	STRUCTURES	*/
typedef struct s_ambient_light
{
	float	rate;
	int	rgb[3];
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
	t_list**	sp;
	t_list**	cy;
	t_list**	pl;
	t_light		L;
	t_camera	C;
	t_ambient	A;
}	t_scene;
/*	PROTOTYPES	*/

/* UTILS */
int	input_error(int arg);
void	error_msg(char *s);
void	vcpy(float src[3], float dst[3]);
char	*quit_c(char *s, char c);

/* PARSE */
int		open_file(char *s);
int		check_extension(char *s);
int		fill_scene(int fd, t_scene *scene);
int		parse(char *s, t_scene *scene);
float	atofelio(char *s);
int		check_all_nb(char *s);
int		double_pointier_len(char **s);
int		ambient(char **line_content, t_scene *scene, int n_line);

#endif
