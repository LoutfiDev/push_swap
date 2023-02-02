/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/02 11:21:02 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_args(char **args, int nbr)
{
	int	i;

	if (!args || !(*args))
		return (0);
	while (nbr >= 0)
	{
		i = 0;
		while (args[nbr][i])
		{
			if ((args[nbr][i] == '-' || args[nbr][i] == '+') && !i)
				i++;
			if (args[nbr][i] < '0' || args[nbr][i] > '9')
				return (0);
			i++;
		}
		nbr--;
	}
	return (1);
}

int	check_is_int(char **args, int nbr)
{
	long long	nb;

	while (nbr >= 0)
	{
		nb = ft_atoi(args[nbr]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		nbr--;
	}
	return (1);
}

int	is_not_dup(char **args, int nbr)
{
	int	i;

	while (nbr >= 0)
	{
		i = nbr - 1;
		while (i >= 0)
		{
			if (ft_atoi(args[nbr]) == ft_atoi(args[i]))
				return (0);
			i--;
		}
		nbr--;
	}
	return (1);
}

void	is_valid_args(char **args, int ac)
{
	if (!check_args(args, ac))
		ft_error();
	if (!check_is_int(args, ac))
		ft_error();
	if (!is_not_dup(args, ac))
		ft_error();
	return ;
}
