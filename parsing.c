/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:39:52 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 18:47:24 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = stack_a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr && flag)
			return (1);
		if (stack_a->nbr > stack_a->next->nbr)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (stack_a && stack_a->nbr > temp->nbr && flag)
		return (1);
	return (0);
}

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

void	parsing(int argc, char **argv)
{
	char	**matrix;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return ;
	matrix = create_matrix(stack_a, argc, argv);
	stack_a = fill_stack_a(matrix);
	if (is_sorted(stack_a))
	{
		sort_three(&stack_a);
		stack_b = fill_stack_b(&stack_a);
		if (stack_b == NULL)
		{
			free(stack_a);
			free_matrix(matrix);
			return ;
		}
		while (stack_b)
			moving_to_stack_a(&stack_a, &stack_b);
	}
	final_sort(&stack_a);
	free_matrix(matrix);
}
