#include "../includes/ft_memory.h"

char		*tool_checkdirname(char *dir)
{
	if (dir == NULL)
		return (dir);
	if (dir[ft_strlen(dir) - 1] != '/')
		return (ft_strjoin(dir, "/"));
	return (dir);
}

int tool_stats(char *path)
{
	STAT st;
	static char *str = NULL;

	if (lstat(path, &st) == -1)
	{
		str = ft_strjoin("ls: ", path);
		perror(str);
		g_ret = 2;
		ft_memdel((void*)&str);
	}
	if (S_ISDIR(st.st_mode))
		return(1);
	return(0);
}

LF *ft_add_file_a(char *name, LF **file)
{
	if (opt_a)
		ft_add_end_file(name, file);
	else if (name[0] != '.')
		ft_add_end_file(name, file);		
	return(*file);
}

int ft_check_files(LD *curr)
{
	LF *file;
	STAT st;
	int block;
	char *str = NULL;

	block = 0;
	file = curr->file;
	while (file)
	{
		curr->path = tool_checkdirname(curr->path);
		str = ft_strjoin(curr->path, file->name);
		lstat(str, &st);
		if ((S_ISDIR(st.st_mode) && opt_R && (ft_strcmp(file->name, ".")) && (ft_strncmp(file->name, "..", 2))))
	 		ft_add_end_dir(file->name, &curr);
	 	if (opt_l)
	 		block += st.st_blocks;
		file = file->next;
		ft_memdel((void*)&str);
	}
	return (block);
}

LD *ft_read(LD *curr)
{
	DIR *pdir;
	struct dirent *pdirent;
	
	if ((pdir = opendir(curr->path)))
	{
		while ((pdirent = readdir(pdir)))
			ft_add_file_a(pdirent->d_name, &curr->file);
		ft_sort(&curr->file);
		if (opt_t)
			ft_sort_time(&curr->file, curr->path);
		curr->size = ft_check_files(curr);
  		closedir(pdir);
	}
	return(curr);
}