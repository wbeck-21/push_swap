/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:09:37 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 18:36:28 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_ranks(t_stack *stack_a, int *array)
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
	return (0);
}

t_stack	*fill_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;
	int		min;
	int		med;
	int		max;

	stack_b = NULL;
	if (find_values(stack_a, &min, &max, &med) > 0)
		return (NULL);
	size = ft_listsize(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->nbr == max || (*stack_a)->nbr == med
			|| (*stack_a)->nbr == min)
			ft_ra(stack_a);
		else
		{
			ft_pb(stack_a, &stack_b);
			size--;
		}
	}
	return (stack_b);
}
