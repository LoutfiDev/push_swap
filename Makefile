# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 08:43:01 by yloutfi           #+#    #+#              #
#    Updated: 2023/01/03 08:47:27 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJS = 

BONUS_SRCS = 				

BONUS_OBJS = 			
	
NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

bonus : $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS) -o checker
	
$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) -o push_swap

clean :
	-rm -f $(OBJS) $(BONUS_OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all