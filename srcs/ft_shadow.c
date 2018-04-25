/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:01:31 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 18:44:24 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					ft_shadow_sphere(t_thread *thr, int i, t_camera *shadow_eye)
{
	t_sphere		shadow_sphere;
	double			j;

	j = 0.0;
	shadow_sphere.pos = thr->e->sphere[i]->pos;
	shadow_sphere.rotate = thr->e->sphere[i]->rotate;
	shadow_sphere.radius = thr->e->sphere[i]->radius;
	j = ft_calc_sphere(&shadow_sphere, shadow_eye);
	if (j > 0.0001 && j < 1.0001)
		return (1);
	return (0);
}

int					ft_shadow_cone(t_thread *thr, int i, t_camera *shadow_eye)
{
	t_cone			shadow_cone;
	double			j;

	j = 0.0;
	shadow_cone.pos = thr->e->cone[i]->pos;
	shadow_cone.rotate = thr->e->cone[i]->rotate;
	shadow_cone.angle = thr->e->cone[i]->angle;
	j = ft_calc_cone(&shadow_cone, shadow_eye);
	if (j > 0.0001 && j < 1.0001)
		return (1);
	return (0);
}

int					ft_shadow_cylinder(t_thread *thr, \
		int i, t_camera *shadow_eye)
{
	t_cylinder		shadow_cylinder;
	double			j;

	j = 0.0;
	shadow_cylinder.pos = thr->e->cylinder[i]->pos;
	shadow_cylinder.rotate = thr->e->cylinder[i]->rotate;
	shadow_cylinder.radius = thr->e->cylinder[i]->radius;
	j = ft_calc_cylinder(&shadow_cylinder, shadow_eye);
	if (j > 0.0001 && j < 1.0001)
		return (1);
	return (0);
}
