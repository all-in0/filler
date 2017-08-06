# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 15:56:35 by vnakonec          #+#    #+#              #
#    Updated: 2017/04/13 16:07:48 by vnakonec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

SRCS = my_filler.c\
	  save_input.c\
	  calculate.c\

OBJ = $(SRCS:.c=.o)

LIBFTDIR = ft_printf/

all: $(NAME)

$(NAME) : $(LIBFTDIR)libftprintf.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lftprintf

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libftprintf.a: ft_printf/Makefile
	make -C ft_printf/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR)libftprintf.a

re: fclean all
