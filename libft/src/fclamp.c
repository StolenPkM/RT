/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fclamp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:14:11 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/16 14:16:55 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	fclamp(double d, double min, double max)
{
	if(d > max)
		d = max;
	if (d < min)
		d = min;
	return (d);
}
