/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:20:20 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 18:35:03 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack **stack_a)
{
	t_stack			*p;
	int				min;
	int				max;
	int				med;
	int				size;

	if (find_values(stack_a, &min, &max, &med) > 0)
		return ;
	p = *stack_a;
	med = 0;
	while (p->nbr != min)
	{
		med++;
		p = p->next;
	}
	size = ft_listsize(*stack_a);
	if (med <= size - med)
		while (med-- > 0)
			ft_ra(stack_a);
	else
		while (med++ < size)
			ft_rra(stack_a);
}
