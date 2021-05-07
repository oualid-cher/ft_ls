/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:29:39 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/14 13:55:35 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_avsort(char **argv, int ac, int i, t_flag flag)
{
	char		**av;
	char		**ls;
	int			j;

	j = 0;
	if (!(av = (char **)malloc(sizeof(char *) * (ac - i + 1))))
		return (NULL);
	if (!(ls = (char **)malloc(sizeof(char *) * (ac - i + 1))))
		return (NULL);
	while (argv[i])
	{
		av[j] = argv[i];
		j++;
		i++;
	}
	av[j] = NULL;
	if (!flag.t)
		ft_sortascii(av);
	if (flag.r || flag.t)
		av = ft_argmanager(av, ac, flag);
	i = ft_sorterror(av, ls);
	i = ft_sortfile(av, ls, i);
	ft_sortdir(ls, av, i);
	free(av);
	return (ls);
}

void	ft_rec(t_path *pr, t_flag flag)
{
	struct stat	st;
	t_path		*head;

	head = pr;
	while (pr && pr->name)
	{
		if (lstat(pr->path, &st) == -1)
		{
			ft_putstr_fd("ft_ls :", 2);
			perror(pr->path);
			return ;
		}
		if (ft_strcmp(pr->name, ".") && ft_strcmp(pr->name, ".."))
		{
			if (S_ISDIR(st.st_mode))
				ft_r(pr->path, flag);
		}
		pr = pr->next;
	}
	pr = head;
}

void	ft_r(char *av, t_flag flag)
{
	t_path		*pr;
	int			i;
	t_len		len;

	i = 0;
	len = (t_len){0, 0, 0, 0, 0, 0};
	ft_putchar('\n');
	ft_putstr(av);
	ft_putstr(":\n");
	if (!(pr = ft_dir(av, 1)))
		return ;
	pr = ft_task(&pr, flag);
	i = ft_lslparam(&pr, &len);
	ft_printls(pr, i, &len, &flag);
	ft_rec(pr, flag);
	ft_delall(&pr);
}

void	ft_lsmain(char **str, int ac)
{
	t_flag		flag;
	int			i;
	char		*path;
	char		**av;

	i = 0;
	av = NULL;
	flag = (t_flag){0, 0, 0, 0, 0, 0, 0, 0, 0};
	path = NULL;
	if ((i = ft_flag(str, &flag)) == -1)
		exit(0);
	(flag.g) && (flag.l = 1);
	if (!(str[i]))
		path = ".";
	else
	{
		av = ft_avsort(str, ac, i, flag);
		i = 0;
		path = av[i];
	}
	if (ac > (i + 1))
		ac = 5;
	while ((path))
		ft_ls(ac, &path, av, flag);
	free(av);
}

int		main(int ac, char **av)
{
	ft_lsmain(av, ac);
	return (0);
}
