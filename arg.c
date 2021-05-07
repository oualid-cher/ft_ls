/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:41:02 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/14 13:43:14 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_mode(char *path, struct stat st)
{
	(S_ISDIR(st.st_mode)) && (ft_print('d'));
	(S_ISCHR(st.st_mode)) && (ft_print('c'));
	(S_ISBLK(st.st_mode)) && (ft_print('b'));
	(S_ISFIFO(st.st_mode)) && (ft_print('p'));
	(S_ISLNK(st.st_mode)) && (ft_print('l'));
	(S_ISSOCK(st.st_mode)) && (ft_print('s'));
	(S_ISREG(st.st_mode)) && (ft_print('-'));
	ft_putchar((st.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st.st_mode & S_IWUSR) ? 'w' : '-');
	ft_checksb(st, 1);
	ft_putchar((st.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st.st_mode & S_IWGRP) ? 'w' : '-');
	ft_checksb(st, 2);
	ft_putchar((st.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st.st_mode & S_IWOTH) ? 'w' : '-');
	ft_checksb(st, 3);
	ft_acl(path);
}

int		aff_usage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-lRartUdfg] [file ...]", 2);
	return (-1);
}

int		ft_flag(char **av, t_flag *flag)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i] && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		while (av[i][++j])
		{
			if (av[i][j] == '-' && !av[i][j + 1])
				return (i + 1);
			if (ft_checkflag(av[i][j], flag) < 0)
				return (-1);
		}
	}
	return (i);
}

t_path	*ft_dir(char *path, int i)
{
	DIR				*open;
	struct dirent	*read;
	t_path			*pa;
	t_path			*head;

	if (!path || !(open = opendir(path)))
	{
		if (path && i == 1)
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(path);
		}
		return (NULL);
	}
	pa = ft_new();
	head = pa;
	while ((read = readdir(open)))
	{
		pa->path = ft_readjoin(path, read->d_name);
		pa->name = ft_strdup(read->d_name);
		ft_add(&pa);
		pa = pa->next;
	}
	closedir(open);
	return (head);
}

void	ft_len(struct stat st, t_len *len)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	if (ft_intlen((unsigned int)st.st_nlink) > len->len_lnk)
		len->len_lnk = ft_intlen((unsigned int)st.st_nlink);
	if (ft_strlen(pwd->pw_name) > (size_t)len->len_usr)
		len->len_usr = ft_strlen(pwd->pw_name);
	if (ft_strlen(grp->gr_name) > (size_t)len->len_grp)
		len->len_grp = ft_strlen(grp->gr_name);
	if (ft_intlen((unsigned int)st.st_size) > len->len_size)
		len->len_size = ft_intlen((unsigned int)st.st_size);
	if (S_ISCHR(st.st_mode) &&
	ft_intlen((unsigned int)major(st.st_rdev)) > len->len_major)
		len->len_major = ft_intlen((unsigned int)major(st.st_rdev));
	if (S_ISCHR(st.st_mode) &&
	ft_intlen((unsigned int)minor(st.st_rdev)) > len->len_minor)
		len->len_minor = ft_intlen((unsigned int)minor(st.st_rdev));
}
