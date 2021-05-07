/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:36:20 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/03 23:36:21 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] || (s[0] == '\0' && s[0] == (unsigned char)c))
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		else if (s[i + 1] == (unsigned char)c)
			return (&((char *)s)[i + 1]);
		i++;
	}
	return (0);
}
