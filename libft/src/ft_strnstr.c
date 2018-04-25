/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:31:53 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 00:17:14 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;
	int		z;

	i = 0;
	z = 0;
	j = ft_strlen(little);
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && j <= len)
	{
		if (big[i] == little[0] && (j + z) <= len)
		{
			big = &big[i];
			if ((ft_strncmp(big, little, j)) == 0)
				return ((char*)big);
			i = 0;
		}
		i++;
		z++;
	}
	return (0);
}
