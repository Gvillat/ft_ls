/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:04:21 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:04:22 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS t_ls
# define LF t_list_file
# define LD t_list_dir
# define INFO t_info
# define STAT struct stat
# define T_MONTH 15778800

# include "../lib/libft/libft.h"
# include "../lib/libftprintf/includes/fpf_printf.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <grp.h>

typedef struct s_list_file	t_list_file;
typedef struct s_list_dir	t_list_dir;
typedef struct s_info		t_info;
typedef struct s_ls			t_ls;

int				g_ret;
size_t			g_minor_max;
size_t			g_major_max;
long			g_size_max;
size_t			g_uid_max;
size_t			g_guid_max;
int				g_link_max;

struct						s_info
{
	mode_t		st_mode;
	char		type;
	char		permission[10];
	int			nb_link;
	char		*uid;
	char		*guid;
	long		size;
	quad_t		st_blocks;
	char		*major;
	char		*minor;
	time_t		ctime;
	time_t		atime;
	char		*mtime;
};

struct						s_list_file
{
	LF			*next;
	LF			*prev;
	char		*name;
	INFO		*info;
};

struct						s_list_dir
{
	LD			*next;
	LD			*prev;
	char		*path;
	char		*name;
	LF			*file;
	quad_t		size;
};

struct						s_ls
{
	int			ac;
	int			reste;
	char		**av;
	LD			*dir;
	LF			*file;
};

typedef enum
{
	false,
	true
}	t_opt;

t_opt			g_opt_a;
t_opt			g_opt_l;
t_opt			g_opt_r;
t_opt			g_opt_rup;
t_opt			g_opt_t;
t_opt			g_opt_1;

/*
** SORT
*/

int							sort_alpha(char *one, char *two);
int							sort_ralpha(char *one, char *two);
int							sort_time(char *one, char *two, char *path);
int							sort_rtime(char *one, char *two, char *path);
void						swap(void **one, void **two);

/*
** SORT2
*/

int							ft_choose_sort(char *s1, char *s2, char *path);
int							ft_choose_sort_alpha(char *s1, char *s2);
int							ft_sort_args(LD **curr);
int							ft_sort_time(LF **curr, char *path);
int							ft_sort(LF **curr);

/*
** OPT
*/

LS							*ft_check_args(int ac, char **av);
void						ft_add_args(LF **tmp, LS *ls);
LS							*ft_check_reste(LS *ls);
int							ft_check_opt(char c);
int							ft_fill_opt(char **av, int ac);

/*
** READ
*/

LF							*ft_add_file_a(char *name, LF **file);
int							ft_check_files(LD *curr);
LD							*ft_read(LD *curr);
void						ft_end(LS *ls);
void						ft_start(LS *ls);

/*
** MEMORY
*/

LD							*ft_create_dir(char *name);
LF							*ft_create_file(char *name);
LD							*ft_add_begin_dir(char *name, LD **curr);
LD							*ft_add_next_dir(char *name, LD **curr);
LF							*ft_add_end_file(char *name, LF **curr);

/*
** DISPLAY
*/

INFO						*ft_fill_info(STAT *sb);
void						ft_nputchar(char *c, int n);
void						ft_get_time(time_t tm_file);
LF							*tool_lst_file_del(LF *lst);
LF							*ft_display(LF *tmp, char *path);

/*
** L
*/

char						ft_get_type(INFO *curr, STAT *sb);
void						ft_display_permission(mode_t st_mode);
void						ft_free_info(INFO *info);
void						ft_display_l(LF *tmp, STAT sb, char *path);

/*
** TOOL
*/

LD							*tool_lst_dir_del(LD *lst);
char						*tool_checkdirname(char *dir);
int							tool_stats(char *path);
void						tool_stat_error(char *name);
void						tool_perm_denied(char *name);

/*
** LS
*/

void						ft_get_info_size(LF *curr, char *dir_path);
void						ft_clean_info_size(void);
LS							*ft_init_ls(int ac, char **av, int reste);
STAT						ft_magouille(char *dir_path, char *name, STAT sb);

#endif
