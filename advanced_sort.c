/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:07:54 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/21 13:30:51 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rotate_min(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	min_index;

	min = 0;
	min_index = get_min_index1(stack_b, &min);
	while ((*stack_b)->data != min)
	{
		if ((*stack_b)->next->data == min)
			swap(*stack_b, "sb\n");
		else if (min_index <= (ft_lstsize(*stack_b) / 2) + 1)
			rotate(stack_b, "rb\n");
		else if (min_index > (ft_lstsize(*stack_b) / 2) + 1)
			rev_rotate(stack_b, "rrb\n");
	}
	push(stack_a, stack_b, "pa\n");
	rotate(stack_a, "ra\n");
}

void	advanced_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	range;
	int	i;
	
	if (ft_lstsize(*stack_a) <= 100)
		range = 4;
	else
		range = 10;
	while (is_sorted(stack_a, stack_b) == 0)
	{
		i = ft_lstsize(*stack_a) / range;
		range--;
		while (i--)
			push(stack_b, stack_a, "pb\n");
		while (stack_b && *stack_b)
			push_rotate_min(stack_a, stack_b);
	}
	return ;
}
