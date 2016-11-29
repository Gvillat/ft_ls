#include "../includes/ft_memory.h"

LS *ft_add_args(LF **tmp, LS *ls)
{
	LF *chibre;
	STAT st;

	chibre = *tmp;
	while (chibre)
	{
		if (lstat(chibre->name, &st) == -1)
	    {
	    	if (!ft_strcmp(chibre->name, ""))
	    	{
	    		perror("ls: fts_open");
	      		exit (1);
	    	}
	    	else
	     	   perror(ft_strjoin("ls: ", chibre->name));
	    }
		else if ((S_ISDIR(st.st_mode) || (!opt_l && S_ISLNK(st.st_mode) && opendir(chibre->name))))
		{
			if (opendir(chibre->name))
				ft_add_begin_dir(chibre->name, &ls->dir);
			else
			{
				ft_putstr_fd("ls: ", 2);
				ft_putstr_fd(chibre->name, 2);
				ft_putstr_fd(": Permission denied", 2);
				ft_putchar_fd('\n', 2);
			}
		}
		else
			ft_add_end_file(chibre->name, &ls->file);			
		chibre = chibre->next;
	}
	// ft_free(tmp);
	return(ls);
}

LS *ft_check_reste(LS *ls)
{
	LF *tmp = NULL;
	int i;

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
		if (opt_t)
			ft_sort_time(&tmp, "./");
		ft_add_args(&tmp, ls);
	}
	return(ls);
}

int 	ft_check_opt(char c)
{
	if (c == 'a')
		return (opt_a = 1);
	else if (c == 'l')
		return (opt_l = 1);
	else if (c == 't')
		return (opt_t = 1);
	else if (c == 'r')
		return (opt_r = 1);
	else if (c == 'R')
		return (opt_R = 1);
	else if (c == '1')
		return(1);
	else
	{
		ft_putstr_fd("/bin/ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx2] [file ...]", 2);
		ft_putchar_fd('\n', 2);
		exit (1);
	}
	return (0);
}

int	ft_fill_opt(char **av, int ac)
{
	int i;
	int c;

	i = 1;
	c = 1;
	while(i < ac && (av[i][0] == '-' && av[i][1] != '\0') && ft_strcmp(av[i], "--"))
	{
		while(av[i][c] != '\0' && ft_check_opt(av[i][c]))
			c++;
		c = 1;
		i++;
	}
	return(i);
}