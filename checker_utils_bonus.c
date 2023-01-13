/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:24:22 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/13 12:07:18 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_message(int is_sorted)
{
	if (is_sorted)
	{
		write(1, "OK\n", 3);
		exit(1);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	return ;
}

void	init_instractions(char *instructions[11])
{
	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
}

void	is_inst_valid(char *inst)
{
	char	*instructions[11];
	int		i;
	int		find;

	i = 0;
	find = 0;
	init_instractions(instructions);
	while (i < 11)
	{
		if (ft_strncmp(inst, instructions[i], ft_strlen(inst)) == 0)
			find = 1;
		i++;
	}
	if (find == 0)
		ft_error();
	return ;
}

void	do_inst(char *inst, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(inst, "sa", ft_strlen(inst)) == 0)
		swap(stack_a);
	if (ft_strncmp(inst, "sb", ft_strlen(inst)) == 0)
		swap(stack_b);
	if (ft_strncmp(inst, "pa", ft_strlen(inst)) == 0)
		push(stack_b, stack_a);
	if (ft_strncmp(inst, "pb", ft_strlen(inst)) == 0)
		push(stack_a, stack_b);
	if (ft_strncmp(inst, "ra", ft_strlen(inst)) == 0)
		rotate(stack_a);
	if (ft_strncmp(inst, "rb", ft_strlen(inst)) == 0)
		rotate(stack_b);
	if (ft_strncmp(inst, "rr", ft_strlen(inst)) == 0)
		double_inst(inst, stack_a, stack_b);
	if (ft_strncmp(inst, "rra", ft_strlen(inst)) == 0)
		rev_rotate(stack_a);
	if (ft_strncmp(inst, "rrb", ft_strlen(inst)) == 0)
		rev_rotate(stack_b);
	if (ft_strncmp(inst, "rrr", ft_strlen(inst)) == 0)
		double_inst(inst, stack_a, stack_b);
	free (inst);
	return ;
}

void	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int			min;
	int			is_sorted;
	t_stack		*lst;

	lst = *stack_a;
	min = lst->data;
	is_sorted = 1;
	if (!(*stack_b))
	{
		while (lst->next)
		{
			if (min > lst->next->data)
			{
				is_sorted = 0;
				break ;
			}
			min = lst->next->data;
			lst = lst->next;
		}
	}
	checker_message(is_sorted);
	return ;
}
