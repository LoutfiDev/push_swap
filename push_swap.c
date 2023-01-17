/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/17 12:22:58 by yloutfi          ###   ########.fr       */
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

int	main(int ac, char **av)
{	
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	*str;

	if (ac == 1)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	str = ft_argsjoin(av, ac);
	args = ft_split(str, &ac);
	is_valid_args(args, ac - 1);
	ac -= 1;
	while (ac >= 0)
		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(args[ac--])));
	simple_sort(&stack_a, &stack_b);
	return (0);
}

	// system("leaks push_swap");
	// -fsanitize=address -g
	// rev_rotate(&stack_a);
	// ft_lstprint(stack_a);