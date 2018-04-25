/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:10:01 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/24 12:39:57 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int g_y;
int g_x;


void	ft_save_inter_sphere(t_thread *thr, t_sphere *sphere, t_camera *camera)
{
	//debug("rotate", rot);
	thr->interpos = vectadd(camera->pos, vmult(camera->v, thr->value));
	thr->internorm = vectsub(thr->interpos, sphere->pos);
	//thr->internorm = normalize(thr->internorm);
}

void			ft_post_sphere(t_thread *thr, unsigned int *tmp)
{
	int	i;

	i = thr->number;
	thr->ar = thr->e->sphere[i]->radius;
	thr->pos = thr->e->sphere[i]->pos;
	thr->rotate = thr->e->sphere[i]->rotate;
	thr->decal_w = thr->e->sphere[i]->decal_w;
	thr->decal_h = thr->e->sphere[i]->decal_h;
	ft_save_inter_sphere(thr, thr->e->sphere[i], &thr->cam);
	if (thr->e->sphere[i]->proc == 4)
		*tmp = ft_texture(thr, thr->e->sphere[i]->text);
	else
		*tmp = thr->e->sphere[i]->color;
}

static double	ft_calc_inter_sphere(t_vect pos, t_vect vect, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	delta = 0;
	a = norm2(vect);
	b = (dot(pos, vect)) * 2.0;
	c = (norm2(pos)) - (sphere->radius * sphere->radius);
	delta = (b * b) - (4.0 * a * c);
	//printf("a = %f b = %f c = %f delta = %f\n", a, b, c, delta);
	//while(1);
	if (delta < 0.0001)
		return (0);
	else
		return (ft_eq_second(delta, a, b));
}

double ft_calc_sphere(t_sphere *sphere, t_camera *camera)
{
	t_vect pos;
	t_vect vect;
	double inter;

	inter = 0;
	//if (g_x == 500 && g_y == 373)
	//{
	//	printf("camera->x = %f camera->y = %f camera->z = %f\n",camera->pos.x, camera->pos.y, camera->pos.z);
	//	printf("sphere->x = %f sphere->y = %f sphere->z = %f\n",sphere->pos.x, sphere->pos.y, sphere->pos.z);
	//}
	pos = vrotate(vectsub(camera->pos, sphere->pos), sphere->rotate);
	vect = vrotate(camera->v, sphere->rotate);
	if ((inter = ft_calc_inter_sphere(pos, vect, sphere)) < 0.0001)
		return (0);
	//printf("coucou");
	//printf("sphere->inter = %f\n", sphere->inter);
	//while(1);
	return (inter);
}
