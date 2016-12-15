/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:16:29 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 04:16:30 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_nputchar(char *c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c[i]);
		i++;
	}
}

INFO		*ft_fill_info(STAT *sb)
{
	INFO			*info;
	struct passwd	*psswd;
	struct group	*grp;

	if (!(info = (INFO*)malloc(sizeof(INFO))))
		return (NULL);
	ft_get_type(info, sb);
	info->nb_link = sb->st_nlink;
	psswd = getpwuid(sb->st_uid);
	grp = getgrgid(sb->st_gid);
	info->uid = psswd->pw_name;
	info->major = ft_itoa((int)((char)((int32_t)(((u_int32_t)(sb->st_rdev)
	>> 24) & 0xff))));
	info->minor = ft_itoa((int)((char)sb->st_rdev));
	info->guid = grp->gr_name;
	info->size = sb->st_size;
	return (info);
}

void		ft_get_time(time_t tm_file)
{
	char		*str_ctime;
	time_t		tm_now;
	time_t		tm_diff;
	char		**tmp;
	int			i;

	i = 0;
	time(&tm_now);
	tm_diff = tm_now - tm_file;
	str_ctime = ctime(&tm_file);
	tmp = ft_strsplit(str_ctime, ' ');
	fpf_printf("%-3s %2s ", tmp[1], tmp[2]);
	if (tm_diff >= T_MONTH || tm_diff < -T_MONTH || tm_diff > tm_now)
	{
		ft_putchar(' ');
		ft_nputchar(tmp[4], ft_strlen(tmp[4]) - 1);
	}
	else
		ft_nputchar(tmp[3], 5);
	ft_putchar(' ');
	while (tmp[i])
		ft_memdel((void*)&tmp[i++]);
	ft_memdel((void**)&tmp);
}

LF			*tool_lst_file_del(LF *lst)
{
	LF	*tmp;

	tmp = lst->next;
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
	return (tmp);
}

LF			*ft_display(LF *tmp, char *path)
{
	STAT sb;
	char *path2;
	char *temp;

	while (tmp)
	{
		if (g_opt_l && !g_opt_1)
		{
			temp = tool_checkdirname(path);
			path2 = ft_strjoin(temp, tmp->name);
			ft_memdel((void**)&temp);
			lstat(path2, &sb);
			ft_display_l(tmp, sb, path2);
			ft_memdel((void*)&path2);
		}
		else
			fpf_printf("%s\n", tmp->name);
		tmp = tool_lst_file_del(tmp);
	}
	return (tmp);
}
