/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:45:38 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 11:46:09 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			negative(t_rgb *v)
{
	t_rgb		n;

	n.r = 255 - v->r;
	n.g = 255 - v->g;
	n.b = 255 - v->b;
	v->r = n.r;
	v->g = n.g;
	v->b = n.b;
}

void			applied_negative(t_env *e)
{
	int			i;

	i = 0;
	while (((i % WIN_X) < WIN_X) && ((i / WIN_X) < WIN_Y))
	{
		negative(e->rgb[i]);
		i++;
	}
}
