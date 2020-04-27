/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:54:52 by mdube             #+#    #+#             */
/*   Updated: 2019/06/10 09:30:58 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t slen;
	size_t dlen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (n <= dlen)
		return (slen + n);
	while ((dst[i]) && i < (n - 1))
		i++;
	while (*src && i < (n - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
