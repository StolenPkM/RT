/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phamelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:54:17 by phamelin          #+#    #+#             */
/*   Updated: 2018/04/25 12:12:12 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		free_sdl(t_env *e)
{
	if (e->renderer)
		SDL_DestroyRenderer(e->renderer);
	if (e->win)
		SDL_DestroyWindow(e->win);
	SDL_Quit();
}

void		sdl_loop(t_env *e)
{
	int		terminer;

	terminer = 1;
	while (terminer != 0)
	{
		SDL_WaitEvent(&e->events);
		if (e->events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 0;
		if (e->events.key.keysym.sym == SDLK_ESCAPE)
			terminer = 0;
	}
	free_sdl(e);
}
