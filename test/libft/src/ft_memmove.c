/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 06:30:51 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/19 00:22:59 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	size_t	i;
	char	*tab_src;
	char	*tab_dst;

	i = -1;
	tab_src = (char*)src;
	tab_dst = (char*)dst;
	if (tab_src < tab_dst)
		while ((int)(--n) >= 0)
			tab_dst[n] = tab_src[n];
	else
		while (++i < n)
			tab_dst[i] = tab_src[i];
	return (dst);
}
