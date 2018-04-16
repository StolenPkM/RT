/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 01:31:28 by gmachena          #+#    #+#             */
/*   Updated: 2016/11/22 02:22:54 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *tmp;
	t_list *new_chain;

	if (lst == 0)
		return (0);
	ptr = f(lst);
	if (!(ft_lstnew(ptr->content, ptr->content_size)))
		return (0);
	tmp = ptr;
	new_chain = tmp;
	lst = lst->next;
	while (lst != 0)
	{
		ptr = f(lst);
		if (!(ft_lstnew(ptr->content, ptr->content_size)))
			return (0);
		tmp->next = ptr;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_chain);
}
