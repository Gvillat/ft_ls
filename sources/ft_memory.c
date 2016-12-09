#include "../includes/ft_memory.h"

LD *ft_create_dir(char *name)
{
	LD *new;

	if (!(new = (LD*)malloc(sizeof(LD))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	if (name[0] == '/')
		new->path = ft_strdup(name);
	else
		new->path = name;
	new->name = ft_strdup(name);
	new->file = NULL;
	new->size = 0;
	return (new);
}

LF *ft_create_file(char *name)
{
	LF *new;

	if (!(new = (LF*)malloc(sizeof(LF))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->name = fpf_strsub(name, 0, ft_strlen(name) + 1);
	new->info = NULL;
	return (new);
}

LD  *ft_add_begin_dir(char *name, LD **curr)
{
	LD *tmp;


	if (!*curr)
		return (*curr = ft_create_dir(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_dir(name);
	tmp->next->prev = tmp;
	return (tmp->next);
}

void ft_add_end_dir(char *name, LD **curr)
{
	LD *tmp;
	char *path;

	path = (*curr)->path;
	if (!*curr)
		*curr = ft_create_dir(name);
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_dir(name);
	tmp->next->path = ft_strjoin(tool_checkdirname(path), tmp->next->path);
	tmp->next->prev = tmp;
}

LD *ft_add_next_dir(char *name, LD **curr)
{
	LD *tmp;
	char *path;
	char *str;

	path = (*curr)->path;
	if (!*curr)
		return (*curr = ft_create_dir(name));
	if ((*curr)->next)
	{
		tmp = ft_create_dir(name);
		str = tool_checkdirname((*curr)->path);
		tmp->path = ft_strjoin(str, tmp->name);
		ft_memdel((void**)&str);
		tmp->prev = *curr;
		tmp->next = (*curr)->next;
		(*curr)->next->prev = tmp;	
		(*curr)->next = tmp;
	}
	else
	{
		tmp = *curr;
		tmp->next = ft_create_dir(name);
		str = tool_checkdirname((*curr)->path);		
		tmp->next->path = ft_strjoin(str, tmp->next->path);
		ft_memdel((void**)&str);
		tmp->next->prev = tmp;
	}
	return(*curr);
}

LF *ft_add_end_file(char *name, LF **curr)
{
	LF *tmp;

	if (!*curr)
		return (*curr = ft_create_file(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_file(name);
	tmp->next->prev = tmp;
	return((*curr)->next);
}
