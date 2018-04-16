/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:58:08 by gmachena          #+#    #+#             */
/*   Updated: 2017/05/11 04:41:33 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_sort(t_attr ***list, int (*compare)(t_attr *, t_attr *))
{
	t_attr	**ptr;
	t_attr	*tmp;
	int		i;
	int		j;

	i = 1;
	j = -1;
	ptr = *list;
	while (i)
	{
		i = 0;
		j = -1;
		ptr = *list;
		while (ptr[++j + 1])
		{
			if (compare(ptr[j], ptr[j + 1]) > 0)
			{
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
				i = 1;
			}
		}
	}
}
