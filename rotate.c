/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:23:01 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/06 19:32:59 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(int flag)
{
	if (flag == 1)
		write(1, "ra\n", 3);
	if (flag == 2)
		write(1, "rb\n", 3);
	if (flag == 3)
		write(1, "rr\n", 3);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	int		flag;

	flag = 1;
	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_a, tmp);
	}
	ft_print(flag);
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*tmp;
	int		flag;

	flag = 2;
	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_listadd_back(stack_b, tmp);
	}
	ft_print(flag);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	int	flag;

	flag = 3;
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_print(flag);
}
