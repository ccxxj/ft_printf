# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xxu <xxu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/01 14:24:44 by xxu           #+#    #+#                  #
#    Updated: 2020/11/16 10:51:38 by Xiaojing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_itoa.c\
			ft_memcmp.c\
			ft_memset.c\
			ft_putnbr_fd.c\
			ft_strchr.c\
			ft_strlcat.c\
			ft_strmapi.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_atoi.c\
			ft_isalnum.c\
			ft_isdigit.c\
			ft_isascii.c\
			ft_toupper.c\
			ft_strncmp.c\
			ft_calloc.c\
			ft_memccpy.c\
			ft_memcpy.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_memcpy.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_bzero.c\
			ft_isalpha.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_memmove.c\
			ft_putendl_fd.c\
			ft_split.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strnstr.c\
			ft_strtrim.c\
			ft_substr.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstiter.c\
			ft_lstdelone.c ft_lstclear.c\
			ft_lstmap.c
REG_OBJ_FILES = $(SRCS:.c=.o)
OBJ_BONUS_FILES = $(BONUS_SRCS:.c=.o)
HEADER_FILES = libft.h
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(OBJ_BONUS_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)

bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
