/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:28:15 by yloutfi           #+#    #+#             */
/*   Updated: 2023/01/06 12:20:03 by yloutfi          ###   ########.fr       */
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

char	*ft_strjoin(char **args, int nbr)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!args || !(*args))
		return (0);
	len = 0;
	i = 0;
	while (i < nbr)
		len += ft_strlen(args[i++]);
	res = malloc((len + nbr + 1) * sizeof(char));
	if (res != NULL)
		return (0);
	i = 0;
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
