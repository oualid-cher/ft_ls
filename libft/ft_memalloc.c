/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:05:01 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/04 22:05:03 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(sizeof(unsigned int) * size);
	if (mem == NULL)
		return (NULL);
	while ((int)size >= 0)
		mem[(int)size--] = '\0';
	return ((void *)mem);
}
