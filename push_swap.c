/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/30 12:29:54 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// just for test 
void	ft_lstprint(t_stack *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
	printf("--------------------\n");
	return ;
}
//

t_stack	*ft_create(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	main(int ac, char **av)
{	
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	*str;
	int		i;

	if (ac == 1)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	str = ft_argsjoin(av, ac);
	args = ft_split(str, &ac);
	is_valid_args(args, ac - 1);
	i = ac - 1;
	while (i >= 0)
		ft_lstadd_front(&stack_a, ft_create(ft_atoi(args[i--])));
	// if (ac <= 3)
	// 	simple_sort(&stack_a, &stack_b);
	// else if (ac <= 5)
	// 	middle_sort(&stack_a, &stack_b);
	// else
		advanced_sort(&stack_a, &stack_b);
	return (0);
}
	// system("leaks push_swap");
	// ft_lstprint(stack_a);
	// -fsanitize=address -g
	// rev_rotate(&stack_a);