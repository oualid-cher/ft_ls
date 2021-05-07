/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:19:22 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/15 03:19:23 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar('-');
			ft_putchar('2');
			n = 147483648;
		}
		else
		{
			n = -n;
			ft_putchar('-');
		}
	}
	nbr = n;
	if (nbr < 10)
		ft_putchar(nbr + '0');
	if (n > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
