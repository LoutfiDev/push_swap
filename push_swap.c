/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/05 17:49:58 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{	
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	*str;
	int		i;

	if (ac == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	str = ft_argsjoin(av, ac);
	args = ft_split(str, &ac);
	is_valid_args(args, ac - 1);
	i = ac - 1;
	while (i >= 0)
		ft_lstadd_front(&stack_a, ft_create(ft_atoi(args[i--])));
	if (ac <= 3)
		simple_sort(&stack_a, &stack_b);
	else
		advanced_sort(&stack_a, &stack_b);
	return (0);
}
