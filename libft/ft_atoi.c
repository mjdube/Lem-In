/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:26:27 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 09:16:10 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	unsigned long long	j;
	int					neg;

	neg = 1;
	i = 0;
	j = 0;
	while (*str && ft_isspace(*str) && ++i)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
		i++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		j = j * 10 + (*str - 48);
		str++;
		i++;
	}
	if (i > 19 || j >= 9223372036854775808ULL)
		return (neg == 1 ? -1 : 0);
	return (j * neg);
}
