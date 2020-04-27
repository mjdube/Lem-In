/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:22:01 by mdube             #+#    #+#             */
/*   Updated: 2019/09/27 13:22:08 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long           ft_atoll(const char *str)
{
    long       i;
    long       j;
    long       neg;

    neg = 1;
    j = 0;
    while (*str && ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            neg = -1;
        str++;
    }
    while (*str && *str >= '0' && *str <= '9')
    {
        j = j * 10 + (*str - 48);
        str++;
    }
    return (neg * j);
}