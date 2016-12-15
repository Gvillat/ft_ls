/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:04:13 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:04:14 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	tool_perm_denied(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Permission denied", 2);
	ft_putchar_fd('\n', 2);
}

int		tool_stats(char *path)
{
	STAT st;
	char *str;

	str = NULL;
	if (lstat(path, &st) == -1)
	{
		str = ft_strjoin("ls: ", path);
		perror(str);
		g_ret = 2;
		ft_memdel((void*)&str);
	}
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

void	tool_stat_error(char *name)
{
	static char *str;

	str = NULL;
	if (!ft_strcmp(name, ""))
	{
		perror("ls: fts_open");
		exit(1);
	}
	else
	{
		str = ft_strjoin("ls: ", name);
		perror(str);
		ft_memdel((void*)&str);
	}
}

char	*tool_checkdirname(char *dir)
{
	if (!dir && !*dir)
		return (dir);
	if (!ft_strcmp(dir, "/"))
		return (ft_strdup(dir));
	if (dir[ft_strlen(dir)] != '/')
		return (ft_strjoin(dir, "/"));
	return (dir);
}

LD		*tool_lst_dir_del(LD *lst)
{
	LD	*tmp;

	tmp = lst->next;
	ft_memdel((void*)&lst->path);
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
	return (tmp);
}
