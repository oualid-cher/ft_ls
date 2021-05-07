/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 03:37:41 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/04 03:37:42 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	size_t			a;
	int				res;
	unsigned char	*ps;

	i = 0;
	res = 0;
	a = 0;
	ps = (unsigned char *)str;
	while ((ps[i] <= 13 && ps[i] >= 9) || ps[i] == ' ')
		i++;
	if (ps[i] == '-')
		a = 1;
	if (ps[i] == '+' || ps[i] == '-')
		i++;
	while (ps[i] >= '0' && ps[i] <= '9')
	{
		res = res * 10 + (ps[i] - '0');
		i++;
	}
	if (a)
		return (-res);
	else
		return (res);
}
