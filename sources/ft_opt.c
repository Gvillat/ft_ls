/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:14:44 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 03:14:45 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

LS		*ft_check_args(int ac, char **av)
{
	LS *ls;

	ls = ft_init_ls(ac, av, ft_fill_opt(av, ac));
	if (ls->reste < ac)
		ft_check_reste(ls);
	if (ls->reste == ls->ac)
		ft_add_begin_dir(".", &ls->dir);
	return (ls);
}

void	ft_add_args(LF **tmp, LS *ls)
{
	STAT	st;
	DIR		*pdir;

	while ((*tmp))
	{
		if (lstat((*tmp)->name, &st) == -1)
			tool_stat_error((*tmp)->name);
		else if ((S_ISDIR(st.st_mode) || (!g_opt_l && S_ISLNK(st.st_mode)
		&& (pdir = opendir((*tmp)->name)))))
		{
			if ((pdir = opendir((*tmp)->name)))
			{
				ft_add_begin_dir((*tmp)->name, &ls->dir);
				closedir(pdir);
			}
			else
				tool_perm_denied((*tmp)->name);
		}
		else
			ft_add_end_file((*tmp)->name, &ls->file);
		(*tmp) = tool_lst_file_del((*tmp));
	}
}

LS		*ft_check_reste(LS *ls)
{
	LF	*tmp;
	int i;

	tmp = NULL;
	if (!ft_strcmp(ls->av[ls->reste], "--"))
		ls->reste++;
	i = ls->reste;
	while (i < ls->ac)
	{
		ft_add_end_file(ls->av[i], &tmp);
		i++;
	}
	if (tmp)
	{
		ft_sort(&tmp);
		if (g_opt_t)
			ft_sort_time(&tmp, "./");
		ft_add_args(&tmp, ls);
	}
	return (ls);
}

int		ft_check_opt(char c)
{
	if (c == 'a')
		return (g_opt_a = 1);
	else if (c == 'l')
		return (g_opt_l = 1);
	else if (c == 't')
		return (g_opt_t = 1);
	else if (c == 'r')
		return (g_opt_r = 1);
	else if (c == 'R')
		return (g_opt_rup = 1);
	else if (c == '1')
		return (g_opt_1 = 1);
	else
	{
		ft_putstr_fd("/bin/ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-alrRt1] [file ...]", 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	return (0);
}

int		ft_fill_opt(char **av, int ac)
{
	int i;
	int c;

	i = 1;
	c = 1;
	while (i < ac && (av[i][0] == '-' && av[i][1] != '\0')
	&& ft_strcmp(av[i], "--"))
	{
		while (av[i][c] != '\0' && ft_check_opt(av[i][c]))
			c++;
		c = 1;
		i++;
	}
	return (i);
}
