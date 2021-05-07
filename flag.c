/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 03:47:05 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/11 11:38:13 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printl(char *path, struct stat st, t_len len, t_flag *flag)
{
	struct passwd	*pwd;
	struct group	*grp;
	static int		signal;

	pwd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	ft_mode(path, st);
	if (flag->g)
		pwd = NULL;
	ft_printparam(len, pwd, grp, st);
	if (S_ISCHR(st.st_mode) || signal)
	{
		ft_printlnk(len, st);
		signal = 1;
	}
	else
	{
		ft_printspace(len.len_size - ft_intlen((unsigned int)st.st_size));
		ft_putnbr((int)st.st_size);
	}
	ft_putchar(' ');
	ft_printtime(st.st_mtime);
	ft_putchar(' ');
}

t_path	*ft_task(t_path **pa, t_flag flag)
{
	t_path *tmp;

	tmp = NULL;
	if (!flag.a)
	{
		while ((*pa) && (*pa)->name && (*pa)->name[0] == '.')
		{
			tmp = (*pa)->next;
			ft_del(pa);
			ft_memdel((void **)pa);
			*pa = tmp;
		}
	}
	if (flag.u_maj)
		return (*pa);
	if (flag.t)
		ft_sortlistt(pa);
	else
		ft_sortlist(pa);
	if (flag.r)
		ft_sortlistr(pa);
	return (*pa);
}

void	ft_printls(t_path *pa, int i, t_len *len, t_flag *flag)
{
	t_path		*head;
	char		str[4000];
	struct stat	st;

	head = pa;
	ft_bzero((void *)str, 4000);
	while (pa && pa->name)
	{
		lstat(pa->path, &st);
		if (flag->l && (i = ft_flagl(i, pa, len, flag)) == -2)
			return ;
		ft_putstr(pa->name);
		if (flag->l && S_ISLNK(st.st_mode))
		{
			readlink(pa->path, str, 4000);
			ft_putstr(" -> ");
			ft_putstr(str);
		}
		ft_putchar('\n');
		pa = pa->next;
	}
	pa = head;
}

int		ft_lslparam(t_path **pa, t_len *len)
{
	struct stat	st;
	t_path		*head;
	int			i;

	i = 0;
	head = *pa;
	while ((*pa)->next && (*pa)->name)
	{
		if (lstat((*pa)->path, &st) == -1)
			return (0);
		ft_len(st, len);
		i = i + (int)st.st_blocks;
		*pa = (*pa)->next;
	}
	*pa = head;
	return (i);
}

int		ft_main(t_path **pa, t_flag *flag, char **path)
{
	t_path		*head;
	struct stat	st;
	int			i;
	t_path		*dir;
	t_len		len;

	i = 0;
	len = (t_len){0, 0, 0, 0, 0, 0};
	if (lstat(*path, &st) == -1)
		return (0);
	head = *pa;
	if (S_ISDIR(st.st_mode) && !flag->d)
	{
		if (!(dir = ft_dir(*path, 1)))
			return (0);
		i = ft_func(pa, flag, &len, dir);
	}
	else if (S_ISLNK(st.st_mode) && !flag->l && (dir = ft_dir(*path, 0)))
		i = ft_func(pa, flag, &len, dir);
	else
		i = ft_fill(pa, path);
	ft_printls(*pa, i, &len, flag);
	return (1);
}
