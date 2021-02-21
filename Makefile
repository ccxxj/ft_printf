# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Xiaojing <Xiaojing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/21 11:37:05 by Xiaojing      #+#    #+#                  #
#    Updated: 2021/02/21 11:05:18 by Xiaojing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_FILE =  ft_printf.c\
			ft_replace.c\
			ft_process.c\
			ft_htoa.c\
			ft_utils.c\
			print_char.c\
			print_intd.c\
			print_str.c
                
OBJ_FILE = $(SRC_FILE:%.c=%.o)
HEADER_FILE = ft_printf.h
LIB_PATH = ./libft
LIBRARY = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILE)
	$(MAKE) -C $(LIB_PATH)
	ar -rcs $@ $^ $(LIBRARY)
	ar -q $(LIBRARY) $(OBJ_FILE)
	cp $(LIBRARY) $(NAME)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILE)
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
