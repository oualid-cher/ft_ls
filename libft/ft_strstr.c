/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:20:17 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/04 00:20:18 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return (&((char *)haystack)[0]);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i] && haystack[i] && needle[j])
		{
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
			return (&((char *)haystack)[i - j]);
		else if (j)
			i = i - j + 1;
		else
			i++;
	}
	return (0);
}
