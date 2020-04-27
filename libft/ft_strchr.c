/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:55:54 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 12:05:20 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strchr(const char *str, int n)
{
	while (*str)
	{
		if (*str == (char)n)
		{
			return ((char *)str);
		}
		str++;
	}
	if (n == '\0')
		return ((char *)str);
	return (0);
}
