/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:30:07 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 04:30:10 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

LF		*ft_add_file_a(char *name, LF **file)
{
	if (g_opt_a)
		ft_add_end_file(name, file);
	else if (name[0] != '.')
		ft_add_end_file(name, file);
	return (*file);
}

int		ft_check_files(LD *curr)
{
	LF		*file;
	STAT	st;
	int		block;
	char	*str;
	char	*temp;

	block = 0;
	file = curr->file;
	while (file)
	{
		temp = tool_checkdirname(curr->path);
		str = ft_strjoin(temp, file->name);
		free(temp);
		lstat(str, &st);
		ft_memdel((void*)&str);
		if ((S_ISDIR(st.st_mode) && g_opt_rup && (ft_strcmp(file->name, "."))
		&& (ft_strncmp(file->name, "..", 2))))
			ft_add_next_dir(file->name, &curr);
		if (g_opt_l)
			block += st.st_blocks;
		file = file->next;
	}
	return (block);
}

LD		*ft_read(LD *curr)
{
	DIR				*pdir;
	struct dirent	*pdirent;

	if ((pdir = opendir(curr->path)))
	{
		while ((pdirent = readdir(pdir)))
			ft_add_file_a(pdirent->d_name, &curr->file);
		ft_sort(&curr->file);
		if (g_opt_t)
			ft_sort_time(&curr->file, curr->path);
		curr->size = ft_check_files(curr);
		closedir(pdir);
	}
	return (curr);
}

void	ft_end(LS *ls)
{
	static int	on = 0;
	DIR			*pdir;

	if ((ls->ac - ls->reste) > 1 || on)
		fpf_printf("%s:\n", ls->dir->path);
	if ((pdir = opendir(ls->dir->path)))
	{
		if (g_opt_l && ls->dir->file)
		{
			ft_putstr("total");
			ft_putchar(' ');
			ft_putnbr(ls->dir->size);
			ft_putchar('\n');
			ft_get_info_size(ls->dir->file, ls->dir->path);
		}
		ft_display(ls->dir->file, ls->dir->path);
		closedir(pdir);
	}
	else
		fpf_printf("ls: %s: Permission denied\n", ls->dir->name);
	if (ls->dir->next)
		ft_putchar('\n');
	ls->dir = tool_lst_dir_del(ls->dir);
	ft_clean_info_size();
	on = 1;
}

void	ft_start(LS *ls)
{
	if (ls->file)
	{
		ft_get_info_size(ls->file, ".");
		ft_display(ls->file, ".");
		ft_clean_info_size();
		if (ls->dir)
			ft_putchar('\n');
	}
	while (ls->dir)
	{
		ft_read(ls->dir);
		ft_sort_args(&ls->dir->next);
		ft_end(ls);
	}
}
