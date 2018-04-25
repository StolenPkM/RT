/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:24:42 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/09 16:09:53 by tlecas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect	vectsub(t_vect vect1, t_vect vect2)
{
	vect1.x -= vect2.x;
	vect1.y -= vect2.y;
	vect1.z -= vect2.z;
	return (vect1);
}
