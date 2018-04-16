/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 00:42:55 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 04:37:03 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *del_chain;
	t_list *tmp;

	del_chain = *alst;
	while (del_chain != 0)
	{
		tmp = del_chain->next;
		del(del_chain->content, del_chain->content_size);
		free(del_chain);
		del_chain = tmp;
	}
	*alst = 0;
}
