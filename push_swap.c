/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:16:18 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:55:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

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


// long long int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				minus;
// 	long long int	res;

// 	i = 0;
// 	minus = 1;
// 	res = 0;
// 	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
// 		|| str[i] == '\n' || str[i] == '\t')
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			minus *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * minus);
// }
