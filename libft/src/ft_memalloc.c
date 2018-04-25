/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:44:31 by gmachena          #+#    #+#             */
/*   Updated: 2017/11/30 11:26:05 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tab;

	if (!(tab = malloc(sizeof(void*) * (size))))
		exit(EXIT_FAILURE);
	ft_memset(tab, 0, size);
	return (tab);
}
