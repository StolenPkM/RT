/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phamelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:18:59 by phamelin          #+#    #+#             */
/*   Updated: 2018/04/25 14:40:25 by phamelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_putchar_to_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_to_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_to_fd(fd, str[i]);
		i++;
	}
}

int		open_file(char **buf, t_env *e)
{
	int fd;
	int i;
	int j;

	i = 0;
	if ((fd = open("save.ppm", O_WRONLY | O_CREAT, 0666)) < 0)
		return (-1);
	ft_putstr_to_fd(fd, "P3\n");
	ft_putstr_to_fd(fd, ft_itoa(WIN_X));
	ft_putchar_to_fd(fd, ' ');
	ft_putstr_to_fd(fd, ft_itoa(WIN_Y));
	ft_putstr_to_fd(fd, "\n255\n");
	while (buf[++i])
	{
		j = 0;
		if (i % 9 == 0)
			ft_putchar_to_fd(fd, '\n');
		while (buf[i][j])
		{
			ft_putchar_to_fd(fd, buf[i][j]);
			j++;
		}
		ft_putchar_to_fd(fd, ' ');
	}
	return (1);
}

void	ft_export(t_env *e)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	while (e->rgb[i])
		i++;
	if (!(str = malloc(sizeof(char *) * i * 3 + 1)))
		exit(0);
	i = -1;
	while (e->rgb[++i + 2])
	{
		if (!(str[j] = malloc(sizeof(char) * 12)))
			exit(0);
		while (e->rgb[i])
		{
			str[j++] = ft_itoa(e->rgb[i]->r);
			str[j++] = ft_itoa(e->rgb[i]->g);
			str[j++] = ft_itoa(e->rgb[i]->b);
			i++;
		}
	}
	str[j] = NULL;
	open_file(str, e);
}
