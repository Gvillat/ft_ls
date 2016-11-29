.PHONY: all clean fclean re

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBSRC = 	lib/fpf_isdigit.c \
			lib/fpf_isescaped.c \
			lib/fpf_atoi.c \
			lib/fpf_itoa_base.c \
			lib/fpf_memset.c \
			lib/fpf_nputchar.c \
			lib/fpf_strlen.c \
			lib/fpf_strlower.c \
			lib/fpf_strnew.c \
			lib/fpf_strsub.c \
			lib/fpf_wstrtostr.c \
			lib/fpf_wchartostr.c \
			lib/fpf_wstrlen.c \
			lib/fpf_tolower.c \
			lib/fpf_strcmp.c \
			lib/fpf_wcharlen.c \

SRC =	source/fpf_printf.c \
		source/fpf_display.c \
		source/fpf_flags.c \
		source/fpf_memory.c \
		source/fpf_char_conv.c \
		source/fpf_ptr_conv.c \
		source/fpf_str_conv.c \
		source/fpf_signed_conv.c \
		source/fpf_unsigned_conv.c\
		source/fpf_wildcard.c\
		$(LIBSRC)\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o:%.c
	$(CC) $(CFLAGS) -c -I includes/ -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all