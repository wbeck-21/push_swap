/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:33:23 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 18:51:35 by wbeck            ###   ########.fr       */
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
			if (array[i] == array[j] || array[i] > 2147483647)
			{
				ft_putstr_fd("Error\nthere are duplicates\n", 1);
				return (NULL);
			}
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
	int	elem_0;
	int	elem_1;
	int	elem_2;
	int	size;

	size = ft_listsize(*stack_a);
	if (size == 3)
	{
		elem_0 = (*stack_a)->nbr;
		elem_1 = (*stack_a)->next->nbr;
		elem_2 = (*stack_a)->next->next->nbr;
		if (elem_0 > elem_2 && elem_0 > elem_1 && elem_1 > elem_2)
			ft_sa(stack_a);
		if (elem_1 > elem_2 && elem_1 > elem_0 && elem_2 > elem_0)
			ft_sa(stack_a);
		if (elem_2 > elem_0 && elem_2 > elem_1 && elem_0 > elem_1)
			ft_sa(stack_a);
	}
}
