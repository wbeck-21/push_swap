/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:23:01 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 14:59:26 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_a, tmp);
	}
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_b, tmp);
	}
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*stack_a && (*stack_a)->next)
	{
		temp_a = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_a->next = NULL;
		ft_listadd_back(stack_a, temp_a);
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_b = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_b->next = NULL;
		ft_listadd_back(stack_b, temp_b);
	}
	write(1, "rr\n", 3);
}
