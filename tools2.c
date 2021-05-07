/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:21:47 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/14 13:45:42 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortdir(char **ls, char **av, int i)
{
	int			j;
	struct stat	st;

	j = 0;
	while (av[j])
	{
		if (lstat(av[j], &st) != -1)
			if (S_ISDIR(st.st_mode))
				ls[i++] = av[j];
		j++;
	}
	ls[i] = NULL;
}

void	ft_puthead(char **av, int i, char *path)
{
	if (!(!i && !av[i + 1]))
	{
		if (i)
			ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

int		ft_error(char **av, int i, char **path)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(*path);
	*path = av[++i];
	return (i);
}

void	ft_ls(int ac, char **path, char **av, t_flag flag)
{
	struct stat	st;
	t_path		*pa;
	static int	i;

	if (lstat(*path, &st) == -1)
		i = ft_error(av, i, path);
	else
	{
		if (ac == 5 && S_ISDIR(st.st_mode) && !flag.d)
			ft_puthead(av, i, *path);
		if (ft_main(&pa, &flag, path))
		{
			if (flag.r_maj && !flag.d)
				ft_rec(pa, flag);
			if (av && av[i])
				*path = av[++i];
			else
				*path = NULL;
			ft_delall(&pa);
		}
		else
			*path = av[++i];
	}
}
