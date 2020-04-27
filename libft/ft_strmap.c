/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:12:42 by mdube             #+#    #+#             */
/*   Updated: 2019/06/12 16:29:34 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(const char *s, char (*f)(char))
{
	char	*ptr;
	char	*ptr2;
	char	*result;

	if (s)
	{
		if (!s || !(result = ft_memalloc(ft_strlen((char *)s) + 1)))
			return (NULL);
		ptr = (char *)s;
		ptr2 = result;
		while (*ptr)
			*ptr2++ = f(*(ptr++));
		return (result);
	}
	return (0);
}
