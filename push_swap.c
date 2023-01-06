/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/05 16:23:38 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{	
	(void)av;
	if (ac == 1)
		exit(1);
	if (!check_arg())
		printf("Error\n");
	if (!check_is_int())
		printf("Error\n");
	if (!is_not_dup())
		printf("Error\n");
	return (0);
}

	// t_stack *head_a = NULL;
	// t_stack *second_a = NULL;
	// t_stack *third_a = NULL;
	
	// t_stack *head_b = NULL;
	// t_stack *second_b = NULL;
	// t_stack *third_b = NULL;
	
	// head_a = ft_lstnew(10);
	// second_a = ft_lstnew(20);
	// third_a = ft_lstnew(30);
	
	// head_b = ft_lstnew(40);
	// second_b = ft_lstnew(50);
	// third_b = ft_lstnew(60);
	
	// head_a->next = second_a;
	// second_a->next = third_a;
	// third_a->next = NULL;
	
	// head_b->next = second_b;
	// second_b->next = third_b;
	// third_b->next = NULL;
	
	// rev_rotate(&head_b);
	// ft_lstprint(head_b);
	
	// system("leaks push_swap");