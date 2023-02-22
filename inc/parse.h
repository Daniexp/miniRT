/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:31:12 by ndonaire          #+#    #+#             */
/*   Updated: 2023/02/22 09:34:43 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <miniRT.h>
/* UTILS */
int	input_error(int arg);
void	error_msg(char *s);
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
int		check_vec3d(char **vec);
int		sphere_check(char **line_content, t_scene *scene, int n_line);
int		error_id(int n_line, int ref);
int		pre_read(int fd, t_scene *scene);
void		fill_cylinder(char **coor, char **vec, char **rgb, char **line_content, t_cylinder *cy);
int		plane_check(char **line_content, t_scene*scene, int n_line);
void	fill_plane(char **coor, char **vec, char **rgb, t_plane *plane);
#endif
