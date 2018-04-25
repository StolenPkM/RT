/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yellow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:46:17 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 11:49:32 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			yellow(t_rgb *v)
{
	t_rgb		n;
	float		opacite;

	opacite = 0.6;
	n.r = v->r * (1 - opacite) + 255 * opacite;
	n.g = v->g * (1 - opacite) + 255 * opacite;
	n.b = v->b * (1 - opacite) + 0 * opacite;
	v->r = n.r;
	v->g = n.g;
	v->b = n.b;
}

void			applied_yellow(t_env *e)
{
	int			i;

	i = 0;
	while (((i % WIN_X) < WIN_X) && ((i / WIN_X) < WIN_Y))
	{
		yellow(e->rgb[i]);
		i++;
	}
}
