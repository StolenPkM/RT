/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:46:46 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/22 16:57:26 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect	vmv(t_vect v1, t_vect v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return(v1);
}

t_vect	vmult(t_vect v, double mult)
{
	v.x *= mult;
	v.y *= mult;
	v.z *= mult;
	return (v);
}