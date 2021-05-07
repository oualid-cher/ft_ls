/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:12:47 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 00:12:48 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char	*))
{
	size_t	i;

	i = 0;
	if (s && f)
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
}
