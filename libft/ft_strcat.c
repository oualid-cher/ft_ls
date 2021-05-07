/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 02:41:09 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/03 02:41:11 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		k;

	j = 0;
	i = 0;
	k = ft_strlen(s1);
	while (s2[i])
	{
		s1[i + k] = s2[i];
		i++;
	}
	s1[i + k] = '\0';
	return (s1);
}
