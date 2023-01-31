/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:22 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/23 11:53:46 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int	get_max_index(t_stack **stack_a, int *max)
{
	int		index;
	int		i;
	t_stack	*lst;

	lst = *stack_a;
	*max = lst->data;
	index = 1;
	i = 1;
	while (lst->next)
	{
		i++;
		if (*max < lst->next->data)
		{
			index = i;
			*max = lst->next->data;
		}
		lst = lst->next;
	}
	return (index);
}

int	get_min_index(t_stack **stack_a, int *min)
{
	int		index;
	int		i;
	t_stack	*lst;

	lst = *stack_a;
	*min = lst->data;
	index = 1;
	i = 1;
	while (lst->next)
	{
		i++;
		if (*min > lst->next->data)
		{
			index = i;
			*min = lst->next->data;
		}
		lst = lst->next;
	}
	return (index);
}

void	middle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	min_index;

	min = 0;
	while (is_sorted(stack_a, stack_b) == 0)
	{
		while (ft_lstsize(*stack_a) > 3)
		{
			min_index = get_min_index(stack_a, &min);
			while ((*stack_a)->data != min)
			{
				if ((*stack_a)->next->data == min)
					swap(*stack_a, "sa\n");
				else if (min_index <= (ft_lstsize(*stack_a) / 2) + 1)
					rotate(stack_a, "ra\n");
				else if (min_index > (ft_lstsize(*stack_a) / 2) + 1)
					rev_rotate(stack_a, "rra\n");
			}
			push(stack_b, stack_a, "pb\n");
		}
		simple_sort(stack_a, NULL);
		while (stack_b && (*stack_b))
			push(stack_a, stack_b, "pa\n");
	}
	return ;
}
