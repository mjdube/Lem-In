/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:39:21 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 09:36:47 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*src;
	char			chr;

	chr = (char)c;
	src = (char *)s;
	i = 0;
	while (n != 0)
	{
		if (src[i] == chr)
			return (&src[i]);
		i++;
		n--;
	}
	return (NULL);
}
