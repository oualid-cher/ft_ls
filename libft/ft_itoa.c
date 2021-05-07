/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 05:11:40 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/14 05:11:41 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compt_digit(int n)
{
	int		counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static char		*ft_fill(int n, char *str, int i, int tst)
{
	char	tmp;

	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (--i > tst)
	{
		tmp = (n % 10) + 48;
		n /= 10;
		str[i] = tmp;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		tst;
	char	*str;

	tst = 0;
	i = ft_compt_digit(n);
	if ((str = ft_strnew(i)))
	{
		str[i] = '\0';
		if (n >= 0)
			tst = -1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		else
			ft_fill(n, str, i, tst);
		return (str);
	}
	return (NULL);
}
