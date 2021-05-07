/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:13:12 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/11 00:18:19 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path	*ft_new(void)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->name = NULL;
	path->path = NULL;
	path->next = NULL;
	return (path);
}

void	ft_add(t_path **src)
{
	t_path *tmp;

	tmp = *src;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new();
}

void	ft_del(t_path **arg)
{
	ft_strdel(&(*arg)->name);
	ft_strdel(&(*arg)->path);
}

void	ft_delall(t_path **arg)
{
	t_path	*tmp;

	tmp = NULL;
	while ((*arg))
	{
		tmp = *arg;
		ft_strdel(&(*arg)->name);
		ft_strdel(&(*arg)->path);
		*arg = (*arg)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_nodeswap(t_sort *sort)
{
	sort->name = sort->cmp->name;
	sort->path = sort->cmp->path;
	sort->cmp->name = sort->ptr->name;
	sort->cmp->path = sort->ptr->path;
	sort->ptr->name = sort->name;
	sort->ptr->path = sort->path;
}
