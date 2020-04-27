/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:16:49 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 09:37:13 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int						ft_memcmp(const void *s1, const void *s2, size_t l)
{
	int					i;
	unsigned int		n;
	unsigned int		m;
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	m = 0;
	n = 0;
	while (l > 0)
	{
		if (a[i] != b[i])
		{
			n = (unsigned int)a[i];
			m = (unsigned int)b[i];
			return (n - m);
		}
		i++;
		l--;
	}
	return (0);
}
