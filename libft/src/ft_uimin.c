/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:54:48 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/19 13:24:00 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	uimin(unsigned int a, unsigned int b)
{
	if ( a > b)
		return (b);
	else
		return (a);
}