/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:32:56 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/25 19:59:26 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_put_pixel_to_img(t_env *e, int x, int y, int i)
{
	SDL_SetRenderDrawColor(e->renderer, e->rgb[i]->r, e->rgb[i]->g, \
			e->rgb[i]->b, 255);
	if (x < WIN_X && x >= 0 && y < WIN_Y && y >= 0)
		SDL_RenderDrawPoint(e->renderer, x, y);
}

void			main_post_treatment(t_env *e)
{
	int i;

	i = -1;
	if (e->filter == 1)
		applied_sepia(e);
	if (e->filter == 2)
		applied_negative(e);
	if (e->filter == 3)
		applied_yellow(e);
	if (e->filter == 4)
		applied_red(e);
	if (e->filter == 5)
		applied_green(e);
	while (++i < (WIN_X * WIN_Y))
		ft_put_pixel_to_img(e, (i % WIN_X), (i / WIN_X), i);
}

void			hex_to_rgb(unsigned int color, t_rgb *rgb)
{
	unsigned int	inv;

	inv = (color / 0x1000000);
	color = color % 0x1000000;
	rgb->r = (color / 0x10000);
	uiclamp(&rgb->r, 0, 255);
	color = color % 0x10000;
	rgb->g = (color / 0x100);
	uiclamp(&rgb->g, 0, 255);
	color = color % 0x100;
	rgb->b = color;
	uiclamp(&rgb->b, 0, 255);
}

void			ft_print_obj(t_thread *thr, int i)
{
	hex_to_rgb(thr->color, thr->e->rgb[i]);
}
