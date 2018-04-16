/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 03:53:07 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/17 03:53:48 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*tab;
	int		i;
	int		j;

	if (s == 0)
		return (0);
	i = 0;
	j = ft_strlen(s);
	while ((*(s + i) == c))
		i++;
	while ((*(s + (j - 1)) == c) && j > i)
		j--;
	tab = ft_strsub(s, i, (j - i));
	return (tab);
}
