/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:51 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/30 12:31:45 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//BUFFER_SIZE used to read buffer from stdin
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//for test only
# include <stdio.h>

typedef struct s_stack
{
	int				data;
    int            	pos;
    int            	target_pos;
    int            	rank;
    int            	cost_stack_a;
    int            	cost_stack_b;
	struct s_stack	*next;
}	t_stack;


//sorting_functions
void		swap(t_stack *head, char *inst);
void		push(t_stack **first, t_stack **second, char *inst);
void		rotate(t_stack **head, char *inst);
void		rev_rotate(t_stack **head, char *inst);
void		double_inst(char *inst, t_stack **stack_a, t_stack **stack_b);

//Linked_list_functions
void		ft_lstprint(t_stack *lst);
t_stack		*ft_lstnew(t_stack *node);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack **lst);
int			ft_lstsize(t_stack *lst);

//global_functions
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		**ft_split(char *str, int *ac);
char		*ft_argsjoin(char **args, int nbr);
long long	ft_atoi(char *str);
int			is_sorted(t_stack **stack_a, t_stack **stack_b);
int			get_min_index(t_stack **stack_a, int *min);
int			get_max_index(t_stack **stack_a, int *max);
void		stack_ranking(t_stack **stack);

//get_next_line function
char		*get_next_line(int fd);
int			ft_memchr(char *str, int c, int n);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *str, int start, int len);

//parsing_functions
void		is_valid_args(char **args, int nbr);
void		ft_error(void);

//checker_function
void		is_inst_valid(char *list);
void		do_inst(char *list, t_stack **stack_a, t_stack **stack_b);
void		checker_message(int is_sorted);

//sorting_versions
void		simple_sort(t_stack **stack_a, t_stack **stack_b);
void		middle_sort(t_stack **stack_a, t_stack **stack_b);
void		advanced_sort(t_stack **stack_a, t_stack **stack_b);

#endif
