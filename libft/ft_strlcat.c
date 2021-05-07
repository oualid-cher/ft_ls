/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:52:27 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/23 17:52:31 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_size;
	size_t	d_size;
	int		i;

	s_size = ft_strlen(src);
	d_size = ft_strlen(dst);
	i = 0;
	while (size > d_size + i + 1 && src[i])
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	if (size >= d_size)
		return (s_size + d_size);
	else
		return (s_size + size);
}
