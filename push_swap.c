/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/11 17:58:28 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	str = ft_strjoin(av, ac);
	args = ft_split(str, &ac);
	is_valid_args(args, ac - 1);
	ac -= 1;
	while (ac >= 0)
		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(args[ac--])));
	ft_lstprint(stack_a);
	return (0);
}

	// system("leaks push_swap");
	// rev_rotate(&stack_a);
	// ft_lstprint(stack_a);