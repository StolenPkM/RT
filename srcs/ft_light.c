/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:24:29 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 17:48:40 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	g_x;
int g_y;

static double		ft_cos_a(t_thread *thr, t_light *light)
{
	double	cos_a;
	double	intensity;

	light->prod_scal = dot(light->vect, thr->internorm);
	light->norm_l = norm(light->vect);
	light->norm_obj = norm(thr->internorm);
	intensity = fclamp((light->intensity / POW2(light->norm_l)), 0, 1.0);
	cos_a = -1;
	if (light->norm_l * light->norm_obj != 0)
		cos_a = (light->prod_scal / (light->norm_l * light->norm_obj)) \
				* intensity * thr->mat.diffuse;
	return (cos_a);
}

void				rgb_mult(unsigned int *color, double f)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	inv;

	inv = (*color / 0x1000000);
	*color = *color % 0x1000000;
	r = (*color / 0x10000) * f;
	*color = *color % 0x10000;
	g = (*color / 0x100) * f;
	*color = *color % 0x100;
	b = *color * f;
	*color = (inv * 0x1000000) + (r * 0x10000) + (g * 0x100) + b;
}

void				rgb_addf(unsigned int *color, double d)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	inv;

	inv = (*color / 0x1000000);
	*color = *color % 0x1000000;
	r = (*color / 0x10000) + d;
	uiclamp(&r, 0, 255);
	*color = *color % 0x10000;
	g = (*color / 0x100) + d;
	uiclamp(&g, 0, 255);
	*color = *color % 0x100;
	b = *color + d;
	uiclamp(&b, 0, 255);
	*color = (inv * 0x1000000) + (r * 0x10000) + (g * 0x100) + b;
}

double				fmax(double reflet, double d)
{
	if (reflet < d)
		return (d);
	return (reflet);
}

unsigned int		ft_light(t_thread *thr, t_light *light, unsigned int tmp)
{
	unsigned int	color;
	double			cos_a;
	t_vect			reflet;
	t_vect			cam;
	double			spec;

	color = tmp;
	light->vect = vectsub(light->pos, thr->interpos);
	if (ft_is_shadow(thr, light))
		return (0xFF000000);
	if ((cos_a = ft_cos_a(thr, light)) < 0.0001)
		return (0xFF000000);
	rgb_mult(&color, cos_a);
	reflet = vectsub(vmult(vmult(thr->internorm, dot(thr->internorm, \
						light->vect)), 2), light->vect);
	reflet = normalize(reflet);
	cam = vectsub(thr->e->camera->pos, thr->interpos);
	cam = normalize(cam);
	spec = pow(fmax(dot(reflet, cam), 0), 500) * 500;
	if (spec > 0)
		rgb_addf(&color, (spec * thr->mat.specular * \
					fclamp((light->intensity / POW2(light->norm_l)), 0, 1.0)));
	return (color);
}
