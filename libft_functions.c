/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:52:30 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/02 10:17:11 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{	
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

char	*ft_argsjoin(char **args, int nbr)
{
	int		i;
	int		j;
	char	*res;

	if (!args || !*args[1])
		return (0);
	i = 1;
	j = 0;
	while (i < nbr)
		j += ft_strlen(args[i++]);
	res = malloc((j + nbr) * sizeof(char));
	if (res == NULL)
		return (0);
	i = 1;
	j = 0;
	while (i < nbr)
	{
		while ((*args[i]))
			res[j++] = (*args[i]++);
		if (i < nbr - 1)
			res[j++] = ' ';
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int			min;
	int			is_sorted;
	t_stack		*lst;

	lst = *stack_a;
	if (!lst)
		return (0);
	min = lst->data;
	is_sorted = 0;
	if (!stack_b || !(*stack_b))
	{
		is_sorted = 1;
		while (lst->next)
		{
			if (min > lst->next->data)
				return (0);
			min = lst->next->data;
			lst = lst->next;
		}
	}
	return (is_sorted);
}
