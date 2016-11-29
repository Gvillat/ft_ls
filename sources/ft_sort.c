#include "../includes/ft_memory.h"

static int	sort_alpha(char *one, char *two)
{
	return (ft_strcmp(one, two) > 0 ? 1 : 0);
}

static int	sort_ralpha(char *one, char *two)
{
	return (ft_strcmp(one, two) < 0 ? 1 : 0);
}

int	sort_time(char *one, char *two, char *path)
{
	STAT st1;
	STAT st2;
	char *pathone;
	char *pathtwo;

	pathone = ft_strjoin(tool_checkdirname(path), one);
	pathtwo = ft_strjoin(tool_checkdirname(path), two);

	lstat(pathone, &st1);
	lstat(pathtwo, &st2);
	return (st1.st_mtime < st2.st_mtime);
}

int	sort_rtime(char *one, char *two, char *path)
{
	STAT st1;
	STAT st2;
	char *pathone;
	char *pathtwo;

	pathone = ft_strjoin(tool_checkdirname(path), one);
	pathtwo = ft_strjoin(tool_checkdirname(path), two);

	lstat(pathone, &st1);
	lstat(pathtwo, &st2);
	return (st1.st_mtime > st2.st_mtime);
}

static int ft_choose_sort(char *s1, char *s2, char *path)
{
	if (opt_r)
		return (sort_rtime(s1,s2, path));
	else
		return (sort_time(s1,s2, path));
}

static int ft_choose_sort_alpha(char *s1, char *s2)
{
	if (opt_r)
		return (sort_ralpha(s1,s2));
	else
		return (sort_alpha(s1,s2));
}

static void	swap(void **one, void **two)
{
	void *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

int ft_sort_args(LD **curr)
{
	static LD *head = NULL;
	LD *tmp;

 	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort_alpha(tmp->path, tmp->next->path))
		{
			swap((void **)&tmp->name, (void **)&tmp->next->name);
			swap((void **)&tmp->path, (void **)&tmp->next->path);
			swap((void **)&tmp->file, (void **)&tmp->next->file);
			swap((void **)&tmp->size, (void **)&tmp->next->size);
			if (tmp != head)
				return(0);
		}
		if (ft_sort_args(&tmp->next))
			return(1);
	}
}

int ft_sort_time(LF **curr, char *path)
{
	static LF *head = NULL;
	LF *tmp;

 	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort(tmp->name, tmp->next->name, path))
		{
			swap((void**)&tmp->name, (void**)&tmp->next->name);
			if (tmp != head)
				return(0);
		}
		if (ft_sort_time(&tmp->next, path))
			return(1);
	}
}

int ft_sort(LF **curr)
{
	static LF *head = NULL;
	LF *tmp;

 	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort_alpha(tmp->name, tmp->next->name))
		{
			swap((void**)&tmp->name, (void**)&tmp->next->name);
			if (tmp != head)
				return(0);
		}
		if (ft_sort(&tmp->next))
			return(1);
	}
}
