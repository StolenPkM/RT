/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <pabonnin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:21:39 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 11:57:29 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static		t_env	*ft_init_obj_nb(t_env *e)
{
	if (!(e->objnb = malloc(sizeof(t_objnb))))
		ft_error("Error malloc'ing!");
	e->objnb->sphere = 0;
	e->objnb->cylinder = 0;
	e->objnb->cone = 0;
	e->objnb->light = 0;
	e->objnb->plane = 0;
	e->objnb->totobj = 0;
	return (e);
}

static		t_env	*ft_init_eye(t_env *e)
{
	e->virt_e.pos = coord_v(0, 0, 0);
	e->virt_e.angle = coord_v(0, 0, 0);
	e->virt_e.v = coord_v(0, 0, 0);
	return (e);
}

t_env				*ft_load_obj(t_env *e, char **tab)
{
	ft_parse_sphere(e, tab);
	ft_parse_plane(e, tab);
	ft_parse_light(e, tab);
	ft_parse_cone(e, tab);
	ft_parse_cylinder(e, tab);
	ft_parse_camera(e, tab);
	return (e);
}

int					init_sdl(t_env *e)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("Erreur lors de l'initialisation de la SDL");
		SDL_Quit();
		return (0);
	}
	e->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	if (e->win == NULL)
	{
		ft_putendl("Erreur lors de la création de la fenetre");
		SDL_Quit();
		return (0);
	}
	e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED);
	return (0);
}

t_env				*init(char *filename)
{
	t_env			*e;
	char			**tab;
	int				i;

	i = -1;
	(void)tab;
	if (!(e = malloc(sizeof(t_env))))
		ft_error("malloc error");
	e = ft_init_obj_nb(e);
	if (!(e->filename = malloc(sizeof(char) * (ft_strlen(filename) + 1))))
		ft_error("malloc error");
	e->filename = ft_strcpy(e->filename, filename);
	tab = ft_parse_file(e);
	e = ft_load_obj(e, tab);
	e = ft_init_eye(e);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	init_sdl(e);
	return (e);
}
