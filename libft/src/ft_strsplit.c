/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:53:34 by acoudray          #+#    #+#             */
/*   Updated: 2017/09/26 16:24:13 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t		nb_words;
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	nb_words = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++nb_words;
		++s;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nb_words;
	char		*wrd_begin;
	char		**result;

	if (!(nb_words = ft_count_words((char *)s, c)))
		return (0);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd_begin = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (wrd_begin != s)
				*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
			wrd_begin = (char *)s + 1;
		}
		++s;
	}
	if (wrd_begin != s)
		*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
	*result = NULL;
	return (result - nb_words);
}
