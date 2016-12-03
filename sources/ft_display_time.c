#include "../includes/ft_memory.h"

void		ft_get_time(time_t tm_file)
{
	char		*str_ctime;
	time_t		tm_now;
	time_t		tm_diff;
	char 		**tmp;
	int i = 0;

	time(&tm_now);
	tm_diff = tm_now - tm_file;
	str_ctime = ctime(&tm_file);
	tmp = ft_strsplit(str_ctime, ' ');
	if (tm_diff >= T_MONTH || tm_diff < -T_MONTH || tm_diff > tm_now)
		fpf_printf("%-3s %2s  %-.*s ", tmp[1], tmp[2], ft_strlen(tmp[4]) - 1,tmp[4]);
	else
		fpf_printf("%-3s %2s %.5s ", tmp[1], tmp[2], tmp[3]);
	while (tmp[i])
	{
		ft_memdel((void*)&tmp[i]);
		i++;
	}
	ft_memdel((void*)&tmp);
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
				// tmp->info = ft_fill_info(&sb);
				ft_display_l(tmp, sb, path2);
				ft_memdel((void*)&path2);
			}
			else
				fpf_printf("%s\n", tmp->name);
		tmp = tool_lst_file_del(tmp);
	}
	return (tmp);
}