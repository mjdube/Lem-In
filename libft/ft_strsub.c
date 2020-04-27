/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:09:12 by mdube             #+#    #+#             */
/*   Updated: 2019/06/17 15:51:54 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char				*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*fresh;

	if (!(s) || !(fresh = ft_memalloc(len + 1)))
		return (NULL);
	fresh = ft_strncpy(fresh, (char *)s + start, len);
	return (fresh);
}
