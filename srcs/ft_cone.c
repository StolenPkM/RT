/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:10:19 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 17:34:49 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_save_inter_cone(t_thread *thr, t_cone *cone, \
		t_camera *camera)
{
	t_vect		norm;
	double		dotc;

	dotc = 0;
	norm = vrotateinv(coord_v(0, 1, 0), cone->rotate);
	thr->interpos = vectadd(camera->pos, vmult(camera->v, thr->value));
	thr->internorm = vectsub(thr->interpos, cone->pos);
	dotc = dot(norm, thr->internorm);
	thr->internorm = vectsub(thr->internorm, vmult(norm, dotc));
	thr->internorm = normalize(thr->internorm);
}

void			ft_post_cone(t_thread *thr, unsigned int *tmp)
{
	int			i;

	i = thr->number;
	thr->ar = thr->e->cone[i]->angle;
	thr->pos = thr->e->cone[i]->pos;
	thr->rotate = thr->e->cone[i]->rotate;
	ft_save_inter_cone(thr, thr->e->cone[i], &thr->cam);
	*tmp = thr->e->cone[i]->color;
}

static double	ft_calc_inter_cone(t_cone *cone, t_vect pos, t_vect vect)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		tmp;

	delta = 0;
	tmp = tan((cone->angle * (M_PI / 180)));
	a = (vect.z * vect.z) + (vect.x * vect.x)
		- ((vect.y * vect.y) * tmp);
	b = (2.0 * pos.z * vect.z) + (2.0 * pos.x * vect.x)
		- ((2.0 * pos.y * vect.y) * tmp);
	c = (pos.z * pos.z) + (pos.x * pos.x)
		- ((pos.y * pos.y) * tmp);
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0.0)
	{
		return (0);
	}
	else
		return (ft_eq_second(delta, a, b));
}

double			ft_calc_cone(t_cone *cone, t_camera *camera)
{
	t_vect		pos;
	t_vect		vect;
	double		inter;

	inter = 0;
	pos = vrotate(vectsub(camera->pos, cone->pos), cone->rotate);
	vect = vrotate(camera->v, cone->rotate);
	if ((inter = ft_calc_inter_cone(cone, pos, vect)) < 0.0001)
		return (0);
	return (inter);
}
