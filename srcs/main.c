/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <pabonnin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:01:04 by pabonnin          #+#    #+#             */
/*   Updated: 2018/04/25 20:03:02 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			main(int ac, char **av)
{
	char	**useless;
	t_env	*e;

	useless = av;
	if (ac == 2)
	{
		e = init(av[1]);
		ft_rt(e);
	//	ft_export(e);
		sdl_loop(e);
	}
	return (0);
}
