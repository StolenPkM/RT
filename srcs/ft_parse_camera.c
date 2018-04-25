/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:15:43 by acoudray          #+#    #+#             */
/*   Updated: 2018/02/22 13:26:04 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera		*ft_init_camera(t_camera *camera)
{
	if (!(camera = malloc(sizeof(t_camera))))
		ft_error("Error malloc'ing!");
	camera->pos = coord_v(0, 0, 0);
	camera->angle = coord_v(0, 0, 0);
	camera->v = coord_v(0, 0, 0);
	return (camera);
}

static int		ft_fill_coords(t_camera *camera, char *str)
{
	char	*tmp;

	if (!(ft_strncmp(str, "\tx: ", 4)))
		camera->pos.x = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\ty: ", 4)))
		camera->pos.y = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tz: ", 4)))
		camera->pos.z = ft_atof(tmp = ft_strrcpy(str, 4));
	else if (!(ft_strncmp(str, "\tangle_x: ", 10)))
		camera->angle.x = ft_atof(tmp = ft_strrcpy(str, 10));
	else if (!(ft_strncmp(str, "\tangle_y: ", 10)))
		camera->angle.y = ft_atof(tmp = ft_strrcpy(str, 10));
	else if (!(ft_strncmp(str, "\tangle_z: ", 10)))
		camera->angle.z = ft_atof(tmp = ft_strrcpy(str, 10));
	else
		return (0);
	free(tmp);
	return (1);
}

static t_camera		*ft_parse_properties(t_camera *camera, char *str)
{
	if (str[0] == '\t')
	{
		if ((!ft_fill_coords(camera, str)))
			ft_error("Can't parse properties of an object");
		return (camera);
	}
	return (0);
}

int		ft_parse_camera(t_env *e, char **tab)
{
	int		i;
	int		incamera;

	i = -1;
	incamera = 0;
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "camera:"))
		{
			e->camera = ft_init_camera(e->camera);
			incamera = 1;
		}
		else if (incamera == 1 && tab[i][0] == '\t')
			e->camera = ft_parse_properties(e->camera, tab[i]);
		else if (tab[i][0] != '\t')
			incamera = 0;
	}
	return (0);
}
