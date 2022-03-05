/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:25:31 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 20:25:40 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p_a;
	t_stack	*p_b;

	if (*stack_b)
	{
		p_a = *stack_a;
		p_b = *stack_b;
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = p_b;
		(*stack_a)->next = p_a;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	if (*stack_a)
	{
		b = *stack_b;
		a = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = a;
		(*stack_b)->next = b;
	}	
	write(1, "pb\n", 3);
}
