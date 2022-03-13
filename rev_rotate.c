/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:21:47 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/12 17:09:47 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = before_last_stack_elem(*stack_a);
		stack_add_front(stack_a, before_last->next);
		before_last->next = NULL;
	}
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*before_last;

	if (*stack_b && (*stack_b)->next)
	{
		before_last = before_last_stack_elem(*stack_b);
		stack_add_front(stack_b, before_last->next);
		before_last->next = NULL;
	}
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = before_last_stack_elem(*stack_a);
		stack_add_front(stack_a, before_last->next);
		before_last->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		before_last = before_last_stack_elem(*stack_b);
		stack_add_front(stack_b, before_last->next);
		before_last->next = NULL;
	}
	write(1, "rrr\n", 4);
}
