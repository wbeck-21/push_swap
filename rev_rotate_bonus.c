/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:22:40 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:49:38 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_rra_checker(t_stack **stack_a)
{
	t_stack	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = before_last_stack_elem(*stack_a);
		stack_add_front(stack_a, before_last->next);
		before_last->next = NULL;
	}
}

void	ft_rrb_checker(t_stack **stack_b)
{
	t_stack	*new_last_elem;
	t_stack	*first_elem;

	new_last_elem = NULL;
	first_elem = *stack_b;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while (first_elem->next != NULL)
	{
		new_last_elem = first_elem;
		first_elem = first_elem->next;
	}
	new_last_elem->next = NULL;
	first_elem->next = *stack_b;
	*stack_b = first_elem;
}

void	ft_rrr_checker(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*before_last;
	t_stack	*new_last_elem;
	t_stack	*first_elem;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = before_last_stack_elem(*stack_a);
		stack_add_front(stack_a, before_last->next);
		before_last->next = NULL;
	}
	new_last_elem = NULL;
	first_elem = *stack_b;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while (first_elem->next != NULL)
	{
		new_last_elem = first_elem;
		first_elem = first_elem->next;
	}
	new_last_elem->next = NULL;
	first_elem->next = *stack_b;
	*stack_b = first_elem;
}
