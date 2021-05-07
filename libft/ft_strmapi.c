/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:50:55 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 00:50:56 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mem;
	char	temp;

	i = 0;
	temp = 0;
	if (s)
	{
		mem = ft_strnew(ft_strlen(s));
		if (mem == NULL)
			return (NULL);
		while (s[i])
		{
			temp = s[i];
			mem[i] = f(i, temp);
			i++;
		}
		return (mem);
	}
	return (0);
}
