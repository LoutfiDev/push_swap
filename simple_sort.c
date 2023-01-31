/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:30:50 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/23 11:53:36 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (is_sorted(stack_a, stack_b) == 0)
	{
		if ((*stack_a)->data > ft_lstlast(*stack_a)->data)
			rotate(stack_a, "ra\n");
		else if ((*stack_a)->data > (*stack_a)->next->data)
			swap(*stack_a, "sa\n");
		else
			rev_rotate(stack_a, "rra\n");
	}
}
