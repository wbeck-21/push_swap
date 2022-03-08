/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:16:18 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 13:38:26 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static int	ft_check_maxint(char **argv)
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

int	main(int argc, char **argv)
{
	if (!ft_checkarg(argv))
	{
		ft_putstr_fd("Error\nsome arguments aren’t integers\n", 1);
		return (0);
	}
	if (!ft_check_maxint(argv))
	{
		ft_putstr_fd("Error\nsome arguments are bigger/smaller than an int\n", 1);
		return (0);
	}
	if (argc > 1)
		parsing(argc, argv);
	else if (argc == 1)
		ft_putstr_fd("There're not any args\n", 1);
	return (0);
}
