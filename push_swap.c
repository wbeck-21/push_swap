/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:16:18 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/13 13:52:44 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int argc, char **argv)
{
	if (!ft_checkarg(argv) || !ft_check_maxint(argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (argc > 1)
		parsing(argc, argv);
	return (0);
}
