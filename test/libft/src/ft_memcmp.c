/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 07:53:08 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 00:18:39 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char*)s1;
	tab2 = (unsigned char*)s2;
	i = 0;
	while (i < n && tab1[i] == tab2[i])
		i++;
	if (i == n)
		return (0);
	return (tab1[i] - tab2[i]);
}
