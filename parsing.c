/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:39:52 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 22:22:09 by wbeck            ###   ########.fr       */
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

	i = 1;
	str = ft_calloc(1, 1);
	if (!str)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			write(1, "Error\n", 6);
			free(str);
			return (NULL);
		}
		i++;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

void	insert_ranks(t_stack *stack_a, int *array)
{
	int	i;

	while (stack_a)
	{
		i = 0;
		while (array[i] != stack_a->nbr)
			i++;
		stack_a->index = i;
		stack_a = stack_a->next;
	}
}

int	find_values(t_stack **stack_a, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = ft_listsize(*stack_a);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	array = sort_arr(*stack_a, array, size);
	if (!array)
	{
		free(array);
		return (1);
	}
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	insert_ranks(*stack_a, array);
	free(array);
	// array = NULL;
	return (0);
}

void	parsing(int argc, char **argv)
{
	char	**matrix;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return ;
	matrix = console_reader(argc, argv);
	if (matrix == NULL)
	{
		free(stack_a);
		return ;
	}
	stack_a = fill_stack_a(matrix);
	if (is_sorted(stack_a))
	{
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
