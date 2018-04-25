/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:46:06 by acoudray          #+#    #+#             */
/*   Updated: 2018/04/25 15:36:21 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*ft_init_sphere(t_sphere *sphere)
{
	if (!(sphere = malloc(sizeof(t_sphere))))
		ft_error("Error malloc'ing!");
	sphere->pos = coord_v(0, 0, 0);
	sphere->rotate = coord_v(0, 0, 0);
	sphere->mat = ft_mat_init(0, 0, 0);
	sphere->radius = 1.0;
	sphere->color = 0xFF0000FF;
	sphere->inter = 0;
	sphere->decal_w = 0;
	sphere->decal_h = 0;
	return (sphere);
}

static int		ft_fill_properties(t_sphere *sphere, char *str)
{
	char	*tmp;

	if (!(ft_strncmp(str, "\tradius: ", 9)))
		sphere->radius = parse_double(tmp = ft_strrcpy(str, 9), 0.0, 20.0);
	else if (!(ft_strncmp(str, "\tcolor: ", 8)))
		sphere->color = parse_hexa(tmp = ft_strrcpy(str, 8));
	else if (!(ft_strncmp(str, "\tambient: ", 10)))
		sphere->mat.ambient = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tdiffuse: ", 10)))
		sphere->mat.diffuse = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\tspecular: ", 11)))
		sphere->mat.specular = parse_double(tmp = ft_strrcpy(str, 11), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\treflection: ", 13)))
		sphere->mat.reflection = parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\trefraction: ", 13)))
		sphere->mat.refraction = parse_double(tmp = ft_strrcpy(str, 13), 0.0, 1.0);
	else if (!(ft_strncmp(str, "\ttexture: ", 10)))
	{
		sphere->proc = parse_texture(tmp = ft_strrcpy(str, 10), sphere->text);
		if ((sphere->text = SDL_LoadBMP("./textures/3.bmp")))
			sphere->proc = 4;
	}
	else if (!(ft_strncmp(str, "\tdecal_w: ", 10)))
		sphere->decal_w = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1000.0);
	else if (!(ft_strncmp(str, "\tdecal_h: ", 10)))
		sphere->decal_h = parse_double(tmp = ft_strrcpy(str, 10), 0.0, 1000.0);
	else
		return (0);
	free(tmp);
	return (1);
}

static int		ft_fill_coords(t_sphere *sphere, char *str)
{
	char	*tmp;

	if (!(ft_strncmp(str, "\tx: ", 4)))
		sphere->pos.x = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\ty: ", 4)))
		sphere->pos.y = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tz: ", 4)))
		sphere->pos.z = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\trotX: ", 7)))
		sphere->rotate.x = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotY: ", 7)))
		sphere->rotate.y = ft_atof(tmp = ft_strrcpy(str, 7));
	else if (!(ft_strncmp(str, "\trotZ: ", 7)))
		sphere->rotate.z = ft_atof(tmp = ft_strrcpy(str, 7));
	else
		return (0);
	free(tmp);
	return (1);
}

static t_sphere		*ft_parse_properties(t_sphere *sphere, char *str)
{
	if (str && str[0] == '\t')
	{
		if ((!ft_fill_coords(sphere, str)) && (!ft_fill_properties(sphere, str)))
			ft_error("Can't parse properties of an object");
		return (sphere);
	}
	return (0);
}

int		ft_parse_sphere(t_env *e, char **tab)
{
	int		i;
	int		j;
	int		insphere;

	i = -1;
	j = -1;
	insphere = 0;
	if (!(e->sphere = malloc(sizeof(t_sphere *) * (e->objnb->sphere))))
		ft_error("error malloc");
	while (tab[++i])
	{
		if (!(ft_strcmp(tab[i], "sphere:")))
		{
			++j;
			e->sphere[j] = ft_init_sphere(e->sphere[j]);
			insphere = 1;
		}
		else if (insphere == 1 && tab[i][0] == '\t')
			e->sphere[j] = ft_parse_properties(e->sphere[j], tab[i]);
		else if (tab[i][0] != '\t')
			insphere = 0;
	}
	return (0);
}
