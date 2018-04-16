/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:32:28 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 00:19:53 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tab;
	const char	*tabs;
	size_t		i;

	tab = dst;
	tabs = src;
	i = 0;
	while (i < n)
	{
		tab[i] = tabs[i];
		i++;
	}
	return (dst);
}
