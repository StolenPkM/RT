/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:16:19 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/25 12:08:49 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static unsigned int		ambient_light(t_thread *thr, unsigned int color)
{
	unsigned int		ambient;
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	unsigned int		tmp;
	unsigned int		inv;
	double				doto;

	doto = fclamp((dot(vmult(thr->cam.v, -1), \
					thr->internorm) + 0.0 * 0.15), 0, 1);
	tmp = color;
	ambient = thr->e->ambientcolor;
	inv = (ambient / 0x1000000);
	tmp = tmp % 0x1000000;
	ambient = ambient % 0x1000000;
	r = uimin((ambient / 0x10000), (tmp / 0x10000)) * thr->mat.ambient * doto;
	uiclamp(&r, 0, 255);
	tmp = tmp % 0x10000;
	ambient = ambient % 0x10000;
	g = uimin(ambient / 0x100, (tmp / 0x100)) * thr->mat.ambient * doto;
	uiclamp(&g, 0, 255);
	uimin(g, (tmp / 0x100));
	tmp = tmp % 0x100;
	ambient = ambient % 0x100;
	b = uimin(ambient, tmp) * thr->mat.ambient * doto;
	uiclamp(&b, 0, 255);
	ambient = (inv * 0x1000000) + (r * 0x10000) + (g * 0x100) + b;
	return (ambient);
}

t_mat					ft_mat_cpy(t_mat init)
{
	t_mat				mat;

	mat.ambient = init.ambient;
	mat.diffuse = init.diffuse;
	mat.specular = init.specular;
	mat.reflection = init.reflection;
	mat.refraction = init.refraction;
	return (mat);
}

static	char			*ft_which_obj(t_thread *thr, int *i)
{
	char				*name;

	name = 0;
	if (*i < thr->e->objnb->sphere)
	{
		name = ft_strdup("sphere");
		thr->mat = thr->e->sphere[*i]->mat;
	}
	else if (*i < thr->e->objnb->sphere + thr->e->objnb->plane)
	{
		name = ft_strdup("plane");
		*i -= thr->e->objnb->sphere;
		thr->mat = thr->e->plane[*i]->mat;
	}
	else if (*i < thr->e->objnb->sphere + thr->e->objnb->plane + \
			thr->e->objnb->cylinder)
	{
		name = ft_strdup("cylinder");
		*i -= thr->e->objnb->sphere + thr->e->objnb->plane;
		thr->mat = thr->e->cylinder[*i]->mat;
	}
	else if (*i < thr->e->objnb->sphere + thr->e->objnb->plane + \
			thr->e->objnb->cylinder + thr->e->objnb->cone)
	{
		name = ft_strdup("cone");
		*i -= thr->e->objnb->sphere + thr->e->objnb->plane + \
			thr->e->objnb->cylinder;
		thr->mat = thr->e->cone[*i]->mat;
	}
	return (name);
}

unsigned int			ft_load_post(t_thread *thr, int i, double obj)
{
	double				kr;
	char				*name;
	int					j;
	unsigned int		color[thr->e->objnb->light + 1];
	unsigned int		ambient;
	unsigned int		tmp;

	j = -1;
	kr = 0;
	name = 0;
	tmp = 0xFF000000;
	thr->value = obj;
	if (obj > 0.0001)
	{
		name = ft_which_obj(thr, &i);
		color[0] = 0xFF000000;
		thr->name = name;
		thr->number = i;
		thr->value = obj;
		if (!(ft_strcmp(thr->name, "sphere")))
			ft_post_sphere(thr, &tmp);
		else if (!(ft_strcmp(thr->name, "plane")))
			ft_post_plane(thr, &tmp);
		else if (!(ft_strcmp(thr->name, "cylinder")))
			ft_post_cylinder(thr, &tmp);
		else if (!(ft_strcmp(thr->name, "cone")))
			ft_post_cone(thr, &tmp);
		ambient = ambient_light(thr, tmp);
		while (++j < thr->e->objnb->light)
		{
			thr->light = *thr->e->light[j];
			color[j] = ft_light(thr, &thr->light, tmp);
		}
		j = -1;
		tmp = 0xFF000000;
		while (++j < (thr->e->objnb->light))
		{
			rgb_add(&tmp, color[j]);
			rgb_add(&tmp, ambient);
		}
		if ((thr->mat.refraction > 0.0 && thr->recursivity > 0) || \
				(thr->mat.reflection > 0.0 && thr->recursivity > 0))
		{
			kr = fresnel(thr);
			if (kr < 1)
				tmp = refracted(thr, tmp, kr);
			tmp = refleted(thr, tmp, kr);
		}
	}
	free(name);
	return (tmp);
}

int					ft_isview(double *obj, int i)
{
	int				x;
	int				j;

	j = 0;
	x = -1;
	if (i > 0)
		while (++x <= i)
		{
			if ((obj[j] == 0.0) || (obj[x] < obj[j] && \
						obj[x] != 0.0 && obj[x] > 0.0))
				j = x;
		}
	return (j);
}

void				ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
