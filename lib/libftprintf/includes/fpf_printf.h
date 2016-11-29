/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:12 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:13 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF t_printf
# define SPE t_spec
# define BUFF_MAX 58
# define FD 1
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

char	g_buff[BUFF_MAX];
int		g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
** %[flags][width][.precision][length]specifier
** specifier : s S p d D i o O u U x X c C b
*/

typedef struct s_printf	t_printf;
typedef struct s_spec	t_spec;

struct	s_printf
{
	char			*format;
	size_t			index;
	unsigned char	spec;
	int				flags[13];
	char			*arg;
	wchar_t			*warg;
	int				ret;
};

struct	s_spec
{
	int (*spe[128])(PF*, va_list);
};

int		fpf_printf(const char *format, ...);

/*
** DISPLAY
*/

void	fpf_display(PF *argument);
void	*fpf_buff(char *str, PF *argument);
void	fpf_buf(char c, PF *argument);
int		fpf_print_character(PF *argument);
int		fpf_print_str(PF *argument);
int		fpf_print_number(PF *argument, char *pre);

/*
** MEMORY
*/

void	fpf_free(PF *argument);
void	fpf_init_buff();
PF		*fpf_init_argument(PF *argument);
void	fpf_init_spe_tab(SPE *spe);

/*
** LIBPRINTF
*/

char	*fpf_strnew(size_t size);
int		fpf_tolower(int c);
int		fpf_wcharlen(wchar_t wchar);
size_t	fpf_wbytelen(wchar_t *ws);
void	*fpf_strlower(char *s);
int		fpf_atoi(const char *nbr);
char	*fpf_itoa_base(uintmax_t nbr, int base);
int		fpf_wchartostr(char *s, wchar_t wc);
void	fpf_nputchar(char c, ssize_t n, PF *argument);
size_t	fpf_strlen(const char *s);
size_t	fpf_wstrlen(wchar_t *s);
int		fpf_wstrtostr(char *s, wchar_t *wstr, int n);
char	*fpf_strsub(char const *s, unsigned int start, size_t len);
char	*fpf_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char	*fpf_strsub_with_free(char const *s, unsigned int start, size_t len);
char	*fpf_transform_wchar_in_char(wchar_t *ws);
int		fpf_putwchar_in_char(wchar_t wchar, char *fresh, int i);
int		fpf_strcmp(const char *s1, const char *s2);
void	*fpf_memset(void *dest, int c, size_t n);
int		fpf_isescaped(char c);
int		fpf_isdigit(int c);

/*
** HANDLER
*/

int		signed_handler(PF *argument, va_list ap);
int		pointer_handler(PF *argument, va_list ap);
int		character_handler(PF *argument, va_list ap);
int		string_handler(PF *argument, va_list ap);
int		unsigned_handler(PF *argument, va_list ap);
int		fpf_arg_nospe(PF *argument, va_list ap);
int		prc_handler(PF *argument, va_list ap);

/*
** FLAGS
*/

int		fpf_wildcard(PF *argument, va_list ap, int index);
int		fpf_get_flags(PF *argu, va_list ap);
int		fpf_check_flags(PF *argu);
int		fpf_check_width(PF *argu, va_list ap);
int		fpf_check_precision(PF *argument, va_list ap);
void	fpf_check_length(PF *argu);
int		fpf_check_spec(PF *argument);
int		fpf_check_spec_bis(PF *argument);

#endif
