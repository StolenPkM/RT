/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:52:22 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/25 15:36:33 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylinder		*ft_init_cylinder(t_cylinder *cylinder)
{
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		ft_error("Error malloc'ing!");
	cylinder->pos = coord_v(0, 0, 0);
	cylinder->rotate = coord_v(0, 0, 0);
	cylinder->radius = 1.0;
	cylinder->color = 0xFF707070;
	cylinder->mat = ft_mat_init();
	cylinder->inter = 0;

	return (cylinder);
}

static int		ft_fill_properties(t_cylinder *cylinder, char *str)
{
	char	*tmp;

	if (!(ft_strncmp(str, "\tradius: ", 9)))
		cylinder->radius = parse_double(tmp = ft_strrcpy(str, 9), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tcolor: ", 8)))
		cylinder->color = parse_hexa(tmp = ft_strrcpy(str, 8));
	else if (!(ft_strncmp(str, "\tambient: ", 10)))
		cylinder->mat.ambient = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tdiffuse: ", 10)))
		cylinder->mat.diffuse = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tspecular: ", 11)))
		cylinder->mat.specular = parse_double(tmp = ft_strrcpy(str, 11), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\treflection: ", 13)))
		cylinder->mat.reflection = parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\trefraction: ", 13)))
		cylinder->mat.refraction = parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\ttexture: ", 10)))
	{
		cylinder->proc = parse_texture(tmp = ft_strrcpy(str, 10), cylinder->text);
		if ((cylinder->text = SDL_LoadBMP("./textures/3.bmp")))
			cylinder->proc = 4;
	}
	else
		return (0);
	free(tmp);
	return (1);
}

static int		ft_fill_coords(t_cylinder *cylinder, char *str)
{
	char	*tmp;

	if (!(ft_strncmp(str, "\tx: ", 4)))
		cylinder->pos.x = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\ty: ", 4)))
		cylinder->pos.y = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tz: ", 4)))
		cylinder->pos.z = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\trotX: ", 7)))
		cylinder->rotate.x = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotY: ", 7)))
		cylinder->rotate.y = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotZ: ", 7)))
		cylinder->rotate.z = ft_atof(tmp = ft_strrcpy(str, 7));
	else
		return (0);
	free(tmp);
	return (1);
}

static t_cylinder		*ft_parse_properties(t_cylinder *cylinder, char *str)
{
	if (str && str[0] == '\t')
	{
		if ((!ft_fill_coords(cylinder, str)) && (!ft_fill_properties(cylinder, str)))
			ft_error("Can't parse properties of an object");
		return (cylinder);
	}
	return (0);
}

int		ft_parse_cylinder(t_env *e, char **tab)
{
	int		i;
	int		j;
	int		incylinder;

	i = -1;
	j = -1;
	incylinder = 0;
	if (!(e->cylinder = malloc(sizeof(t_cylinder *) * (e->objnb->cylinder))))
		ft_error("error malloc");
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "cylinder:"))
		{
			++j;
			e->cylinder[j] = ft_init_cylinder(e->cylinder[j]);
			incylinder = 1;
		}
		else if (incylinder == 1 && tab[i][0] == '\t')
			e->cylinder[j] = ft_parse_properties(e->cylinder[j], tab[i]);
		else if (tab[i][0] != '\t')
			incylinder = 0;
	}
	return (0);
}
