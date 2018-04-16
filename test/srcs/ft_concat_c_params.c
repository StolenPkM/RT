/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_c_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:36:03 by gmachena          #+#    #+#             */
/*   Updated: 2018/02/22 13:32:34 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat	ft_mat_init()
{
	t_mat mat;

	mat.ambient = 0;
	mat.diffuse = 0;
	mat.specular = 0;
	mat.reflection = 0;
	mat.refraction = 0;
	return (mat);
}

char	*ft_concat_c_params(char *str1, const char *str2, char c)
{
	char	*ret;
	int		i;
	int		j;
	int		k;
	int		l;

	j = -1;
	i = 0;
	k = 0;
	l = -1;
	if (str1 == 0 && --k)
		i = ft_strlen(str2) + 1;
	else if (str1 != 0 && ++k)
		i = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		ft_error("Error malloc!");
	while (++j <= i)
	{
		if (k == 1 && str1[j])
			ret[j] = str1[j];
		else if (k == 1 && str1[j] == '\0' && k--)
			ret[j] = c;
		else if (k <= 0)
			ret[j] = str2[++l];
	}
	if (str1)
		free(str1);
	return (ret);
}
