/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:55:20 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/15 12:07:46 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_intlen(unsigned int i)
{
	int		count;

	count = 0;
	while ((i = i / 10) > 0)
		count++;
	return (count + 1);
}

int		ft_print(char c)
{
	ft_putchar(c);
	return (0);
}

void	ft_printparam(t_len len, struct passwd *pwd,
struct group *grp, struct stat st)
{
	ft_putstr(" ");
	ft_printspace(len.len_lnk - ft_intlen((unsigned int)st.st_nlink));
	ft_putnbr((int)st.st_nlink);
	ft_putchar(' ');
	if (pwd)
	{
		ft_putstr(pwd->pw_name);
		ft_printspace(len.len_usr - ft_strlen(pwd->pw_name));
		ft_putstr("  ");
	}
	ft_putstr(grp->gr_name);
	ft_printspace(len.len_grp - ft_strlen(grp->gr_name));
	ft_putstr("  ");
}

void	ft_printlnk(t_len len, struct stat st)
{
	ft_printspace(len.len_major -
	ft_intlen((unsigned int)major(st.st_rdev)));
	if (S_ISLNK(st.st_mode))
		ft_putstr("   ");
	else
	{
		ft_putnbr(major(st.st_rdev));
		ft_putstr(", ");
	}
	ft_printspace(len.len_minor -
	ft_intlen((unsigned int)minor(st.st_rdev)));
	ft_putnbr(minor(st.st_rdev));
	ft_putchar(' ');
}

void	ft_acl(char *path)
{
	acl_t		acl;
	acl_entry_t	entry;
	ssize_t		xattr;
	char		c;

	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		c = '@';
	else if (acl != NULL)
		c = '+';
	else
		c = ' ';
	if (acl)
		acl_free(acl);
	ft_putchar(c);
}
