#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:46:56 by dpylypen          #+#    #+#              #
#    Updated: 2016/12/14 14:49:59 by dpylypen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/


SRCS = main.c\
	read_line.c\
	check_str.c\
	get_map.c\
	get_size.c\
	get_tetrimino.c\
	get_tetriminos.c\
	out_solution.c\
	set_tetrimino.c\
	solve_tetriminos.c\
	resize_map.c

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft

%.o: srcs/filereader/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/tetriminos/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libft.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR) 

re:  all
	make re -C $(LIBFTDIR)

norm:
	norminette srcs/*.c srcs/filereader/*.c srcs/tetriminos/*c includes/*.h
	make norm -C $(LIBFTDIR)

rmsh:
	find . -name ".DS*" -o -name "._.*" -o -name "#*" -o -name "*~" -o -name "*.out" > rmsh
	xargs rm < rmsh
	rm rmsh