/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:29 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:49:32 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_ra_checker(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_a, tmp);
	}
}

void	ft_rb_checker(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_b, tmp);
	}
}

void	ft_rr_checker(t_stack **stack_a, t_stack **stack_b)
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
}
