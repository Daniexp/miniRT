/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:10:58 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/02 21:27:44 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON  0.001
# define THETA	0.5
#define WIDTH 800
#define HEIGHT 600

/*	PROTOTYPES	*/
# include <libft.h>
# include <MLX42.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <float.h>

/*	STRUCTURES	*/
typedef struct s_plane
{
	float			coord[3];
	float			vec[3];
	unsigned int	rgb[3];
	int		shthis;
}	t_plane;

typedef struct s_cylinder
{
	float			coord[3];
	float			vec[3];
	float			d;
	float			h;
	unsigned int	rgb[3];
	int		shthis;
}	t_cylinder;

typedef struct s_camera
{
	float			coord[3];
	float			vec[3];
	unsigned int	fov;
}	t_camera;

typedef struct s_ambient_light
{
	float			rate;
	unsigned int	rgb[3];
}	t_ambient;

typedef struct s_light
{
	float			coord[3];
	float			rate;
}	t_light;

typedef struct s_sphere
{
	float			coord[3];
	float			d;
	unsigned int	rgb[3];
	int		shthis;
}	t_sphere;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	null;
}	t_vector;

typedef struct s_util_plane
{
	float	a;
	float	b;
	float	c;
	float	d;
}	t_util_plane;

typedef struct	s_scene
{
	t_list		**sp;
	t_list		**cy;
	t_list		**pl;
	t_light		L;
	t_camera	C;
	t_ambient	A;
	int			n_A;
	int			n_C;
	int			n_L;
	int			n_sp;
	int			n_pl;
	int			n_cy;
	int			exit;
}	t_scene;



/*	PROTOTYPES	*/

# include <vector.h>
# include <pixel.h>
# include <rotate.h>
# include <intersection.h>
# include <shadows.h>
# include <colors.h>
/* UTILS */
int		input_error(int arg);
int		error_msg(char *s);
void	vcpy(float src[3], float dst[3]);
char	*quit_c(char *s, char c);
int		check_range(float n, float origin, float last);
void	free_arg(char **s);

/* PARSE */
void	fill_ambient(char **rgb, char *line_content, t_scene *scene);
int		open_file(char *s);
int		check_extension(char *s);
int		fill_scene(int fd, t_scene *scene);
int		parse(char *s, t_scene *scene);
float	atofelio(char *s);
int		check_all_nb(char *s);
int		double_pointier_len(char **s);
int		ambient(char **line_content, t_scene *scene, int n_line);
void	fill_ambient(char **rgb, char *line_content, t_scene *scene);
void	fill_camera(char **coord, char **vec, char *fov, t_scene *scene);
int		camera(char **line_content, t_scene *scene, int n_line);
int		light(char	**coor, t_scene *scene, int n_line);
void	fill_light(char **coor, float rate, t_scene *scene);
void	fill_sphere(char **coor, char *d, char **rgb, t_sphere *sp);
int		check_vec3d(char **vec, int c);
int		sphere_check(char **line_content, t_scene *scene, int n_line);
int		error_id(int n_line, int ref);
int		pre_read(int fd, t_scene *scene);
void		fill_cylinder(char **coor, char **vec, char **rgb, t_cylinder *cy);
void		fill_cylinder_ii(char **line_content, t_cylinder *cy);
int		plane_check(char **line_content, t_scene*scene, int n_line);
void	fill_plane(char **coor, char **vec, char **rgb, t_plane *plane);
int		cylinder_check(char **line_content, t_scene*scene, int n_line);
int		add_cy(t_scene *scene, t_cylinder *cy);
int		add_pl(t_scene *scene, t_plane *pl);
void	threeforfree(char **a, char **b, char **c);
int		error_params(int n_line, int mode, char **v1, char **v2);
void	threeforfree(char **a, char **b, char **c);
int	iscamera_inside(t_scene *scene);
int	islight_inside(t_scene *scene);
int		check_all_normalized(t_scene *scene);
void	leaks();
void	freeScene(t_scene *scene);
int		islight_incylinder(t_scene *scene, t_cylinder *cy);
int		check_light_cylinder(t_scene *scene);
float		*fdup(float *v);
int		is_normalize(float *vector);
#endif
