/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_to_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:11:47 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 13:56:07 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_move_elem_b(t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_listsize(stack_b);
	i = 0;
	while (stack_b)
	{
		stack_b->count_rb = i;
		stack_b->count_rrb = size - i;
		i++;
		stack_b = stack_b->next;
	}
}

void	count_move_elem_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	int		size;
	int		i;
	int		last;

	size = ft_listsize(stack_a);
	temp = stack_a;
	while (stack_b)
	{
		stack_a = temp;
		i = 0;
		last = ft_listlast(stack_a)->nbr;
		while (stack_a)
		{
			if (last < stack_b->nbr && stack_a->nbr > stack_b->nbr)
			{
				stack_b->count_ra = i;
				stack_b->count_rra = size - i;
			}
			i++;
			last = stack_a->nbr;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

void	moving_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		move_type;
	t_stack	*profit_elem;

	count_move_elem_b(*stack_b);
	count_move_elem_a(*stack_a, *stack_b);
	profit_elem = find_profit_elem(*stack_b, &move_type);
	processor(stack_a, stack_b, profit_elem, &move_type);
}
