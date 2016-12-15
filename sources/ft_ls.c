/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:58:13 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 04:58:13 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

STAT	ft_magouille(char *dir_path, char *name, STAT sb)
{
	char	*path;
	char	*temp;

	if (name[0] != '/')
	{
		temp = tool_checkdirname(dir_path);
		path = ft_strjoin(temp, name);
		ft_memdel((void**)&temp);
	}
	else
		path = ft_strjoin(dir_path, name);
	if (lstat(path, &sb) == -1)
	{
		perror(path);
		exit(1);
	}
	ft_memdel((void*)&path);
	return (sb);
}

void	ft_get_info_size(LF *curr, char *dir_path)
{
	LF		*tmp;
	STAT	sb;

	tmp = curr;
	while (tmp)
	{
		sb = ft_magouille(dir_path, tmp->name, sb);
		tmp->info = ft_fill_info(&sb);
		tmp->info->nb_link > g_link_max ? g_link_max =
		tmp->info->nb_link : g_link_max;
		ft_strlen(tmp->info->uid) > g_uid_max ? g_uid_max =
		ft_strlen(tmp->info->uid) : g_uid_max;
		ft_strlen(tmp->info->guid) > g_guid_max ? g_guid_max =
		ft_strlen(tmp->info->guid) : g_guid_max;
		tmp->info->size > g_size_max ? g_size_max =
		tmp->info->size : g_size_max;
		ft_strlen(tmp->info->major) > g_major_max ? g_major_max =
		ft_strlen(tmp->info->major) : g_major_max;
		ft_strlen(tmp->info->minor) > g_minor_max ? g_minor_max =
		ft_strlen(tmp->info->minor) : g_minor_max;
		tmp = tmp->next;
	}
}

LS		*ft_init_ls(int ac, char **av, int reste)
{
	LS *new;

	if (!(new = (LS*)malloc(sizeof(LS))))
		return (NULL);
	new->ac = ac;
	new->av = av;
	new->reste = reste;
	new->dir = NULL;
	new->file = NULL;
	return (new);
}

void	ft_clean_info_size(void)
{
	g_size_max = 0;
	g_uid_max = 0;
	g_guid_max = 0;
	g_link_max = 0;
	g_minor_max = 0;
	g_major_max = 0;
}

int		main(int ac, char **av)
{
	LS *ls;

	g_ret = 1;
	g_size_max = 0;
	g_uid_max = 0;
	g_guid_max = 0;
	g_link_max = 0;
	g_minor_max = 0;
	g_major_max = 0;
	ls = ft_check_args(ac, av);
	ft_start(ls);
	ft_memdel((void*)&ls);
	return (g_ret);
}
