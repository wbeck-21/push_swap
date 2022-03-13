/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:33:23 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/12 20:37:51 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	struct_to_arr(t_stack *elem, int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		array[i] = elem->nbr;
		elem = elem->next;
	}
}

int	check(int *array, int i, int j)
{
	if (array[i] == array[j])
	{
		if (i != j)
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	return (1);
}

int	*sort_arr(t_stack *elem, int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	struct_to_arr(elem, array, size);
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (!check(array, i, j))
				return (NULL);
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}

void	sort_three(t_stack **stack_a)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = ft_listsize(*stack_a);
	if (size == 3)
	{
		first = (*stack_a)->nbr;
		second = (*stack_a)->next->nbr;
		third = (*stack_a)->next->next->nbr;
		if (second > third && second > first && third > first)
			ft_sa(stack_a);
		if (third > first && third > second && first > second)
			ft_sa(stack_a);
		if (first > third && first > second && second > third)
			ft_sa(stack_a);
	}
}
