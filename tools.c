/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 03:57:29 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/09 10:18:52 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_readjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	if (ft_strcmp(s1, "/"))
		str = ft_strjoin(s1, "/");
	else
		str = ft_strdup(s1);
	tmp = str;
	str = ft_strjoin(str, s2);
	ft_strdel(&tmp);
	return (str);
}

void	ft_printspace(int count)
{
	int		i;

	i = -1;
	while (++i < count)
		ft_putchar(' ');
}

void	ft_put(char *str, int start, int end)
{
	while (str[start] && start <= end)
	{
		ft_putchar(str[start]);
		start++;
	}
}

void	ft_printtime(time_t t1)
{
	time_t	t2;

	time(&t2);
	if (t2 - t1 < 15768000)
		ft_put(ctime(&t1), 4, 15);
	else
	{
		ft_put(ctime(&t1), 4, 10);
		ft_putchar(' ');
		ft_put(ctime(&t1), 20, 23);
	}
}

int		ft_sortfile(char **av, char **ls, int i)
{
	int			j;
	struct stat	st;

	j = 0;
	while (av[j])
	{
		if (lstat(av[j], &st) != -1)
			if (!S_ISDIR(st.st_mode))
				ls[i++] = av[j];
		j++;
	}
	return (i);
}
