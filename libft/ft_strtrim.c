/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 03:06:22 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 03:06:24 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s);
		if (s[j] == '\0')
			--j;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (i == ft_strlen(s))
			return (ft_strnew(0));
		else
			while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
				j--;
		return (ft_strsub(s, i, (j - i + 1)));
	}
	return (NULL);
}
