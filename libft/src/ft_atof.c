/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:31:09 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/18 14:06:09 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static float	ft_power(int nb, int exp)
{
	float	result;

	if(exp == 0)
		return (1);
	result = ft_power(nb, exp / 2);
	if (exp % 2 == 0)
		return (result * result);
	else
	{
		if (exp > 0)
			return (nb * result * result);
		else
			return (result * result) / nb;
	}
}

unsigned int	ft_strtol(char *line)
{
	unsigned int	rslt;
	unsigned int	*hexa;
	int				cmp;
	int				power;

	cmp = 0;
	power = 0;
	rslt = 0;
	hexa = (unsigned int*)malloc(sizeof(unsigned int) * ft_strlen(line));
	while (line[cmp])
	{
		if (line[cmp] >= 'A' && line[cmp] <= 'F')
			hexa[cmp] = line[cmp] + 10 - 'A';
		else if (line[cmp] >= '0' && line[cmp] <= '9')
			hexa[cmp] = line[cmp] -  '0';
		cmp++;
	}
	while (--cmp >= 0)
	{
		rslt += hexa[cmp] * ft_power(16, power);
		power++;
	}
	free(hexa);
	return(rslt);
}

static double	get_after_dot(const char *str)
{
	double			nbr;
	unsigned int	div;

	div = 10;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr += (*str - '0') / (double)div;
		div *= 10;
		str++;
	}
	return (nbr);
}

double			ft_atof(const char *str)
{
	double			nbr;
	int				isnegative;

	nbr = 0;
	while (ft_iswp(*str))
		str++;
	isnegative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + *str - '0';
		str++;
	}
	if (*str == '.')
		nbr += get_after_dot(++str);
	nbr *= isnegative;
	return (nbr);
}
