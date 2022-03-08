/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:52:25 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:52:39 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_maxint(char **argv)
{
	long long int	nbr;
	int				i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkarg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 33 && argv[i][j] <= 42) || argv[i][j] == 44
				|| (argv[i][j] >= 46 && argv[i][j] < '0') || argv[i][j] > '9')
				return (0);
			if (argv[i][j] == 43 || argv[i][j] == 45)
			{
				j++;
				if ((argv[i][j] < '0' || argv[i][j] > '9'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
