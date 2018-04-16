/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:12:13 by acoudray          #+#    #+#             */
/*   Updated: 2018/02/22 13:43:46 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_is_shape_named(char *str1, char *str2)
{
    if (!ft_strcmp(str1, str2))
        return (1);
    else
        return (0);
}

t_vect		*ft_parse_coords(t_vect *pos, char *str)
{
	char	*tmp;

	tmp = 0;
	if (!(ft_strncmp(str, "\tx: ", 4)))
		pos->x = (float)(ft_atof(tmp = ft_strrcpy(str, 4)));
	if (!(ft_strncmp(str, "\ty: ", 4)))
		pos->y = (float)(ft_atof(tmp = ft_strrcpy(str, 4)));
	if (!(ft_strncmp(str, "\tz: ", 4)))
		pos->z = (float)(ft_atof(tmp = ft_strrcpy(str, 4)));
	if (!(ft_strncmp(str, "\trotX: ", 7)))
		pos->x = (float)(ft_atof(tmp = ft_strrcpy(str, 7)));
	if (!(ft_strncmp(str, "\trotY: ", 7)))
		pos->y = (float)(ft_atof(tmp = ft_strrcpy(str, 7)));
	if (!(ft_strncmp(str, "\trotZ: ", 7)))
		pos->z = (float)(ft_atof(tmp = ft_strrcpy(str, 7)));
	free(tmp);
	return (pos);
}
