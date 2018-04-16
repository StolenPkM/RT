/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <pabonnin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:11:51 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/13 17:21:20 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include <SDL2/sdl.h>

# define WIN_X e->width
# define WIN_Y e->height
# define RED  0xFF000000
# define GREEN 0x00FF0000
# define BLUE 0x0000FF00
# define THREADS 128
# define VIEWP e->camera->viewp
# define POW2(x) (x * x)
# define FOCALE 300

typedef struct		s_mat
{
	double			ambient;
	double			diffuse;
	double			specular;
	double			reflection;
	double			refraction;
}					t_mat;

typedef struct		s_plane
{
	t_vect			pos;
	t_vect			norm;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	int				damnier;
	unsigned int	color;
	double			inter;
	t_mat			mat;
}					t_plane;

typedef struct		s_cone
{
	t_vect			pos;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	double			angle;
	unsigned int	color;
	double			inter;
	t_mat			mat;
}					t_cone;

typedef struct		s_sphere
{
	t_vect			pos;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	double			radius;
	unsigned int	color;
	double			inter;
	t_mat			mat;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vect			pos;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	float			radius;
	unsigned int	color;
	double			inter;
	t_mat			mat;
}					t_cylinder;

typedef struct		s_light
{
	t_vect			pos;
	t_vect			vect;
	double			norm_obj;
	double			prod_scal;
	double			norm_l;
	double			intensity;
	unsigned int	color;
	unsigned int	color_p;
}					t_light;

typedef struct		s_camera
{
	t_vect			v;
	t_vect			angle;
	t_vect			pos;
	double			prod_scal;
}					t_camera;

typedef struct		s_virt
{
	t_vect			pos;
	t_vect			angle;
	t_vect			v;
}					t_virt;

typedef struct		s_objnb
{
	int				sphere;
	int				cylinder;
	int				cone;
	int				light;
	int				plane;
	int				totobj;
}					t_objnb;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		events;
	Uint8			type;
	int				width;
	int				height;
	char			*filename;
	int				fd;
	int				recursivity;
	int				antialias;
	double			diaphragm;
	unsigned int	ambient_light;
	t_objnb			*objnb;
	t_camera		*camera;
	t_light			**light;
	t_plane			**plane;
	t_cone			**cone;
	t_cylinder		**cylinder;
	t_sphere		**sphere;
	t_virt			virt_e;
}					t_env;


t_env				*init(char *filename);
int					init_sdl(t_env *e);
unsigned			 intparse_hexa(char *str, unsigned int min,	 unsigned int max);
int					parse_int(char *str, int min, int max);
t_vect				vectcpy(t_vect v);
t_mat				ft_mat_init();
int					ft_close(void *param);
int					ft_isview(double *obj, int i);
t_env				*ft_rotate(t_env *e);
void				ft_error(char *str);
char**				ft_parse_file(t_env *e);
t_vect				*ft_parse_coords(t_vect *pos, char *str);
int					ft_parse_cone(t_env		*e, char **eab);
int					ft_parse_cylinder(t_env *e, char **eab);
int					ft_parse_sphere(t_env *e, char **eab);
int					ft_parse_camera(t_env *e, char **eab);
int					ft_parse_light(t_env *e, char **eab);
int					ft_parse_plane(t_env *e, char **eab);
double				parse_double(char *str,double min, double max);
int					ft_parse_main_properties(t_env *e, char *str);
int					ft_is_shape_named(char *str1, char *str2);
char*				ft_concat_c_params(char *str1, const char *str2, char c);
void				rgb_mult(unsigned int *color, double f);
#endif
