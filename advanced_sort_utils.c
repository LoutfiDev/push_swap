/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:55:58 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/01 22:28:44 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	get_min_index(stack_a, &min);
	get_max_index(stack_a, &max);
	while (ft_lstsize(*stack_a) > 2)
	{
		if ((*stack_a)->data == min || (*stack_a)->data == max)
			rotate(stack_a, "ra\n");
		else
			push(stack_b, stack_a, "pb\n");
	}
}

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_b = *stack_b;
	while (lst_b)
	{
		lst_b->target_pos = INT_MAX;
		lst_a = *stack_a;
		while (lst_a)
		{
			if (lst_b->rank < lst_a->rank && lst_a->rank < lst_b->target_pos)
				lst_b->target_pos = lst_a->rank;
			lst_a = lst_a->next;
		}
		lst_b = lst_b->next;
	}
	return ;
}

int	get_pos(t_stack **stack, int rank)
{
	t_stack	*lst;
	int		position;

	lst = *stack;
	position = 0;
	while (lst)
	{
		if (lst->rank == rank)
			break ;
		lst = lst->next;
		position++;
	}
	return (position);
}

void	set_cost_b(t_stack **stack)
{
	t_stack	*lst;
	int		mid;
	int		position;

	mid = ft_lstsize(*stack) / 2;
	lst = *stack;
	position = 0;
	while (lst)
	{
		position = get_pos(stack, lst->rank);
		if (position <= mid)
			lst->cost_stack_b = position;
		else
			lst->cost_stack_b = ft_lstsize(*stack) - position;
		lst = lst->next;
	}
	return ;
}

void	set_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lst;
	int		mid;
	int		pre_cost;
	int		position;

	lst = *stack_b;
	mid = ft_lstsize(*stack_a) / 2;
	pre_cost = 0;
	position = 0;
	while (lst)
	{	
		position = get_pos(stack_a, lst->target_pos);
		if (position <= mid)
			pre_cost = position;
		else
			pre_cost = ft_lstsize(*stack_a) - position;
		lst->cost_stack_a = pre_cost + lst->cost_stack_b + 1;
		lst = lst->next;
	}
	return ;
}
