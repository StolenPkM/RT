/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_main_properties.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:08:17 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/18 14:46:55 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	parse_hexa(char *str)
{
	unsigned int	tmp;

	tmp = ft_strtol(str);
	rgb_add(&tmp, 0xFF000000);
	return (tmp);
}

double	parse_double(char *str, double min, double max)
{
	double tmp;

	tmp = atof(str);
	tmp = fclamp(tmp, min, max);
	return (tmp);
}

int		parse_filter(char *str)
{
	if (!(ft_strncmp(str, "none", 4)))
		return (0);
	else if (!(ft_strncmp(str, "sepia", 5)))
		return (1);
	else if (!(ft_strncmp(str, "negatif", 7)))
		return (2);
	else if (!(ft_strncmp(str, "stereoscopie", 12)))
		return (3);
	return (0);
}

int		parse_int(char *str, int min, int max)
{
	int	tmp;

	tmp = ft_atoi(str);
	iclamp(&tmp, min, max);
	return (tmp);
}

int		ft_parse_main_properties(t_env *e, char *str, int i)
{
	char *tmp;

	if (ft_strncmp(str, "width: ", 7) == 0 && i == 0)
		e->width = parse_int(tmp = ft_strrcpy(str, 7), 800, 2100);
	else if (ft_strncmp(str, "height: ", 8) == 0 && i == 1)
		e->height = parse_int(tmp = ft_strrcpy(str, 8), 600, 1900);
	else if (ft_strncmp(str, "recursivity: ", 13) == 0 && i == 2)
		e->recursivity = parse_int(tmp = ft_strrcpy(str, 13), 0, 10);
	else if (ft_strncmp(str, "antialias: ", 11) == 0 && i == 3)
		e->antialias = parse_int(tmp = ft_strrcpy(str, 11), 0, 16);
	else if (ft_strncmp(str, "diaphragm: ", 11) == 0 && i == 4)
		e->diaphragm = parse_double(tmp = ft_strrcpy(str, 11), 30.0, 120.0);
	else if (ft_strncmp(str, "filter: ", 8) == 0 && i ==5)
		e->filter = parse_filter(tmp = ft_strrcpy(str, 8));
	else if (ft_strncmp(str, "ambientcolor: ", 14) == 0 && i == 6)
		e->ambientcolor = parse_hexa(tmp = ft_strrcpy(str, 14));
	else
		return (-1);
	free(tmp);
	return (1);
}
