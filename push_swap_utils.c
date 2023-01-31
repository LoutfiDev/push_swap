/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:59:11 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/30 13:36:10 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head, char *inst)
{
	int	temp;

	if (!head || !head->next)
		return ;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	if (inst)
		write(1, inst, ft_strlen(inst));
	return ;
}

void	push(t_stack **first, t_stack **second, char *inst)
{
	t_stack	*tmp;

	if (!second || !(*second))
		return ;
	tmp = ft_lstnew(*second);
	ft_lstadd_front(first, tmp);
	ft_lstdelone(second);
	write(1, inst, ft_strlen(inst));
	return ;
}

void	rotate(t_stack **head, char *inst)
{
	t_stack	*tmp;

	if (!head || !(*head))
		return ;
	tmp = ft_lstnew(*head);
	ft_lstdelone(head);
	ft_lstadd_back(head, tmp);
	if (inst)
		write(1, inst, ft_strlen(inst));
	return ;
}

void	rev_rotate(t_stack **head, char *inst)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!head || !(*head))
		return ;
	last = ft_lstnew(ft_lstlast(*head));
	ft_lstadd_front(head, last);
	tmp = last -> next;
	while (tmp->next)
	{
		last = last->next;
		tmp = tmp -> next;
	}
	last->next = NULL;
	free(tmp);
	if (inst)
		write(1, inst, ft_strlen(inst));
	return ;
}

void	double_inst(char *inst, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(inst, "ss\n", ft_strlen(inst)) == 0)
	{
		swap(*stack_a, NULL);
		swap(*stack_b, NULL);
		write(1, inst, ft_strlen(inst));
	}
	if (ft_strncmp(inst, "rr\n", ft_strlen(inst)) == 0)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
		write(1, inst, ft_strlen(inst));
	}
	if (ft_strncmp(inst, "rrr\n", ft_strlen(inst)) == 0)
	{
		rev_rotate(stack_a, NULL);
		rev_rotate(stack_b, NULL);
		write(1, inst, ft_strlen(inst));
	}
	return ;
}
