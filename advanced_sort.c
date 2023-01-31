/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:07:54 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/31 11:59:05 by yloutfi          ###   ########.fr       */
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

void	set_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *lst;
	int		position;

	lst = *stack_a;
	position = 0;
	while (lst)
	{
		lst->pos = position++;
		lst = lst->next;
	}
	lst = *stack_b;
	position = 0;
	while (lst)
	{
		lst->pos = position++;
		lst = lst->next;
	}
	return ;
}

void	set_cost_b(t_stack **stack)
{
	t_stack *lst;
	int		mid;

	mid = ft_lstsize(*stack) / 2;
	lst = *stack;
	while (lst)
	{
		if (lst->pos <= mid)
			lst->cost_stack_b = lst->pos;
		else
			lst->cost_stack_b = ft_lstsize(*stack) - lst->pos;
		lst = lst->next;
	}
	return ;
}

int	get_pos(t_stack **stack, int rank)
{
	t_stack	*lst;
	int		position;

	lst = *stack;
	position = lst->pos;
	while (lst)
	{
		if (lst->rank == rank)
			position = lst->pos;
		lst  = lst->next;
	}
	return (position);
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
	return;
}

t_stack		*find_cheapest(t_stack **stack)
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

void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;
	int		dest_pos;
	int		cheap_pos;
	
	cheap = find_cheapest(stack_b);
	// while ((*stack_b)->rank != cheap->rank || (*stack_a)->rank != cheap->target_pos)
	// {
	// 	cheap_pos = get_pos(stack_b, cheap->rank);
	// 	dest_pos = get_pos(stack_a, cheap->target_pos);
	// 	if (cheap_pos <= ft_lstsize(*stack_b) / 2
	// 		&& dest_pos <= ft_lstsize(*stack_a) / 2)
	// 			double_inst("rr", stack_a, stack_b);
	// 	else if (cheap_pos > ft_lstsize(*stack_b) / 2
	// 		&& dest_pos > ft_lstsize(*stack_a) / 2)
	// 			double_inst("rrr", stack_a, stack_b);
	// }
	while (*stack_b && (*stack_a)->rank != cheap->target_pos)
	{
		dest_pos = get_pos(stack_a, cheap->target_pos);
		if (dest_pos <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, "ra\n");
		else
			rev_rotate(stack_a, "rra\n");
	}
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
		set_pos(stack_a, stack_b);
		set_target_pos(stack_a, stack_b);
		set_cost_b(stack_b);
		set_cost_a(stack_a, stack_b);
		push_cheapest(stack_a, stack_b);
	}
	// while (is_sorted(stack_a, stack_b) == 0)
	// {
	// 	if (get_pos(stack_a, 1) <= ft_lstsize(*stack_a) / 2)
	// 		rotate(stack_a, "ra\n");
	// 	else
	// 		rev_rotate(stack_a, "rra\n");
	// }
	return ;
}
	// printf("data\tpos\trank\tt_pos\tcost_a\tcost_b\n");
	// while (*stack_a)
	// {
	// 	printf("%d\t%d\t%d\t%d\t%d\t%d\n", (*stack_a)->data, (*stack_a)->pos, (*stack_a)->rank, (*stack_a)->target_pos, (*stack_a)->cost_stack_a, (*stack_a)->cost_stack_b);
	// 	(*stack_a) = (*stack_a)->next;
	// }
	// printf("--------------------\n");
	// while (*stack_b)
	// {
	// 	printf("%d\t%d\t%d\t%d\t%d\t%d\n", (*stack_b)->data, (*stack_b)->pos, (*stack_b)->rank, (*stack_b)->target_pos, (*stack_b)->cost_stack_a, (*stack_b)->cost_stack_b);
	// 	(*stack_b) = (*stack_b)->next;
	// }
	// printf("--------------------\n");
// , (*stack_a)->rank, (*stack_a)->target_pos
