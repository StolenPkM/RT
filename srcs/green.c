/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   green.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:48:23 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 11:54:30 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			green(t_rgb *v)
{
	t_rgb		n;
	float		opacite;

	opacite = 1.0 - 0.6;
	n.r = v->r * (opacite);
	n.g = v->g * (opacite) + 255 * (1.0 - opacite);
	n.b = v->b * (opacite);
	v->r = n.r;
	v->g = n.g;
	v->b = n.b;
}

void			applied_green(t_env *e)
{
	int			i;

	i = 0;
	while (((i % WIN_X) < WIN_X) && ((i / WIN_X) < WIN_Y))
	{
		green(e->rgb[i]);
		i++;
	}
}
