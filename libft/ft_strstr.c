/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:21:53 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 12:39:41 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char				*ft_strstr(const char *hay, const char *needle)
{
	unsigned int	j;
	unsigned int	i;

	if (!*needle)
		return ((char *)hay);
	j = 0;
	while (hay[j] != '\0')
	{
		if (hay[j] == needle[0])
		{
			i = 0;
			while (needle[i] != '\0' && hay[j + i] == needle[i])
				++i;
			if (needle[i] == '\0')
				return ((char *)&hay[j]);
		}
		++j;
	}
	return (0);
}
