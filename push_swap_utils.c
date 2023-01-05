/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:59:11 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/05 13:32:38 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack  *head)
{
	int	temp;
	
	if (!head || !head->next)
		return;
	temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
	return ;
}

void	push(t_stack **first, t_stack **second)
{
	t_stack *tmp;
	
	if (!(*second))
		return ;
	tmp = ft_lstnew((*second)->data);
	ft_lstadd_front(first, tmp);
	ft_lstdelone(second);
	return ;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	tmp = ft_lstnew((*head)->data);
	ft_lstdelone(head);
	ft_lstadd_back(head, tmp);
	return ;
}

void	rev_rotate(t_stack **head)
{
	t_stack *last;
	t_stack *tmp;
	
	if (!head)
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