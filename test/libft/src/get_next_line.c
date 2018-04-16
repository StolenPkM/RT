/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:14:12 by acoudray          #+#    #+#             */
/*   Updated: 2018/03/10 13:13:43 by tlecas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_gnl		*ft_free_list(t_gnl *ptr, t_gnl *beginlist)
{
	t_gnl			*buff;

	buff = beginlist;
	if (ptr == beginlist && beginlist->next != NULL)
		beginlist = beginlist->next;
	else if (ptr == beginlist && beginlist->next == NULL)
		beginlist = NULL;
	else
	{
		while (buff->next != ptr && buff)
			buff = buff->next;
		buff->next = ptr->next;
	}
	free(ptr);
	ptr = beginlist;
	return (beginlist);
}

static	char		*ft_process_line(char **str, int len)
{
	int				i;
	char			*ret;
	char			tab[len + 1];
	char			*ptr;
	int				j;

	i = 0;
	j = 0;
	ret = 0;
	ft_strcpy(tab, *str);
	if ((ptr = ft_strchr(tab, '\n')))
		*ptr = '\0';
	else
		j++;
	i = ft_strlen(tab);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret = ft_strcpy(ret, tab);
	free(*str);
	if (((j == 0) && (tab[i + 1] == '\0')) || (j == 1))
		*str = NULL;
	else
		*str = ft_strsub(tab, (i + 1), (len - (i - 1)));
	return (ret);
}

static	char		*ft_read_fd(int fd, char *tab, int *i)
{
	char			*buff;
	char			txt[BUFF_SIZE + 1];

	if ((*i = read(fd, txt, BUFF_SIZE)) < 1)
		return (0);
	if (!(tab = (char *)malloc(sizeof(char) * (*i + 1))))
		return (0);
	tab = ft_strncpy(tab, txt, *i);
	tab[*i] = '\0';
	while ((*i = read(fd, txt, BUFF_SIZE)))
	{
		buff = ft_strjoin(tab, txt);
		*i = ft_strlen(tab) + *i;
		free(tab);
		if (!(tab = (char*)malloc(sizeof(char) * (*i + 1))))
			return (0);
		tab = ft_strncpy(tab, buff, *i);
		tab[*i] = '\0';
		free(buff);
		if ((*i % BUFF_5IZE(BUFF_SIZE)) != 0)
			break ;
	}
	return (tab);
}

static	t_gnl		*ft_struct(t_gnl **beginlist, int fd, int *i)
{
	t_gnl			*ptr;
	char			*str;

	str = NULL;
	READCHECK((str = ft_read_fd(fd, str, &*i)), (*i));
	ptr = *beginlist;
	while (ptr)
	{
		if ((ptr->fd) == fd)
			return (ptr);
		else
			ptr = ptr->next;
	}
	READCHECK((str), -1);
	ptr = NULL;
	*i = ft_strlen(str);
	if (!(ptr = (t_gnl *)malloc(sizeof(t_gnl))) ||
	(!((ptr->str = (char*)malloc(sizeof(char) * (*i + 1))))))
		return (0);
	ft_strcpy(ptr->str, str);
	ptr->fd = fd;
	ptr->next = *beginlist;
	free(str);
	*beginlist = ptr;
	return (ptr);
}

int					get_next_line(int const fd, char **line)
{
	static	t_gnl	*nextline;
	t_gnl			*ptr;
	int				i;

	i = 0;
	ptr = NULL;
	if (line == NULL || fd < 0 || (read(fd, ptr, 0) < 0))
		return (-1);
	*line = NULL;
	if (!(ptr = ft_struct(&nextline, fd, &i)))
		return (0);
	if ((ptr->str) == NULL)
	{
		if (nextline != NULL)
			nextline = ft_free_list(ptr, nextline);
		ptr = nextline;
		return (0);
	}
	*line = ft_process_line(&ptr->str, ft_strlen(ptr->str));
	return (1);
}
