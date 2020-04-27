/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:01:10 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 12:07:15 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) < 0)
		return (-1);
	else if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) > 0)
		return (1);
	else
		return (0);
}
