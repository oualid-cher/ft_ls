/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:15:37 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 01:15:38 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = 0;
	if (s)
	{
		mem = ft_strnew(len);
		if (mem == NULL)
			return (0);
		while (i < len && s[i])
		{
			mem[i] = s[start + i];
			i++;
		}
		return (mem);
	}
	return (0);
}
