/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:23:27 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/11 00:18:15 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortlist(t_path **lst)
{
	t_sort	sort;

	sort.ptr = *lst;
	sort.cmp = *lst;
	sort.head = *lst;
	while (sort.cmp->next && sort.cmp->name)
	{
		sort.ptr = sort.cmp->next;
		while (sort.ptr->next && sort.cmp->name)
		{
			if (ft_strcmp(sort.cmp->name, sort.ptr->name) > 0)
			{
				sort.name = sort.cmp->name;
				sort.path = sort.cmp->path;
				sort.cmp->name = sort.ptr->name;
				sort.cmp->path = sort.ptr->path;
				sort.ptr->name = sort.name;
				sort.ptr->path = sort.path;
			}
			sort.ptr = sort.ptr->next;
		}
		sort.cmp = sort.cmp->next;
	}
	*lst = sort.head;
}

void	ft_sortlistr(t_path **lst)
{
	t_path	*prev;
	t_path	*current;
	t_path	*next;
	t_path	*tmp;

	current = *lst;
	tmp = *lst;
	prev = NULL;
	while (current && current->name)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	ft_memdel((void**)&current);
	*lst = prev;
}

void	ft_sortlistt(t_path **lst)
{
	t_sort		sort;
	struct stat	st1;
	struct stat	st2;

	sort.ptr = *lst;
	sort.cmp = *lst;
	while (sort.cmp->next && sort.cmp->name)
	{
		lstat(sort.cmp->path, &st1);
		sort.ptr = sort.cmp->next;
		while (sort.ptr->next && sort.ptr->name)
		{
			lstat(sort.ptr->path, &st2);
			if (condition_(st1, st2, ft_strcmp(sort.cmp->name, sort.ptr->name)))
			{
				ft_nodeswap(&sort);
				lstat(sort.cmp->path, &st1);
			}
			sort.ptr = sort.ptr->next;
		}
		sort.cmp = sort.cmp->next;
	}
}

void	ft_sortascii(char **av)
{
	char	*str;
	int		j;

	j = 0;
	str = NULL;
	while (av[j + 1])
	{
		if (ft_strcmp(av[j], av[j + 1]) > 0)
		{
			str = av[j];
			av[j] = av[j + 1];
			av[j + 1] = str;
			j = -1;
		}
		j++;
	}
}

int		ft_sorterror(char **av, char **ls)
{
	int			j;
	int			i;
	struct stat st;

	j = 0;
	i = 0;
	while (av[j])
	{
		if (lstat(av[j], &st) == -1)
			ls[i++] = av[j];
		j++;
	}
	return (i);
}
