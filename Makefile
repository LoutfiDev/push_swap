# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 08:43:01 by yloutfi           #+#    #+#              #
#    Updated: 2023/02/02 10:36:05 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_utils.c stack_utils.c 	\
	parsing_functions.c ft_split.c libft_functions.c\
	simple_sort.c middle_sort.c advanced_sort.c		\
	stack_ranking.c advanced_sort_utils.c helper.c
OBJS = push_swap.o push_swap_utils.o stack_utils.o 	\
	parsing_functions.o ft_split.o libft_functions.o\
	simple_sort.o middle_sort.o advanced_sort.o		\
	stack_ranking.o advanced_sort_utils.o helper.o

BONUS_SRCS = checker_bonus.c checker_utils_bonus.c 	\
	get_next_line.c get_next_line_utils.c			\
	push_swap_utils.c stack_utils.c ft_split.c		\
	parsing_functions.c libft_functions.c helper.c

BONUS_OBJS = checker_bonus.o checker_utils_bonus.o 	\
	get_next_line.o get_next_line_utils.o			\
	push_swap_utils.o stack_utils.o ft_split.o 		\
	parsing_functions.o libft_functions.o helper.o
	
NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror 
CC = cc

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean :
	-rm -f $(OBJS) $(BONUS_OBJS)
		
fclean : clean
	-rm -f $(NAME)
	-rm -f $(NAME_BONUS)

re : fclean	all

.PHONY: all bonus clean fclean re