/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:46:51 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/11/15 11:55:39 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include "./libft/libft.h"

typedef struct	s_len
{
	int		len_lnk;
	int		len_usr;
	int		len_grp;
	int		len_size;
	int		len_minor;
	int		len_major;
}				t_len;

typedef	struct	s_path
{
	char			*path;
	char			*name;
	struct s_path	*next;
}				t_path;

typedef struct	s_flag
{
	int		l;
	int		r_maj;
	int		a;
	int		r;
	int		t;
	int		u_maj;
	int		d;
	int		f;
	int		g;
}				t_flag;

typedef struct	s_sort
{
	t_path	*cmp;
	t_path	*ptr;
	t_path	*head;
	char	*name;
	char	*path;
}				t_sort;
int				ft_flag(char **av, t_flag *flag);
t_path			*ft_new(void);
void			ft_add(t_path **src);
void			ft_del(t_path **arg);
void			ft_delall(t_path **arg);
int				ft_print(char c);
void			ft_sortlist(t_path **lst);
void			ft_mode(char *path, struct stat st);
char			*ft_readjoin(char *s1, char *s2);
t_path			*ft_dir(char *path, int i);
int				ft_intlen(unsigned int i);
void			ft_len(struct stat st, t_len *len);
void			ft_printspace(int count);
void			ft_printl(char *path, struct stat st, t_len len, t_flag *flag);
void			ft_printtime(time_t time);
void			ft_sortlistr(t_path **lst);
void			ft_sortlistt(t_path **lst);
t_path			*ft_task(t_path **pa, t_flag flag);
int				ft_main(t_path **pa, t_flag *flag, char **path);
void			ft_lsmain(char **str, int ac);
void			ft_printls(t_path *pa, int i, t_len *len, t_flag *flag);
int				ft_lslparam(t_path **pa, t_len *len);
void			ft_r(char *av, t_flag flag);
void			ft_sortascii(char	**av);
int				ft_sorterror(char **av, char **ls);
int				ft_sortfile(char **av, char **ls, int i);
void			ft_sortdir(char **ls, char **av, int i);
void			ft_puthead(char **av, int i, char *path);
int				ft_error(char **av, int i, char **path);
void			ft_rec(t_path *pr, t_flag flag);
void			ft_ls(int ac, char **path, char **av, t_flag flag);
void			ft_acl(char *path);
void			ft_printparam(t_len len, struct passwd *pwd,
				struct group *grp, struct stat st);
void			ft_printlnk(t_len len, struct stat st);
int				ft_flagl(int i, t_path *pa, t_len *len, t_flag *flag);
int				ft_func(t_path **pa, t_flag *flag, t_len *len, t_path *dir);
int				ft_fill(t_path **pa, char **path);
int				aff_usage(char c);
int				ft_checkflag(char c, t_flag *flag);
void			ft_nodeswap(t_sort *sort);
int				condition_(struct stat st1, struct stat st2, int ret);
void			ft_checksb(struct stat st, int i);
char			**ft_tsort(char **av, int ac);
char			**ft_rsort(char **av, int ac);
char			**ft_argmanager(char **str, int ac, t_flag flag);
char			**ft_avsort(char **argv, int ac, int i, t_flag flag);

#endif
