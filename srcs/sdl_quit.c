/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phamelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:54:17 by phamelin          #+#    #+#             */
/*   Updated: 2018/04/25 19:59:10 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void   free_sdl(t_env *e)
{
  if (e->renderer)
    SDL_DestroyRenderer(e->renderer);
  if (e->win)
    SDL_DestroyWindow(e->win);
  SDL_Quit();
}

void  re_draw(t_env *e)
{
  int i;

  i = -1;
  while (++i < (WIN_X * WIN_Y))
    ft_put_pixel_to_img(e, (i % WIN_X), (i / WIN_X), i);
  SDL_RenderPresent(e->renderer);
}

void  sdl_loop(t_env *e)
{
  int terminer;
  int i;

  i = -1;
  terminer = 1;
  while (terminer != 0)
  {
    SDL_WaitEvent(&e->events);
    if (e->events.type == SDL_KEYDOWN)
    {  
      if (e->events.key.keysym.sym == SDLK_1)
           applied_sepia(e);
      if (e->events.key.keysym.sym == SDLK_2)
       applied_negative(e);
      if (e->events.key.keysym.sym == SDLK_3)
       applied_yellow(e);
      if (e->events.key.keysym.sym == SDLK_4)
       applied_red(e);
     if (e->events.key.keysym.sym == SDLK_5)
       applied_green(e);
     re_draw(e);
  }
    if (e->events.window.event == SDL_WINDOWEVENT_CLOSE)
        terminer = 0;
    if (e->events.type == SDL_KEYDOWN && e->events.key.keysym.sym == SDLK_ESCAPE)
      terminer = 0;
  }
  free_sdl(e);
}


