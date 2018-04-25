/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 06:21:42 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 00:17:45 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = -1;
	if (!(tab = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
		tab[i] = '\0';
	return (tab);
}
