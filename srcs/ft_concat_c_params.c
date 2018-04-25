/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_c_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:36:03 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/25 12:26:44 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat		ft_mat_init(void)
{
	t_mat mat;

	mat.ambient = 0;
	mat.diffuse = 0;
	mat.specular = 0;
	mat.reflection = 0;
	mat.refraction = 0;
	return (mat);
}

char		*ft_concat_c_params(char *str1, const char *str2, char c)
{
	char	*ret;
	int		tab[4];

	tab[0] = -1;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = -1;
	if (str1 == 0 && --tab[2])
		tab[1] = ft_strlen(str2) + 1;
	else if (str1 != 0 && ++tab[2])
		tab[1] = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(ret = malloc(sizeof(char) * (tab[1] + 1))))
		ft_error("Error malloc!");
	while (++tab[0] <= tab[1])
	{
		if (tab[2] == 1 && str1[tab[0]])
			ret[tab[0]] = str1[tab[0]];
		else if (tab[2] == 1 && str1[tab[0]] == '\0' && tab[2]--)
			ret[tab[0]] = c;
		else if (tab[2] <= 0)
			ret[tab[0]] = str2[++tab[3]];
	}
	if (str1)
		free(str1);
	return (ret);
}
