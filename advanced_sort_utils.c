/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:55:58 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/05 17:39:09 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	n;
	int	counter;

	chunk = ft_lstsize(*stack_a) / 10;
	n = 4;
	counter = 1;
	if (ft_lstsize(*stack_a) <= 100)
		n = 8;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->rank > chunk * n && chunk)
			rotate(stack_a, "ra\n");
		else
		{
			push(stack_b, stack_a, "pb\n");
			counter++;
		}
		if (counter == chunk * n)
			n++;
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
		if (lst_b->target_pos == INT_MAX)
			lst_b->target_pos = get_min_rank(stack_a);
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
