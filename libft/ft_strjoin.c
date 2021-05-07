/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 02:53:04 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/05 02:53:05 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str == NULL)
			return (0);
		ft_memmove(str, s1, ft_strlen(s1));
		ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
		return (str);
	}
	return (0);
}
