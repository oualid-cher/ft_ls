/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:56:53 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/10 23:37:07 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flagl(int i, t_path *pa, t_len *len, t_flag *flag)
{
	struct stat st;

	if (i >= 0)
	{
		ft_putstr("total ");
		ft_putnbr(i);
		ft_putchar('\n');
	}
	i = -1;
	if (lstat(pa->path, &st) == -1)
		return (-2);
	ft_printl(pa->path, st, *len, flag);
	return (i);
}

int		ft_checkflag(char c, t_flag *flag)
{
	if (c == 'l')
		flag->l = 1;
	else if (c == 'R')
		flag->r_maj = 1;
	else if (c == 'a')
		flag->a = 1;
	else if (c == 'r')
		flag->r = 1;
	else if (c == 't')
		flag->t = 1;
	else if (c == 'U')
		flag->u_maj = 1;
	else if (c == 'd')
		flag->d = 1;
	else if (c == 'f')
	{
		flag->a = 1;
		flag->u_maj = 1;
	}
	else if (c == 'g')
		flag->g = 1;
	else
		return (aff_usage(c));
	return (1);
}

int		ft_func(t_path **pa, t_flag *flag, t_len *len, t_path *dir)
{
	t_path	*head;

	head = ft_task(&dir, *flag);
	*pa = head;
	return (ft_lslparam(pa, len));
}

int		ft_fill(t_path **pa, char **path)
{
	*pa = ft_new();
	(*pa)->name = ft_strdup(*path);
	(*pa)->path = ft_strdup(*path);
	return (-1);
}

int		condition_(struct stat st1, struct stat st2, int ret)
{
	if (st1.st_mtime < st2.st_mtime)
		return (1);
	else if ((st1.st_mtime == st2.st_mtime) && ret > 0)
		return (1);
	return (0);
}
