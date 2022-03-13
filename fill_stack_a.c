/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:18:07 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/09 16:36:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_elem(int elem)
{
	t_stack	*elem_stack;

	elem_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!elem_stack)
		return (NULL);
	elem_stack->nbr = elem;
	elem_stack->count_ra = -1;
	elem_stack->count_rra = -1;
	elem_stack->count_rb = -1;
	elem_stack->count_rrb = -1;
	elem_stack->index = -1;
	elem_stack->next = NULL;
	return (elem_stack);
}

t_stack	*fill_stack_a(char **elem)
{
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 0;
	while (elem[i])
	{
		if (ft_atoi(elem[i]) > 2147483647)
			return (NULL);
		ft_listadd_back(&stack_a, init_elem(ft_atoi(elem[i])));
		i++;
	}
	return (stack_a);
}
