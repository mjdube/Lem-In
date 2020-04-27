/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:18:13 by mdube             #+#    #+#             */
/*   Updated: 2019/06/12 17:01:06 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	else if (s1)
		size = ft_strlen(s1);
	else if (s2)
		size = ft_strlen(s2);
	else
		return (NULL);
	if (!(result = (char *)ft_memalloc(size)))
		return (NULL);
	if (s1)
		result = ft_strcpy(result, (char *)s1);
	else
		result = ft_strcpy(result, (char *)s2);
	if (s1 && s2)
		result = ft_strcat(result, (char *)s2);
	return (result);
}
