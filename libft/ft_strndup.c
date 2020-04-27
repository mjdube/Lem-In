/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:07:31 by mdube             #+#    #+#             */
/*   Updated: 2019/06/13 14:34:06 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (NULL);
	s = ft_strncpy(s, (char *)str, n);
	s[n] = '\0';
	return (s);
}
