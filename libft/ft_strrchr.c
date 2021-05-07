/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:57:51 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/03 23:57:52 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			p = &((char *)s)[i];
		i++;
	}
	if (p != 0)
		return (p);
	return (0);
}
