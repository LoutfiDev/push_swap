/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/10 12:13:34 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **args, int nbr)
{
	int	i;

	while (--nbr)
	{
		i = 0;
		while (args[nbr][i])
		{
			if (args[nbr][i] < '0' || args[nbr][i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_is_int(char **args, int nbr)
{
	long long	nb;

	while (--nbr)
	{
		nb = ft_atoi(args[nbr]);
		if (nb < -INT_MIN || nb > INT_MAX)
			return (0);
	}
	return (1);
}

int	is_not_dup(char **args, int nbr)
{
	int	i;

	while (--nbr)
	{
		i = nbr;
		while (--i)
			if (ft_atoi(args[nbr]) == ft_atoi(args[i]))
				return (0);
	}
	return (1);
}
