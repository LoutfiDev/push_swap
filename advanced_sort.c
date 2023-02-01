/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:07:54 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/01 22:28:17 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*cheap;

	lst = *stack;
	cheap = lst;
	while (lst->next)
	{
		if (cheap->cost_stack_a > lst->next->cost_stack_a)
			cheap = lst->next;
		lst = lst->next;
	}
	return (cheap);
}

void	_together(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;
	int		dest_pos;
	int		cheap_pos;
	int		exit;

	cheap = find_cheapest(stack_b);
	exit = 0;
	while ((*stack_b)->rank != cheap->rank
		&& (*stack_a)->rank != cheap->target_pos)
	{
		cheap_pos = get_pos(stack_b, cheap->rank);
		dest_pos = get_pos(stack_a, cheap->target_pos);
		if (cheap_pos <= ft_lstsize(*stack_b) / 2)
		{
			if (dest_pos <= ft_lstsize(*stack_a) / 2)
				double_inst("rr\n", stack_a, stack_b, &exit);
		}
		else
			if (dest_pos > ft_lstsize(*stack_a) / 2)
				double_inst("rrr\n", stack_a, stack_b, &exit);
		if (exit == 0)
			break ;
	}
	return ;
}

void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;
	int		dest_pos;
	int		cheap_pos;

	_together(stack_a, stack_b);
	cheap = find_cheapest(stack_b);
	while ((*stack_a)->rank != cheap->target_pos)
	{
		dest_pos = get_pos(stack_a, cheap->target_pos);
		if (dest_pos <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, "ra\n");
		else
			rev_rotate(stack_a, "rra\n");
	}
	cheap = find_cheapest(stack_b);
	while ((*stack_b)->rank != cheap->rank)
	{
		cheap_pos = get_pos(stack_b, cheap->rank);
		if (cheap_pos <= ft_lstsize(*stack_b) / 2)
			rotate(stack_b, "rb\n");
		else
			rev_rotate(stack_b, "rrb\n");
	}
	push(stack_a, stack_b, "pa\n");
	return ;
}

void	advanced_sort(t_stack **stack_a, t_stack **stack_b)
{	
	stack_ranking(stack_a);
	push_to_b(stack_a, stack_b);
	simple_sort(stack_a, NULL);
	while (*stack_b)
	{
		set_target_pos(stack_a, stack_b);
		set_cost_b(stack_b);
		set_cost_a(stack_a, stack_b);
		push_cheapest(stack_a, stack_b);
	}
	while (is_sorted(stack_a, stack_b) == 0)
	{
		if (get_pos(stack_a, 1) <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, "ra\n");
		else
			rev_rotate(stack_a, "rra\n");
	}
	return ;
}
