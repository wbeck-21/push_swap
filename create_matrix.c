/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:05:46 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/09 16:06:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**console_reader(int argc, char **argv)
{
	char	*str;
	char	**res;
	int		i;

	str = ft_calloc(1, 1);
	if (!str)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

char	**create_matrix(t_stack *stack_a, int argc, char **argv)
{
	char	**matrix;

	matrix = console_reader(argc, argv);
	if (matrix == NULL)
	{
		free(stack_a);
		return (NULL);
	}
	return (matrix);
}
