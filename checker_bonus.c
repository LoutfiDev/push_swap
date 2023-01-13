/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:42:25 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/13 21:30:28 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//just for test
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
	char	*list;

	if (ac == 1)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	list = ft_argsjoin(av, ac);
	args = ft_split(list, &ac);
	is_valid_args(args, ac - 1);
	ac -= 1;
	while (ac >= 0)
		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(args[ac--])));
	ft_lstprint(stack_a);// for test
	while (1)
	{
		list = get_next_line(0);
		if (!list)
			break ;
		is_inst_valid(list);
		do_inst(list, &stack_a, &stack_b);
	}
	is_sorted(&stack_a, &stack_b);
	return (0);
}
