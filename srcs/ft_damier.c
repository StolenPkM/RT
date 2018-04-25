/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_damier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:58:20 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 12:39:29 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double				damier_trou(t_thread *thr)
{
	int				i;
	double			c1;
	double			c2;
	int				l;
	long int		p1;
	long int		p2;
	long int		p3;
	t_vect			p;

	i = thr->number;
	p = vrotate(thr->interpos, thr->e->plane[i]->rotate);
	l = 3;
	p1 = ((int)p.x) / l > 0 ? (p.x / l) : (p.x / l) - l;
	p2 = ((int)p.y) / l > 0 ? (p.y / l) : (p.y / l) + l;
	p3 = ((int)p.z) / l > 0 ? (p.z / l) : (p.z / l) - l;
	if ((p1 <= 0 && p2 <= 0) && 0)
	{
		c1 = 1.0;
		c2 = 0.0;
	}
	else
	{
		c1 = 0.0;
		c2 = 1.0;
	}
	if (p3 % 2 == 0)
	{
		if ((p1 % 2 == 0 && p2 % 2 == 0) || (p1 % 2 != 0 && p2 % 2 != 0))
			return (c1);
		else
			return (c2);
	}
	else
	{
		if ((p1 % 2 == 0 && p2 % 2 == 0) || (p1 % 2 != 0 && p2 % 2 != 0))
			return (c2);
		else
			return (c1);
	}
}

unsigned int		choose_c(int i, int j, unsigned int c1, unsigned int c2)
{
	if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
		return (c1);
	else
		return (c2);
}

unsigned int		damier(t_thread *thr)
{
	unsigned int	c1;
	unsigned int	c2;
	int				t[5];
	t_vect			p;

	t[0] = thr->number;
	p = vrotate(thr->interpos, thr->e->plane[t[0]]->rotate);
	t[1] = 3;
	t[2] = ((int)(p.x) / t[1]) > 0.0001 ? (p.x / t[1]) : (p.x / t[1]) - t[1];
	t[3] = ((int)(p.y) / t[1]) > 0.0001 ? (p.y / t[1]) : (p.y / t[1]) + t[1];
	t[4] = ((int)(p.z) / t[1]) > 0.0001 ? (p.z / t[1]) : (p.z / t[1]) - t[1];
	if ((t[2] <= 0 && t[3] <= 0) && 0)
	{
		c1 = 0xFF00FF00;
		c2 = 0xFFFF0000;
	}
	else
	{
		c1 = 0xFFFF0000;
		c2 = 0xFF00FF00;
	}
	if (t[4] % 2 == 0)
		return (choose_c(t[2], t[3], c1, c2));
	else
		return (choose_c(t[2], t[3], c1, c2));
}
