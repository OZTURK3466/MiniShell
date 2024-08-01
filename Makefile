##
## EPITECH PROJECT, 2023
## printf
## File description:
## makefile
##

NAME	=	mysh

SRCS	=	lib/my/my_putstr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_putfloat.c \
			lib/my/unsigned_nbr.c \
			lib/my/my_putnbr_base.c \
			lib/my/my_compute_power_rec.c \
			lib/my/my_put_e.c \
			lib/my/len_nbr.c \
			lib/my/verif_flags.c \
			lib/my/my_printf.c	\
			lib/my/my_getnbr.c	\
			lib/my/my_strncmp.c	\
			lib/my/my_strncpy.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strcat.c	\
			lib/my/my_strcat_alloc.c	\
			lib/my/my_strdup.c	\
			lib/my/my_getenv.c	\
			lib/my/my_strchr.c	\
			lib/my/my_setenv.c	\
			src/main.c	\
			src/execute.c	\
			src/parse_command.c	\
			src/command_cd.c	\
			src/command_env.c	\
			src/pip.c	\


OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) lib/my/*~
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(NAME)

re: all clean
