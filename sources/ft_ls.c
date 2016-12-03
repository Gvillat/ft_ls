#include "../includes/ft_memory.h"

void ft_get_info_size(LF *curr,char *dir_path)
{
	char *path;
	LF *tmp;
	STAT sb;

	tmp = curr;
	while (tmp)
	{
		path = ft_strjoin(tool_checkdirname(dir_path), tmp->name);
		if (lstat(path, &sb) == -1)
	    {
	        perror(tmp->name);
	        exit(1);
	    }
		tmp->info = ft_fill_info(&sb);
		tmp->info->nb_link > g_link_max ? g_link_max = ft_decade(tmp->info->nb_link) : ft_decade(g_link_max);
		ft_strlen(tmp->info->uid) > g_uid_max ? g_uid_max = ft_strlen(tmp->info->uid) : g_uid_max;
		ft_strlen(tmp->info->guid) > g_guid_max ? g_guid_max = ft_strlen(tmp->info->guid) : g_guid_max;
		tmp->info->size > g_size_max ? g_size_max = tmp->info->size : g_size_max;
		ft_strlen(tmp->info->major) > g_major_max ? g_major_max = ft_strlen(tmp->info->major) : g_major_max;
		ft_strlen(tmp->info->minor) > g_minor_max ? g_minor_max = ft_strlen(tmp->info->minor) : g_minor_max;
		tmp = tmp->next;
		ft_memdel((void*)&path);
	}
}

void ft_clean_info_size()
{
	g_size_max = 0;
	g_uid_max = 0;
	g_guid_max = 0;
	g_link_max = 0;
	g_minor_max = 0;
	g_major_max = 0;
}

LS *ft_init_ls(int ac, char **av, int reste)
{
	LS *new;

	if (!(new = (LS*)malloc(sizeof(LS))))
		return(NULL);
	new->ac = ac;
	new->av = av;
	new->reste = reste;
	new->dir = NULL;
	new->file = NULL;
	return (new); 
}

LS *ft_check_args(int ac, char **av)
{
	LS *ls;

	ls = ft_init_ls(ac, av, ft_fill_opt(av, ac));
	if (ls->reste < ac)
		ft_check_reste(ls);
	if (ls->reste == ls->ac)
		ft_add_begin_dir("./", &ls->dir);
	return(ls);
}

void ft_start(LS *ls)
{
	LD *tmp;

	tmp = ls->dir;
	if (ls->file)
	{
		ft_get_info_size(ls->file, "./");
		ft_display(ls->file, "./");
		ft_clean_info_size();
		if (tmp)
			ft_putchar('\n');
	}
	ft_memdel((void*)&ls->file);
	// read une premiere fois le tout sans -R
	// si -R relire la list et ajouter avec check_file a la suite 
	while (tmp)
	{
		ft_read(tmp);
		tmp = tmp->next;
		ft_sort_args(&tmp);
	}
}

// static void ft_free(LS *ls)
// {
// 	LD **tmp = NULL;
// 	LF **temp = NULL;

// 	while (ls->dir)
// 	{
// 		if (ls->dir->file)
// 		{
// 			*temp = ls->dir->file;
// 			if (ls->dir->file->info)
// 				free(ls->dir->file->info);
// 			ls->dir->file = ls->dir->file->prev;
// 			free(*temp);
// 		}
// 		*tmp = ls->dir;
// 		ls->dir = ls->dir->prev;
// 		free(tmp);
// 	}
// }

LD	*tool_lst_dir_del(LD *lst)
{
	LD	*tmp;

	tmp = lst->next;
	ft_memdel((void*)&lst->path);
	// ft_memdel((void*)&lst->file);
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
	return (tmp);
}




void ft_end(LS *ls)
{
	int on = 0;
	DIR *pdir;

	while (ls->dir)
	{
			if ((ls->ac - ls->reste) > 1 || on)
				fpf_printf("%s:\n", ls->dir->path);
			if ((pdir = opendir(ls->dir->path)))
			{
				if (opt_l && ls->dir->file)
				{
					fpf_printf("total %d\n", ls->dir->size);
					ft_get_info_size(ls->dir->file, ls->dir->path);
				}
				ft_display(ls->dir->file, ls->dir->path);
				ft_memdel((void*)&ls->dir->path);
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
}

int main(int ac, char **av)
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
	ft_end(ls);
	ft_memdel((void*)&ls);
	return (g_ret);
}