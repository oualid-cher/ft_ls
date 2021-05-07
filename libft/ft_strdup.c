/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:48:01 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/02 08:48:04 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
