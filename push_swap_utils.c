/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:59:11 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/14 09:53:43 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head)
{
	int	temp;

	if (!head || !head->next)
		return ;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	return ;
}

void	push(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	if (!second || !(*second))
		return ;
	tmp = ft_lstnew((*second)->data);
	ft_lstadd_front(first, tmp);
	ft_lstdelone(second);
	return ;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head))
		return ;
	tmp = ft_lstnew((*head)->data);
	ft_lstdelone(head);
	ft_lstadd_back(head, tmp);
	return ;
}

void	rev_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!head || !(*head))
		return ;
	last = ft_lstnew(ft_lstlast(*head)->data);
	ft_lstadd_front(head, last);
	tmp = last -> next;
	while (tmp->next)
	{
		last = last->next;
		tmp = tmp -> next;
	}
	last->next = NULL;
	free(tmp);
	return ;
}

void	double_inst(char *inst, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(inst, "rr\n", ft_strlen(inst)) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (ft_strncmp(inst, "rrr\n", ft_strlen(inst)) == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
	return ;
}
