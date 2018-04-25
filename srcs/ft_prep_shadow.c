/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_shadow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:10:20 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 18:26:59 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				ft_prepare_shadow_sphere(t_thread *thr, t_light *light)
{
	t_camera	shadow_eye;
	int			j;

	j = -1;
	shadow_eye.pos = thr->interpos;
	shadow_eye.angle = thr->cam.angle;
	shadow_eye.v = light->vect;
	while (++j < thr->e->objnb->totobj)
	{
		if (thr->number != j && j < thr->e->objnb->sphere && \
				ft_shadow_sphere(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cone && ft_shadow_cone(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cylinder && \
				ft_shadow_cylinder(thr, j, &shadow_eye))
			return (1);
	}
	return (0);
}

int				ft_prepare_shadow_plane(t_thread *thr, t_light *light)
{
	t_camera	shadow_eye;
	int			j;

	j = -1;
	shadow_eye.pos = thr->interpos;
	shadow_eye.angle = thr->cam.angle;
	shadow_eye.v = light->vect;
	while (++j < thr->e->objnb->totobj)
	{
		if (j < thr->e->objnb->sphere && ft_shadow_sphere(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cone && ft_shadow_cone(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cylinder && \
				ft_shadow_cylinder(thr, j, &shadow_eye))
			return (1);
	}
	return (0);
}

int				ft_prepare_shadow_cone(t_thread *thr, t_light *light)
{
	t_camera	shadow_eye;
	int			j;

	j = -1;
	shadow_eye.pos = thr->interpos;
	shadow_eye.angle = thr->cam.angle;
	shadow_eye.v = light->vect;
	while (++j < thr->e->objnb->totobj)
	{
		if (j < thr->e->objnb->sphere && ft_shadow_sphere(thr, j, &shadow_eye))
			return (1);
		if (thr->number != j && j < thr->e->objnb->cone && \
				ft_shadow_cone(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cylinder && \
				ft_shadow_cylinder(thr, j, &shadow_eye))
			return (1);
	}
	return (0);
}

int				ft_prepare_shadow_cylinder(t_thread *thr, t_light *light)
{
	t_camera	shadow_eye;
	int			j;

	j = -1;
	shadow_eye.pos = thr->interpos;
	shadow_eye.angle = thr->cam.angle;
	shadow_eye.v = light->vect;
	while (++j < thr->e->objnb->totobj)
	{
		if (j < thr->e->objnb->sphere && ft_shadow_sphere(thr, j, &shadow_eye))
			return (1);
		if (j < thr->e->objnb->cone && ft_shadow_cone(thr, j, &shadow_eye))
			return (1);
		if (thr->number != j && j < thr->e->objnb->cylinder && \
				ft_shadow_cylinder(thr, j, &shadow_eye))
			return (1);
	}
	return (0);
}

int				ft_is_shadow(t_thread *thr, t_light *light)
{
	if (!(ft_strcmp(thr->name, "sphere")))
		return (ft_prepare_shadow_sphere(thr, light));
	else if (!(ft_strcmp(thr->name, "plane")))
		return (ft_prepare_shadow_plane(thr, light));
	else if (!(ft_strcmp(thr->name, "cylinder")))
		return (ft_prepare_shadow_cylinder(thr, light));
	else if (!(ft_strcmp(thr->name, "cone")))
		return (ft_prepare_shadow_cone(thr, light));
	return (0);
}
