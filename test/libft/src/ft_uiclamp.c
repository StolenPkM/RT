/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uiclamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:28:04 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/16 15:30:05 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	uiclamp(unsigned int *ui, unsigned int min, unsigned int max)
{
	if (*ui > max)
		*ui = max;
	if (*ui < min)
		*ui = min;
}

void	iclamp(int *ui, int min, int max)
{
	if (*ui > max)
		*ui = max;
	if (*ui < min)
		*ui = min;
}
