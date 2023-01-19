/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:30:50 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/19 16:17:40 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack **stack_a)
{
	int		index;
	int		i;
	int		min;
	t_stack	*lst;

	lst = *stack_a;
	min = lst->data;
	index = 1;
	i = 1;
	while (lst->next)
	{
		i++;
		if (min > lst->next->data)
		{
			index = i;
			min = lst->next->data;
		}
		lst = lst->next;
	}
	return (index);
}

int	get_max_index(t_stack **stack_a)
{
	int		index;
	int		i;
	int		max;
	t_stack	*lst;

	lst = *stack_a;
	max = lst->data;
	index = 1;
	i = 1;
	while (lst->next)
	{
		i++;
		if (max < lst->next->data)
		{
			index = i;
			max = lst->next->data;
		}	
		lst = lst->next;
	}
	return (index);
}

void	move_min(t_stack **stack_a, int index)
{
	if (index == 2)
		swap(*stack_a, "sa\n");
	if (index == 3)
		rev_rotate(stack_a, "rra\n");
	return ;
}

void	move_max(t_stack **stack_a, int index)
{
	if (index == 1)
		rotate(stack_a, "ra\n");
	if (index == 2)
		rev_rotate(stack_a, "rra\n");
	return ;
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = 0;
	while (is_sorted(stack_a, stack_b) == 0)
	{
		index = get_min_index(stack_a);
		move_min(stack_a, index);
		if (is_sorted(stack_a, stack_b) == 1)
			break ;
		index = get_max_index(stack_a);
		move_max(stack_a, index);
	}
	return ;
}
