/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phamelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:18:59 by phamelin          #+#    #+#             */
/*   Updated: 2018/04/25 16:16:35 by phamelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_putstr_to_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	fuck_norme(int fd, t_env *e)
{
	ft_putstr_to_fd(fd, "P3\n");
	ft_putstr_to_fd(fd, ft_itoa(WIN_X));
	write(fd, " ", 1);
	ft_putstr_to_fd(fd, ft_itoa(WIN_Y));
	ft_putstr_to_fd(fd, "\n255\n");
}

char	*add_int_to_string(unsigned int nb)
{
	char			*add;
	char			*str;
	unsigned int	tmp;
	int				i;

	i = 0;
	tmp = nb;
	while (tmp /= 10)
		i++;
	if (!(add = malloc(sizeof(char) * i + 1)))
		return (NULL);
	add = ft_itoa(nb);
	str = ft_strjoin("save", add);
	str = ft_strjoin(str, ".ppm");
	free(add);
	return (str);
}

int		open_file(char **buf, t_env *e, unsigned int k)
{
	int	fd;
	int i;
	int j;

	i = -1;
	while (access(add_int_to_string(k), F_OK) == 0)
		k++;
	if ((fd = open(add_int_to_string(k), O_WRONLY | O_CREAT |
					O_EXCL, 0666)) < 0)
		return (-1);
	fuck_norme(fd, e);
	while (buf[++i])
	{
		j = 0;
		if (i % 9 == 0)
			write(fd, "\n", 1);
		while (buf[i][j])
		{
			write(fd, &buf[i][j], 1);
			j++;
		}
		write(fd, " ", 1);
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
		while (e->rgb[++i])
		{
			str[j] = ft_itoa(e->rgb[i]->r);
			str[j + 1] = ft_itoa(e->rgb[i]->g);
			str[j + 2] = ft_itoa(e->rgb[i]->b);
			j += 3;
		}
	}
	str[j] = NULL;
	open_file(str, e, 0);
}
