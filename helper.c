/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:46:21 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/03 12:14:02 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->rank = 0;
	new_node->target_pos = 0;
	new_node->cost_stack_a = 0;
	new_node->cost_stack_b = 0;
	new_node->next = NULL;
	return (new_node);
}

int	get_min_rank(t_stack **stack)
{
	int		rank;
	t_stack	*lst;
	
	lst = *stack;
	rank = lst->rank;
	while (lst->next)
	{
		if (rank > lst->next->rank)
			rank = lst->next->rank;
		lst = lst->next;
	}
	return (rank);
}
