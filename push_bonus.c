/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:34:20 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:49:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_pa_checker(t_stack **stack_a, t_stack **stack_b)
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
}

void	ft_pb_checker(t_stack **stack_a, t_stack **stack_b)
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
}
