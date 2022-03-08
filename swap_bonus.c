/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:36:15 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:49:59 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_sa_checker(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*next;

	a = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		next = (*stack_a)->next;
		(*stack_a)->next = next->next;
		next->next = a;
		(*stack_a) = next;
	}
	else
		return ;
}

void	ft_sb_checker(t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*next;

	b = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		next = (*stack_b)->next;
		(*stack_b)->next = next->next;
		next->next = b;
		(*stack_b) = next;
	}
	else
		return ;
}

void	ft_ss_checker(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*next_a;
	t_stack	*b;
	t_stack	*next_b;

	a = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		next_a = (*stack_a)->next;
		(*stack_a)->next = next_a->next;
		next_a->next = a;
		(*stack_a) = next_a;
	}
	b = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		next_b = (*stack_b)->next;
		(*stack_b)->next = next_b->next;
		next_b->next = b;
		(*stack_b) = next_b;
	}
	else
		return ;
}
