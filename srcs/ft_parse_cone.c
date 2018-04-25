/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:41:39 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/24 17:58:40 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone			*ft_init_cone(t_cone *cone)
{
	if (!(cone = malloc(sizeof(t_cone))))
		ft_error("Error malloc'ing!");
	cone->pos = coord_v(0, 0, 0);
	cone->rotate = coord_v(0, 0, 0);
	cone->angle = 0.0;
	cone->color = 0xFF00FF00;
	cone->inter = 0;
	cone->mat = ft_mat_init();
	return (cone);
}

static int		ft_fill_properties(t_cone *cone, char *str)
{
	char		*tmp;

	if (!(ft_strncmp(str, "\tangle: ", 8)))
		cone->angle = ft_atof(tmp = ft_strrcpy(str, 8));
	else if (!(ft_strncmp(str, "\tcolor: ", 8)))
		cone->color = parse_hexa(tmp = ft_strrcpy(str, 8));
	else if (!(ft_strncmp(str, "\tambient: ", 10)))
		cone->mat.ambient = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tdiffuse: ", 10)))
		cone->mat.diffuse = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tspecular: ", 11)))
		cone->mat.specular = parse_double(tmp = ft_strrcpy(str, 11), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\treflection: ", 13)))
		cone->mat.reflection = parse_double(tmp = \
				ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\trefraction: ", 13)))
		cone->mat.refraction = parse_double(tmp = \
				ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\ttexture: ", 10)))
		cone->proc = parse_texture(tmp = ft_strrcpy(str, 10), cone->text);
	else
		return (0);
	free(tmp);
	return (1);
}

static int		ft_fill_coords(t_cone *cone, char *str)
{
	char		*tmp;

	if (!(ft_strncmp(str, "\tx: ", 4)))
		cone->pos.x = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\ty: ", 4)))
		cone->pos.y = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tz: ", 4)))
		cone->pos.z = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\trotX: ", 7)))
		cone->rotate.x = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotY: ", 7)))
		cone->rotate.y = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotZ: ", 7)))
		cone->rotate.z = ft_atof(tmp = ft_strrcpy(str, 7));
	else
		return (0);
	free(tmp);
	return (1);
}

static t_cone	*ft_parse_properties(t_cone *cone, char *str)
{
	if (str && str[0] == '\t')
	{
		if ((!ft_fill_coords(cone, str)) && (!ft_fill_properties(cone, str)))
			ft_error("Can't parse properties of an object");
		return (cone);
	}
	return (0);
}

int				ft_parse_cone(t_env *e, char **tab)
{
	int			i;
	int			j;
	int			incone;

	i = -1;
	j = -1;
	incone = 0;
	if (!(e->cone = malloc(sizeof(t_cone *) * (e->objnb->cone))))
		ft_error("error malloc");
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "cone:"))
		{
			++j;
			e->cone[j] = ft_init_cone(e->cone[j]);
			incone = 1;
		}
		else if (incone == 1 && tab[i][0] == '\t')
			e->cone[j] = ft_parse_properties(e->cone[j], tab[i]);
		else if (tab[i][0] != '\t')
			incone = 0;
	}
	return (0);
}
