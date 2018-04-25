/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:37:22 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/25 12:42:35 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*ft_init_plane(t_plane *plane)
{
	if (!(plane = malloc(sizeof(t_plane))))
		ft_error("Error malloc'ing!");
	plane->pos = coord_v(0, 0, 0);
	plane->norm = coord_v(0, 0, 0);
	plane->rotate = coord_v(0, 0, 0);
	plane->color = 0xFFabcdef;
	plane->mat = ft_mat_init();
	plane->inter = 0;
	return (plane);
}

int			parse_texture(char *str, SDL_Surface *text)
{
	if (!(ft_strncmp(str, "damier", 5)))
		return (1);
	else if (!(ft_strncmp(str, "trou", 4)))
		return (2);
	else if (!(ft_strncmp(str, "alea", 4)))
		return (3);
	else if ((text = SDL_LoadBMP(str)))
	{
		ft_putendl("coucou");
		return (4);
	}
	else
		return (0);
}

static int		ft_fill_properties(t_plane *plane, char *str)
{
	char		*tmp;

	if (!(ft_strncmp(str, "\tambient: ", 10)))
		plane->mat.ambient = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tcolor: ", 8)))
		plane->color = parse_hexa(tmp = ft_strrcpy(str, 8));
	else if (!(ft_strncmp(str, "\tdiffuse: ", 10)))
		plane->mat.diffuse = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tspecular: ", 11)))
		plane->mat.specular = parse_double(tmp = ft_strrcpy(str, 11), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\treflection: ", 13)))
		plane->mat.reflection = \
			parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\trefraction: ", 13)))
		plane->mat.refraction = \
			parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\ttexture: ", 10)))
		plane->proc = parse_texture(tmp = ft_strrcpy(str, 10), plane->text);
	else
		return (0);
	free(tmp);
	return (1);
}

static int		ft_fill_coords(t_plane *plane, char *str)
{
	char		*tmp;

	if (!(ft_strncmp(str, "\tx: ", 4)))
		plane->pos.x = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\ty: ", 4)))
		plane->pos.y = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tz: ", 4)))
		plane->pos.z = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\trotX: ", 7)))
		plane->rotate.x = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotY: ", 7)))
		plane->rotate.y = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotZ: ", 7)))
		plane->rotate.z = ft_atof(tmp = ft_strrcpy(str, 7));
	else
		return (0);
	free(tmp);
	return (1);
}

static t_plane	*ft_parse_properties(t_plane *plane, char *str)
{
	if (str && str[0] == '\t')
	{
		if (!(ft_fill_coords(plane, str)) && \
				(!(ft_fill_properties(plane, str))))
			ft_error("Can't parse properties of an object");
		return (plane);
	}
	return (0);
}

int				ft_parse_plane(t_env *e, char **tab)
{
	int			i;
	int			j;
	int			inplane;

	i = -1;
	j = -1;
	inplane = 0;
	if (!(e->plane = malloc(sizeof(t_plane *) * (e->objnb->plane))))
		ft_error("error malloc");
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "plane:"))
		{
			++j;
			e->plane[j] = ft_init_plane(e->plane[j]);
			inplane = 1;
		}
		else if (inplane == 1 && tab[i][0] == '\t')
			e->plane[j] = ft_parse_properties(e->plane[j], tab[i]);
		else if (tab[i][0] != '\t')
			inplane = 0;
	}
	return (0);
}
