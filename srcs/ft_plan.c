/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:02:36 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 18:23:36 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_save_inter_plan(t_thread *thr, \
		t_plane *plane, t_camera *camera)
{
	thr->internorm = coord_v(0, 1, 0);
	thr->interpos = vectadd(camera->pos, vmult(camera->v, thr->value));
	thr->internorm = vrotateinv(thr->internorm, plane->rotate);
}

void			ft_post_plane(t_thread *thr, unsigned int *tmp)
{
	int	i;

	i = thr->number;
	thr->pos = thr->e->plane[i]->pos;
	thr->rotate = thr->e->plane[i]->rotate;
	ft_save_inter_plan(thr, thr->e->plane[i], &thr->cam);
	if (thr->e->plane[i]->proc == 1)
		*tmp = damier(thr);
	else if (thr->e->plane[i]->proc == 2)
	{
		thr->mat.refraction = damier_trou(thr);
		*tmp = thr->e->plane[i]->color;
	}
	else
		*tmp = thr->e->plane[i]->color;
}

static double	ft_calc_inter_plan(t_vect pos, t_vect vect)
{
	double		inter;

	inter = pos.y / vect.y;
	inter = -inter;
	if (inter < 0.0001)
		return (0);
	return (inter);
}

double			ft_calc_plan(t_plane *plane, t_camera *camera)
{
	t_vect		pos;
	t_vect		vect;
	double		inter;

		inter = 0;
		pos = vrotate(vectsub(camera->pos, plane->pos), plane->rotate);
		vect = vrotate(camera->v, plane->rotate);
		if ((ABS(vect.y)) < 0.0001)
			return (0);
		inter = ft_calc_inter_plan(pos, vect);
		return (inter);
}
