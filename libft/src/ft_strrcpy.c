/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:52:54 by acoudray          #+#    #+#             */
/*   Updated: 2018/03/09 16:45:23 by tlecas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrcpy(const char *src, size_t from)
{
	int		i;
	char	*dst;

	dst = 0;
	if (!(src))
		return (0);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) - (int)from + 1))))
		return (0);
	i = -1;
	while (src[from - 1])
	{
		dst[++i] = src[from];
		from++;
	}
	dst[i] = 0;
	return (dst);
}
