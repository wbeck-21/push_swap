/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_to_stack_a2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:14:22 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 20:18:43 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_count_moves2(t_stack *stack_b, int *move_type, int profit_total_moves)
{
	if (profit_total_moves > stack_b->count_rra + stack_b->count_rb)
	{
		profit_total_moves = stack_b->count_rra + stack_b->count_rb;
		*move_type = 5;
	}
	if (profit_total_moves > stack_b->count_ra + stack_b->count_rrb)
	{
		profit_total_moves = stack_b->count_ra + stack_b->count_rrb;
		*move_type = 6;
	}
	return (profit_total_moves);
}

int	find_count_moves(t_stack *stack_b, int *move_type)
{
	int	profit_total_moves;
	int	count_rotates;

	*move_type = 1;
	profit_total_moves = stack_b->count_rb;
	count_rotates = stack_b->count_rra;
	if (stack_b->count_ra >= stack_b->count_rb)
	{
		profit_total_moves = stack_b->count_ra;
		*move_type = 2;
	}
	if (stack_b->count_rrb > count_rotates)
		count_rotates = stack_b->count_rrb;
	if (profit_total_moves > count_rotates)
	{
		profit_total_moves = count_rotates;
		if (stack_b->count_rrb >= stack_b->count_rra)
			*move_type = 3;
		else
			*move_type = 4;
	}
	else
		find_count_moves2(stack_b, move_type, profit_total_moves);
	return (profit_total_moves);
}

t_stack	*find_profit_elem(t_stack *stack_b, int *move_type)
{
	t_stack	*profit_elem;
	int		profit_total_moves;
	int		profit_comb_moves;
	int		profit_index;

	profit_index = stack_b->index;
	profit_total_moves = find_count_moves(stack_b, move_type);
	profit_comb_moves = *move_type;
	profit_elem = stack_b;
	while (stack_b)
	{
		if (find_count_moves(stack_b, move_type) < profit_total_moves
			|| (find_count_moves(stack_b, move_type) == profit_total_moves
				&& stack_b->index >= profit_index))
		{
			profit_total_moves = find_count_moves(stack_b, move_type);
			profit_comb_moves = *move_type;
			profit_index = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	*move_type = profit_comb_moves;
	while (profit_elem->index != profit_index)
		profit_elem = profit_elem->next;
	return (profit_elem);
}
