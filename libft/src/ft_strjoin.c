/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:24:32 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 00:23:45 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		size_s1;
	int		size_s2;

	i = -1;
	if (s1 == 0 || s2 == 0)
		return (0);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!(dst = (char*)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
		return (0);
	while (++i < size_s1)
		*(dst + i) = *(s1 + i);
	i--;
	while (++i < (size_s1 + size_s2))
		*(dst + i) = *(s2 + (i - size_s1));
	*(dst + i) = '\0';
	return (dst);
}
