#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# define LS t_ls
# define LF t_list_file
# define LD t_list_dir
# define INFO t_info
# define STAT struct stat
# define T_MONTH 15778800


# include "../lib/libftprintf/includes/fpf_printf.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
// # include <attr/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include "../includes/libft.h"

typedef struct 	s_list_file 	t_list_file;
typedef struct 	s_list_dir		t_list_dir;
typedef struct 	s_info			t_info;
typedef struct 	s_ls 			t_ls;

struct s_info
{
	mode_t 			st_mode;
	char 			type; 
	char			permission[10];  //%lo (octal)(unsigned long) sb.st_mode);
	int				nb_link; //"Nombre de liens :                  %ld\n", (long) sb.st_nlink);
	char			*uid; //(long) sb.st_uid
	char			*guid; //(long) sb.st_gid)
	long			size; //(long long) sb.st_size)
	char 			*minor;
	char 			*major;
	quad_t			st_blocks; //(long long) sb.st_blocks
	time_t			ctime; //("Dernier changement d’état :        %s", ctime(&sb.st_ctime));
	time_t			atime; //("Dernier accès au fichier :         %s", ctime(&sb.st_atime));
	char			*mtime; //"Dernière modification du fichier:  %s", ctime(&sb.st_mtime));
};

struct 					s_list_file
{
	LF 			*next;
	LF 			*prev;
	char 		*name;
	INFO 		*info;
};

struct 					s_list_dir
{
	LD 			*next;
	LD 			*prev;
	char 		*path;
	char 		*name;
	LF 			*file;
	// quad_t 		st_block;
};

struct 					s_ls
{
	int 		ac;
	int 		reste;
	char 		**av;
	LD 			*dir;
	LF 			*file;
	// STAT 		st;	
};

typedef enum
{
				false,
				true
}															t_opt;

t_opt		opt_a;
t_opt		opt_l;
t_opt		opt_r;
t_opt		opt_R;
t_opt 		opt_t;

int 	ft_sort(LF **curr);
char *ft_get_time(time_t tm_file)

LF 		*ft_display(LF *tmp, char *path);


int 	tool_stats(char *path);

LD 		*ft_check_files(LD *curr, char *path);
LD 		*ft_read(LD *curr);

char	*tool_checkdirname(char *dir);

int 	ft_check_opt(char c);
int		ft_fill_opt(char **av, int ac);


LS 		*ft_init_ls(int ac, char **av, int reste);

LD 		*ft_add_begin_dir(char *name, LD **curr);
void	ft_add_end_dir(char *name, LD **curr);
void 	ft_del_dir(LD);
LD 		*ft_create_dir(char *name);

LF 		*ft_add_begin_file(char *name, LF **curr);
LF 		*ft_add_end_file(char *name, LF **curr);
void	ft_del_file();
LF 		*ft_create_file(char *name);

void 	ft_print_file(LF *list);

LS 		*ft_sort_dir();
int ft_sort_args(LD **curr);

LD 		*ft_sort_file();

#endif