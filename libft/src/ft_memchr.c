/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 07:30:56 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 04:15:10 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = -1;
	tab = (unsigned char*)s;
	while (++i < n)
		if (tab[i] == (unsigned char)c)
		{
			tab = &tab[i];
			return (tab);
		}
	return (0);
}
