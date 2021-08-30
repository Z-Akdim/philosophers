# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 07:41:14 by zakdim            #+#    #+#              #
#    Updated: 2021/07/13 11:26:43 by zakdim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
SRCS = main.c utils.c exit.c message.c init.c forks.c eat.c
NAME = philo
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@
all: *.h
	@$(MAKE) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all