# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 09:58:28 by ahmcherk          #+#    #+#              #
#    Updated: 2019/11/15 12:49:44 by ahmcherk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c

OBJS =	arg.o flag.o lst.o sort.o\
		tools.o tools2.o tools3.o tools4.o\
		tools5.o

CFLAGS = -Wall -Werror -Wextra

CC = gcc 

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(SRC) ./libft/libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) main.o
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all
		
