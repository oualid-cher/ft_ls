/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:00:47 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/12 14:30:58 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_checksb(struct stat st, int i)
{
	if ((st.st_mode & S_IXUSR) && (S_ISUID & st.st_mode) && i == 1)
		ft_putchar('s');
	else if (!(st.st_mode & S_IXUSR) && (S_ISUID & st.st_mode) && i == 1)
		ft_putchar('S');
	else if ((st.st_mode & S_IXUSR && i == 1))
		ft_putchar('x');
	else if ((st.st_mode & S_IXGRP) && (S_ISGID & st.st_mode) && i == 2)
		ft_putchar('s');
	else if (!(st.st_mode & S_IXGRP) && (S_ISGID & st.st_mode) && i == 2)
		ft_putchar('S');
	else if ((st.st_mode & S_IXGRP) && i == 2)
		ft_putchar('x');
	else if ((st.st_mode & S_IXOTH) && (S_ISVTX & st.st_mode) && i == 3)
		ft_putchar('t');
	else if (!(st.st_mode & S_IXOTH) && (S_ISVTX & st.st_mode) && i == 3)
		ft_putchar('T');
	else if ((st.st_mode & S_IXOTH) && i == 3)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	ft_argswap(char **str, int i)
{
	char	*tmp;

	tmp = str[i];
	str[i] = str[i + 1];
	str[i + 1] = tmp;
}

char	**ft_tsort(char **av, int ac)
{
	struct stat	st[2];
	int			i;
	char		**str;

	i = -1;
	if (!(str = (char **)malloc(sizeof(char *) * (ac + 1))))
		return (NULL);
	while (av[++i])
		str[i] = av[i];
	str[i] = NULL;
	i = 0;
	while (str[i + 1])
	{
		lstat(str[i], &st[0]);
		lstat(str[i + 1], &st[1]);
		if (condition_(st[0], st[1], ft_strcmp(str[i], str[i + 1])))
		{
			ft_argswap(str, i);
			i = -1;
		}
		i++;
	}
	return (str);
}

char	**ft_rsort(char **av, int ac)
{
	int			i;
	int			j;
	char		**str;

	i = 0;
	j = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (ac + 1))))
		return (NULL);
	while (av[i])
		i++;
	while (--i >= 0)
	{
		str[j] = av[i];
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_argmanager(char **av, int ac, t_flag flag)
{
	char	**tmp;

	tmp = NULL;
	if (flag.t)
	{
		tmp = av;
		av = ft_tsort(av, ac);
		free(tmp);
	}
	if (flag.r)
	{
		tmp = av;
		av = ft_rsort(av, ac);
		free(tmp);
	}
	return (av);
}
