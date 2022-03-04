/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:18:07 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/04 14:57:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(t_stack *elem, int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		array[i] = elem->nbr;
		elem = elem->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}

void	sort_triple(t_stack **stack_a)
{
	int	elem_0;
	int	elem_1;
	int	elem_2;
	int	size;

	size = ft_listsize(*stack_a);
	if (size == 3)
	{
		elem_0 = (*stack_a)->nbr;
		elem_1 = (*stack_a)->next->nbr;
		elem_2 = (*stack_a)->next->next->nbr;
		if (elem_0 > elem_2 && elem_0 > elem_1 && elem_1 > elem_2)
			ft_sa(stack_a);
		if (elem_1 > elem_2 && elem_1 > elem_0 && elem_2 > elem_0)
			ft_sa(stack_a);
		if (elem_2 > elem_0 && elem_2 > elem_1 && elem_0 > elem_1)
			ft_sa(stack_a);
	}
}

t_stack	*fill_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;
	int		min;
	int		med;
	int		max;

	stack_b = NULL;
	size = find_values(stack_a, &min, &max, &med);
	size = ft_listsize(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->nbr == max || (*stack_a)->nbr == med
			|| (*stack_a)->nbr == min)
			ft_ra(stack_a);
		else
		{
			ft_pb(stack_a, &stack_b);
			size--;
		}
	}
	sort_triple(stack_a);
	return (stack_b);
}

void	ft_listadd_back(t_stack **lst, t_stack *new_list)
{
	t_stack	*p;

	if (*lst == NULL)
		*lst = new_list;
	else
	{
		p = ft_listlast(*lst);
		p->next = new_list;
	}
}

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
		ft_listadd_back(&stack_a, init_elem(ft_atoi(elem[i])));
		i++;
	}
	return (stack_a);
}
