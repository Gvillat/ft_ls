#include "../includes/ft_memory.h"

void		ft_get_time(time_t tm_file)
{
	char		*str_ctime;
	time_t		tm_now;
	time_t		tm_diff;
	char 		**tmp;

	time(&tm_now);
	tm_diff = tm_now - tm_file;
	str_ctime = ctime(&tm_file);
	tmp = ft_strsplit(str_ctime, ' ');
	tmp[1][0] = ft_tolower(tmp[1][0]);

	if (tm_diff >= T_MONTH || tm_diff < -T_MONTH || tm_diff > tm_now)
		fpf_printf("%2s %-3s  %-.*s ", tmp[2], tmp[1], ft_strlen(tmp[4]) - 1,tmp[4]);
	else
		fpf_printf("%2s %-3s %.5s ", tmp[2], tmp[1], tmp[3]);
}

LF	*tool_lst_file_del(LF *lst)
{
	LF	*tmp;

	tmp = lst->next;
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
	return (tmp);
}

LF *ft_display(LF *tmp, char *path)
{
	STAT sb;
	char *path2;

	while (tmp)
	{
			if (opt_l)
			{
				path2 = ft_strjoin(tool_checkdirname(path), tmp->name);
				lstat(path2, &sb);
				tmp->info = ft_fill_info(&sb);
				ft_display_l(tmp, sb, path2);
				free(path2);
			}
			else
				fpf_printf("%s\n", tmp->name);
		tmp = tool_lst_file_del(tmp);
	}
	return (tmp);
}