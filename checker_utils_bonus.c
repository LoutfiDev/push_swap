/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:24:22 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/17 11:38:30 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_message(int is_sorted)
{
	if (is_sorted)
	{
		write(1, "OK\n", 3);
		exit(0);
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
	instructions[0] = "sa\n";
	instructions[1] = "sb\n";
	instructions[2] = "ss\n";
	instructions[3] = "pa\n";
	instructions[4] = "pb\n";
	instructions[5] = "ra\n";
	instructions[6] = "rb\n";
	instructions[7] = "rr\n";
	instructions[8] = "rra\n";
	instructions[9] = "rrb\n";
	instructions[10] = "rrr\n";
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
	if (ft_strncmp(inst, "sa\n", ft_strlen(inst)) == 0)
		swap(*stack_a);
	if (ft_strncmp(inst, "sb\n", ft_strlen(inst)) == 0)
		swap(*stack_b);
	if (ft_strncmp(inst, "pa\n", ft_strlen(inst)) == 0)
		push(stack_a, stack_b);
	if (ft_strncmp(inst, "pb\n", ft_strlen(inst)) == 0)
		push(stack_b, stack_a);
	if (ft_strncmp(inst, "ra\n", ft_strlen(inst)) == 0)
		rotate(stack_a);
	if (ft_strncmp(inst, "rb\n", ft_strlen(inst)) == 0)
		rotate(stack_b);
	if (ft_strncmp(inst, "rr\n", ft_strlen(inst)) == 0)
		double_inst(inst, stack_a, stack_b);
	if (ft_strncmp(inst, "rra\n", ft_strlen(inst)) == 0)
		rev_rotate(stack_a);
	if (ft_strncmp(inst, "rrb\n", ft_strlen(inst)) == 0)
		rev_rotate(stack_b);
	if (ft_strncmp(inst, "rrr\n", ft_strlen(inst)) == 0)
		double_inst(inst, stack_a, stack_b);
	free (inst);
	return ;
}
