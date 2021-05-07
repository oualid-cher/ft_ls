/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 02:46:16 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/04/13 02:46:17 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (((char *)s)[i + 1] == c || !((char *)s)[i + 1]))
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_wordlength(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (((char *)s)[i] == c)
		i++;
	while (s[i] && ((char *)s)[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static size_t	ft_charcounter(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] && ((char *)s)[i] == c)
	{
		j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**dest;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	k = ft_wordcounter(s, c);
	dest = (char **)malloc(sizeof(char *) * k + 1);
	if (dest == NULL)
		return (NULL);
	while (i < k)
	{
		dest[i] = ft_strnew(ft_wordlength(s, c, j));
		j = j + ft_charcounter(s, c, j);
		dest[i] = ft_strsub(s, j, ft_wordlength(s, c, j));
		j = j + ft_wordlength(s, c, j);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
