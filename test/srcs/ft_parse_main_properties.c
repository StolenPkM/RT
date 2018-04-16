/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_main_properties.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:08:17 by acoudray          #+#    #+#             */
/*   Updated: 2018/03/29 15:45:00 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


unsigned int	parse_hexa(char *str, unsigned int min, unsigned int max)
{
	unsigned int	tmp;

	(void)min;
	(void)max;
	printf("%s\n", str);
	tmp = ft_strtol(str);
	printf("0x%08x\n", tmp);
	while (1);
//	uiclamp(&tmp, min, max);
	return (tmp);
}

double	parse_double(char *str, double min, double max)
{
	double tmp;

	tmp = atof(str);
	tmp = fclamp(tmp, min, max);
	return (tmp);
}

int		parse_int(char *str, int min, int max)
{
	int	tmp;

	tmp = ft_atoi(str);
	iclamp(&tmp, min, max);
	return (tmp);
}

int		ft_parse_main_properties(t_env *e, char *str)
{
	char *tmp;

	if (!(ft_strncmp(str, "width: ", 7)))
		e->width = parse_int(tmp = ft_strrcpy(str, 7), 800, 2100);
	else if (!(ft_strncmp(str, "height: ", 8)))
		e->height = parse_int(tmp = ft_strrcpy(str, 8), 600, 1900);
	else if (!(ft_strncmp(str, "recursivity: ", 13)))
		e->recursivity = parse_int(tmp = ft_strrcpy(str, 13), 0, 10);
	else if (!(ft_strncmp(str, "antialias: ", 11)))
		e->antialias = parse_int(tmp = ft_strrcpy(str, 11), 0, 16);
	else if (!(ft_strncmp(str, "diaphragm: ", 11)))
		e->diaphragm = parse_double(tmp = ft_strrcpy(str, 11), 30.0, 120.0);
	else
		return (-1);
	free(tmp);
	return (1);
}
