/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:17:16 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 18:38:37 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double				fresnel(t_thread *thr)
{
	double			kr;
	double			cosi;
	double			etai;
	double			sint;
	double			cost;
	double			rs;
	double			rp;
	double			refraction;

	etai = 1;
	refraction = thr->mat.refraction;
	cosi = fclamp(dot(thr->internorm, thr->cam.v), -1.0, 1.0);
	if (cosi > 0)
	{
		sint = etai;
		etai = refraction;
		refraction = sint;
	}
	sint = etai / refraction * sqrt(fclamp((1 - cosi * cosi), 0, 400000));
	if (sint >= 1.00)
		kr = 1.00;
	else
	{
		cost = sqrt(fclamp((1 - sint * sint), 0, 400000));
		cosi = ABS(cosi);
		rs = ((refraction * cosi) - (etai * cost)) / ((refraction * cosi) + \
				(etai * cost));
		rp = ((etai * cosi) - (refraction * cost)) / ((etai * cosi) + \
				(refraction * cost));
		kr = (rs * rs + rp * rp) / 2.0;
	}
	return (kr);
}

t_vect				refracted2(t_thread *thr)
{
	double			refraction;
	double			cosi;
	double			etai;
	double			eta;
	double			k;
	t_vect			v;

	etai = 1;
	v = thr->internorm;
	refraction = thr->mat.refraction;
	cosi = fclamp(dot(thr->internorm, thr->cam.v), -1.0, 1.0);
	if (cosi < 0)
		cosi = -cosi;
	else
	{
		eta = refraction;
		refraction = etai;
		etai = eta;
		v = vmult(v, -1);
	}
	eta = etai / refraction;
	k = 1.0 - eta * eta * (1.0 - cosi * cosi);
	return (k < 0.0 ? coord_v(0, 0, 0) : vectadd(vmult(thr->cam.v, eta), \
				vmult(v, (eta * cosi - sqrt(k)))));
}

unsigned int		refracted(t_thread *thr, unsigned int color, double kr)
{
	unsigned int	tmp;
	double			refraction;

	tmp = 0;
	refraction = thr->mat.refraction;
	thr->cam.pos = thr->interpos;
	thr->cam.v = refracted2(thr);
	thr->cam.v = normalize(thr->cam.v);
	tmp = ft_calc_obj(thr, (thr->recursivity - 1));
	rgb_mult(&color, (1 - refraction));
	if (thr->value > 0.0001)
	{
		rgb_mult(&tmp, (1 - kr));
		rgb_add(&color, tmp);
	}
	return (color);
}
unsigned int		refleted(t_thread *thr, unsigned int color, double kr)
{
	unsigned int	tmp;
	double			reflection;

	tmp = 0;
	reflection = thr->mat.reflection;
	thr->cam.pos = thr->interpos;
	thr->cam.v = vectsub(thr->cam.v, vmult(vmult(thr->internorm, \
					dot(thr->internorm, thr->cam.v)), 2));
	thr->cam.v = normalize(thr->cam.v);
	tmp = ft_calc_obj(thr, (thr->recursivity - 1));
	rgb_mult(&color, (1 - reflection));
	if (thr->value > 0.0001)
	{
		rgb_mult(&tmp, kr);
		rgb_add(&color, tmp);
	}
	return (color);
}
