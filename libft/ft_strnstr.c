/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:39:47 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 12:18:35 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char				*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char *)hay);
	j = 0;
	while (hay[j] != '\0' && (size_t)j <= len)
	{
		if (hay[j] == needle[0])
		{
			i = 0;
			while (needle[i] != '\0' && hay[j + i] == needle[i] &&
					(size_t)(j + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&hay[j]);
		}
		j++;
	}
	return (0);
}
