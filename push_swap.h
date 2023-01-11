/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:51 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/11 17:42:15 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
//for test only
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

//sorting_functions
void		swap(t_stack *head);
void		push(t_stack **first, t_stack **second);
void		rotate(t_stack **head);
void		rev_rotate(t_stack **head);

//Linked_list_functions
void		ft_lstprint(t_stack *lst);
t_stack		*ft_lstnew(int data);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack **lst);

//Libft_functions
char		**ft_split(char *str, int *ac);
char		*ft_strjoin(char **args, int nbr);
long long	ft_atoi(char *str);

//parsing_functions
void		is_valid_args(char **args, int nbr);
void		ft_error(void);

#endif
