# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 08:43:01 by yloutfi           #+#    #+#              #
#    Updated: 2023/01/05 15:47:40 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_utils.c stack_utils.c

OBJS = push_swap.o push_swap_utils.o stack_utils.o

BONUS_SRCS = 				

BONUS_OBJS =		
	
NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

bonus : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) -o checker
	ar rc $(NAME) $(BONUS_OBJS)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o push_swap
	ar rc $(NAME) $(OBJS)

clean :
	-rm -f $(OBJS) $(BONUS_OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all