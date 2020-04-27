/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:01:18 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 12:16:29 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] && s2[i] && s1[i] == s2[i]) && ((size_t)i < n - 1))
		i++;
	if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) < 0)
		return (-1);
	else if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) > 0)
		return (1);
	else
		return (0);
}
