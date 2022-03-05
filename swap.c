/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:24:29 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/05 18:25:43 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*p;
	t_stack	*next;

	p = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		next = (*stack_a)->next;
		(*stack_a)->next = next->next;
		next->next = p;
		(*stack_a) = next;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*next;

	p = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		next = (*stack_b)->next;
		(*stack_b)->next = next->next;
		next->next = p;
		(*stack_b) = next;
		write(1, "sa\n", 3);
	}
	else
		return ;
}
