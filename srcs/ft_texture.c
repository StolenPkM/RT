/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:37:47 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/25 15:13:56 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	Uint32	get_pixel(SDL_Surface *text, int x, int y)
{
	int 	bpp;
	Uint8	*p;

	bpp = text->format->BytesPerPixel;
	p = (Uint8 *)text->pixels + (y * text->pitch) + (x * bpp);
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);

}

unsigned int	get_color_hex(Uint32 pixel, SDL_Surface *text)
{
	Uint8 			rgb[4];
	unsigned int 	color;

	SDL_GetRGBA(pixel, text->format, &rgb[0], &rgb[1], &rgb[2], &rgb[3]);
	color = (rgb[3] * 0x1000000) + (rgb[0] * 0x10000) + (rgb[1] * 0x100) + rgb[0];
	return (color);
}

unsigned int	ft_texture(t_thread *thr, SDL_Surface *text)
{
	int	 xy[2];
	Uint32		pixel;

	if (!(ft_strcmp(thr->name, "plane")))
	{
		xy[0] = thr->gx + text->w;
		xy[1] = thr->gy + text->h;
	}
	else if (!(ft_strcmp(thr->name, "sphere")))
	{
		xy[0] = (((thr->internorm.x / 2) + 0.5) * text->w) + thr->decal_w;
		xy[1] = (((thr->internorm.y / 2) - 0.5) * text->h) + thr->decal_h;
	}
	else
	{
		xy[0] = thr->gx;
		xy[1] = text->h - thr->gy;
	}
	while (xy[0] < 0)
		xy[0] += text->w;
	if (xy[0] > text->w)
		xy[0] %= text->w;
	while (xy[1] < 0)
		xy[1] += text->h;
	if (xy[1] > text->h)
		xy[1] %= text->h;
	if ((xy[0] >= 0 && xy[0] <= text->w) &&  (xy[1] >= 0 && xy[1] <= text->h))
	{

		pixel = get_pixel(text, xy[0], xy[1]);
		return (get_color_hex(pixel, text));
	}
	return (0xFFFF0000);
}