/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:17:22 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 20:22:48 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	processor2(t_stack **stack_a, t_stack **stack_b,
		t_stack *profit_elem, int *move_type)
{
	if (*move_type == 4)
	{
		while (profit_elem->count_rrb-- > 0 && profit_elem->count_rra--)
			ft_rrr(stack_a, stack_b);
		while (profit_elem->count_rra-- > 0)
			ft_rra(stack_a);
	}
	if (*move_type == 5)
	{
		while (profit_elem->count_rb-- > 0)
			ft_rb(stack_b);
		while (profit_elem->count_rra-- > 0)
			ft_rra(stack_a);
	}
	if (*move_type == 6)
	{
		while (profit_elem->count_rrb-- > 0)
			ft_rrb(stack_b);
		while (profit_elem->count_ra-- > 0)
			ft_ra(stack_a);
	}
}

void	processor(t_stack **stack_a, t_stack **stack_b,
		t_stack *profit_elem, int *move_type)
{
	if (*move_type == 1)
	{
		while (profit_elem->count_ra-- > 0 && profit_elem->count_rb--)
			ft_rr(stack_a, stack_b);
		while (profit_elem->count_rb-- > 0)
			ft_rb(stack_b);
	}
	if (*move_type == 2)
	{
		while (profit_elem->count_rb-- > 0 && profit_elem->count_ra--)
			ft_rr(stack_a, stack_b);
		while (profit_elem->count_ra-- > 0)
			ft_ra(stack_a);
	}
	if (*move_type == 3)
	{
		while (profit_elem->count_rra-- > 0 && profit_elem->count_rrb--)
			ft_rrr(stack_a, stack_b);
		while (profit_elem->count_rrb-- > 0)
			ft_rrb(stack_b);
	}
	else
		processor2(stack_a, stack_b, profit_elem, move_type);
	ft_pa(stack_a, stack_b);
}
