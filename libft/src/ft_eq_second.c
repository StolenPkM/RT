/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eq_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 09:57:08 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/09 16:46:37 by tlecas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_eq_second(double delta, double a, double b)
{
	double inter1;
	double inter2;

	inter1 = 0;
	inter2 = 0;
	if (delta >= 0)
		inter1 = (-b - sqrt(delta)) / (2 * a);
	if (delta > 0)
	{
		inter2 = (-b + sqrt(delta)) / (2 * a);
		if (inter2 > 0 && inter2 < inter1)
			return (inter2);
	}
	return (inter1);
}
