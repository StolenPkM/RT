/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phamelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:03 by phamelin          #+#    #+#             */
/*   Updated: 2018/04/24 16:24:41 by phamelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(unsigned int n)
{
	int		temp;
	int		l;
	char	*res;

	temp = n;
	l = 2;
	while (temp /= 10)
		l++;
	if ((res = (char *)malloc(sizeof(char) * l)) == NULL)
		return (NULL);
	res[--l] = '\0';
	while (l--)
	{
		res[l] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
