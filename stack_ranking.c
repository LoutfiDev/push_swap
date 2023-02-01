/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ranking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:38:34 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/01 22:45:13 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rank(t_stack **stack, int data, int rank)
{
	t_stack	*lst;

	lst = *stack;
	while (lst)
	{
		if (lst->data == data)
		{
			lst->rank = rank;
			break ;
		}
		lst = lst->next;
	}
	return ;
}

int	get_next_max(t_stack **stack, int max)
{
	int		next_max;
	t_stack	*lst;

	lst = *stack;
	next_max = lst->data;
	while (lst)
	{
		if (!(lst->data >= max))
		{	
			if (next_max < lst->data)
				next_max = lst->data;
			lst = lst->next;
		}
		else if (next_max >= max)
		{
			lst = lst->next;
			next_max = lst->data;
		}
		else
			lst = lst->next;
	}
	return (next_max);
}

void	stack_ranking(t_stack **stack)
{
	int		i;
	int		max;
	int		next_max;

	i = get_max_index(stack, &max);
	i = ft_lstsize(*stack);
	set_rank(stack, max, i);
	while (--i)
	{
		next_max = get_next_max(stack, max);
		set_rank(stack, next_max, i);
		max = next_max;
	}
	return ;
}
