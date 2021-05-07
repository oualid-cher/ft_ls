/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:05:46 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/04 01:05:47 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (haystack[0] == '\0' && needle[0] == '\0' && len)
		return (&((char *)haystack)[0]);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i] && needle[j] && haystack[i] && i < len)
		{
			j++;
			i++;
		}
		if (j == ft_strlen(needle))
			return (&((char *)haystack)[i - j]);
		i = (i - j) + 1;
	}
	return (0);
}
