/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:17 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/25 16:30:03 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../frameworks/SDL2.framework/Headers/SDL.h"

# define WIN_X e->width
# define WIN_Y e->height
# define THREADS 128
# define VIEWP e->camera->viewp
# define POW2(x) (x * x)
# define FOCALE 300

typedef struct		s_rgb
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}					t_rgb;

typedef	struct		s_mat
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	reflection;
	double	refraction;
}					t_mat;

typedef	struct		s_plane
{
	t_vect		pos;
	t_vect		norm;
	t_vect		rotate;
	t_vect		interpos;
	t_vect		internorm;
	int			damnier;
	unsigned int color;
	double		inter;
	int			proc;
	SDL_Surface	*text;
	t_mat		mat;
}					t_plane;

typedef	struct		s_cone
{
	t_vect		pos;
	t_vect		rotate;
	t_vect		interpos;
	t_vect		internorm;
	double		angle;
	unsigned int color;
	int			proc;
	double		inter;
	SDL_Surface	*text;
	t_mat		mat;
}					t_cone;

typedef	struct		s_sphere
{
	t_vect			pos;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	double			radius;
	unsigned int	color;
	double			inter;
	int				proc;
	SDL_Surface		*text;
	t_mat			mat;
}					t_sphere;

typedef	struct		s_cylinder
{
	t_vect		pos;
	t_vect		rotate;
	t_vect		interpos;
	t_vect		internorm;
	float		radius;
	unsigned int color;
	double		inter;
	int			proc;
	SDL_Surface	*text;
	t_mat		mat;
}					t_cylinder;

typedef	struct		s_light
{
	t_vect		pos;
	t_vect		vect;
	double		norm_obj;
	double		prod_scal;
	double		norm_l;
	double		intensity;
	unsigned int color;
	unsigned int color_p;
}					t_light;

typedef struct		s_camera
{
	t_vect		v;
	t_vect		angle;
	t_vect		pos;
	double		prod_scal;
}					t_camera;

typedef struct		s_virt
{
	t_vect		pos;
	t_vect		angle;
	t_vect		v;
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
    SDL_Window  	*win;
    SDL_Renderer 	*renderer;
    SDL_Event   	events;
	char			*filename;
	int				width;
	int				height;
	int				fd;
	int				recursivity;
	int				antialias;
	double			diaphragm;
	unsigned int 	ambient_light;
	int				filter;
	unsigned int	ambientcolor;
	int				proc;
	t_rgb			**rgb;
	t_objnb			*objnb;
	t_camera		*camera;
	t_light			**light;
	t_plane			**plane;
	t_cone			**cone;
	t_cylinder		**cylinder;
	t_sphere		**sphere;
	t_virt			virt_e;
}					t_env;

typedef struct		s_thread
{
	int				recursivity;
	int				tid;
	char			*name;
	int				number;
	unsigned int	color;
	double			value;
	t_light			light;
	t_vect			pos;
	double			ar;
	t_mat			mat;
	t_vect			rotate;
	t_vect			interpos;
	t_vect			internorm;
	t_camera		cam;
	t_env			*e;
	int				x;
	int				y;
}					t_thread;

int				parse_texture(char *str, SDL_Surface *text);
void			main_post_treatment(t_env *e);
unsigned int	parse_hexa(char *str);
double			parse_double(char *str, double min, double max);
int				parse_int(char *str, int min, int max);
double			fresnel(t_thread *thr);
unsigned int	refracted(t_thread *thr, unsigned int color, double kr);
t_vect			vectcpy(t_vect v);
void			ft_post_sphere(t_thread *thr, unsigned int *tmp);
void			ft_post_cylinder(t_thread *thr, unsigned int *tmp);
void			ft_post_plane(t_thread *thr, unsigned int *tmp);
void			ft_post_cone(t_thread *thr, unsigned int *tmp);
t_mat			ft_mat_init();
int             ft_close(void *param);
void            re_draw(t_env *e);
void 			ft_print_obj(t_thread *thr, int i);
int				ft_isview(double *obj, int i);
unsigned int	ft_load_post(t_thread *thr, int i, double obj);
void 			ft_rotate_x(double *y, double *z, double angle);
void 			ft_rotate_y(double *x, double *z, double angle);
void 			ft_rotate_z(double *x, double *y, double angle);
t_env			*ft_rotate(t_env *e);
double			ft_calc_sphere(t_sphere *sphere, t_camera *camera);
double			ft_calc_plan(t_plane *plan, t_camera *camera);
double			ft_calc_cylinder(t_cylinder *cylinder, t_camera *camera);
double			ft_calc_cone(t_cone *cone, t_camera *camera);
int				ft_shadow_sphere(t_thread *thr, int i, t_camera *shadow_eye);
int				ft_shadow_cone(t_thread *thr, int i, t_camera *shadow_eye);
int 			ft_is_shadow(t_thread *thr, t_light *light);
void 			ft_rt(t_env *e);
unsigned int	ft_light(t_thread *thr, t_light *light, unsigned int tmp);
void			ft_error(char *str);
char			**ft_parse_file(t_env *e);
t_vect			*ft_parse_coords(t_vect *pos, char *str);
int				ft_parse_cone(t_env *e, char **eab);
int				ft_parse_cylinder(t_env *e, char **eab);
int				ft_parse_sphere(t_env *e, char **eab);
int				ft_parse_camera(t_env *e, char **eab);
int				ft_parse_light(t_env *e, char **eab);
int				ft_parse_plane(t_env *e, char **eab);
int				ft_shadow_cylinder(t_thread *thr, int i, t_camera *shadow_eye);
t_env			*init(char *filename);
int				ft_parse_main_properties(t_env *e, char *str, int i);
int				ft_is_shape_named(char *str1, char *str2);
char			*ft_concat_c_params(char *str1, const char *str2, char c);
void			debug(char *str, t_vect vect);
void			rgb_mult(unsigned int *color, double f);
unsigned int	refleted(t_thread *thr, unsigned int color, double kr);
unsigned int	damier(t_thread *thr);
void            sdl_loop(t_env *e);
void            free_sdl(t_env *e);
void			rgb_addf(unsigned int *color, double d);
unsigned int 	ft_calc_obj(t_thread *thr, int recursivity);
int				parse_filter(char *str);
double 			damier_trou(t_thread *thr);
void			applied_green(t_env *e);
void			applied_red(t_env *e);
void			applied_yellow(t_env *e);
void			applied_sepia(t_env *e);
void			applied_negative(t_env *e);
void			green(t_rgb *v);
void			red(t_rgb *v);
void			yellow(t_rgb *v);
void			sepia(t_rgb *v);
void			negative(t_rgb *v);
int				len_rgb(t_env *e);
void			ft_export(t_env *e);
#endif
