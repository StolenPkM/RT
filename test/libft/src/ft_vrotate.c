/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:53:29 by gmachena          #+#    #+#             */
/*   Updated: 2018/03/12 18:07:43 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect	rotate_x(t_vect v, double angle)
{
	double	y_tmp;
	double	z_tmp;

	angle = (angle * (M_PI / 180));
	y_tmp = v.y;
	z_tmp = v.z;
	v.y = y_tmp * cos(angle) - z_tmp * sin(angle);
	v.z = y_tmp * sin(angle) + z_tmp * cos(angle);
	return (v);
}

t_vect	rotate_y(t_vect v, double angle)
{
	double	x_tmp;
	double	z_tmp;

	angle = (angle * (M_PI / 180));
	x_tmp = v.x;
	z_tmp = v.z;
	v.z = z_tmp * cos(angle) - x_tmp * sin(angle);
	v.x = z_tmp * sin(angle) + x_tmp * cos(angle);
	return (v);
}

t_vect	rotate_z(t_vect v, double angle)
{
	double	x_tmp;
	double	y_tmp;

	angle = (angle * (M_PI / 180));
	x_tmp = v.x;
	y_tmp = v.y;
	v.x = x_tmp * cos(angle) - y_tmp * sin(angle);
	v.y = x_tmp * sin(angle) + y_tmp * cos(angle);
	return (v);
}

t_vect	vrotate(t_vect v, t_vect angle)
{
	v = rotate_x(v, -(angle.x));
	v = rotate_y(v, -(angle.y));
	v = rotate_z(v, -(angle.z));
	return (v);
}

t_vect	vrotateinv(t_vect v, t_vect angle)
{
	v = rotate_z(v, (angle.z));
	v = rotate_y(v, (angle.y));
	v = rotate_x(v, (angle.x));
	return (v);
}