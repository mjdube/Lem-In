/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:19:32 by mdube             #+#    #+#             */
/*   Updated: 2019/06/23 15:30:50 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	unsigned int	i;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (s == NULL && d == NULL)
		return (NULL);
	else
	{
		while (n != 0)
		{
			d[i] = s[i];
			i++;
			n--;
		}
		return (dst);
	}
	return (NULL);
}
