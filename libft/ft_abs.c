/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:15:25 by mdube             #+#    #+#             */
/*   Updated: 2019/06/19 13:24:02 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_abs(int x)
{
	if (x < 0)
	{
		return (-(x));
	}
	return (x);
}
