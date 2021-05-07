/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:31:07 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 00:31:08 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mem;
	char	temp;
	size_t	i;

	i = 0;
	temp = 0;
	if (s)
	{
		mem = ft_strnew(ft_strlen(s));
		if (mem == NULL)
			return (0);
		while (s[i])
		{
			temp = f(s[i]);
			mem[i] = temp;
			i++;
		}
		mem[i] = '\0';
		return (mem);
	}
	return (0);
}
