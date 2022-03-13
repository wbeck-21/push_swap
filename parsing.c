/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:39:52 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/12 20:08:52 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = stack_a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr && flag)
			return (1);
		if (stack_a->nbr > stack_a->next->nbr)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (stack_a && stack_a->nbr > temp->nbr && flag)
		return (1);
	return (0);
}

void	sort_stack_a(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	sort_three(stack_a);
	if (is_sorted(*stack_a))
	{
		stack_b = fill_stack_b(stack_a);
		if (!stack_b)
			return ;
		while (stack_b)
			moving_to_stack_a(stack_a, &stack_b);
	}
	final_sort(stack_a);
	free(stack_b);
}

void	parsing(int argc, char **argv)
{
	char	**matrix;
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return ;
	matrix = create_matrix(stack_a, argc, argv);
	stack_a = fill_stack_a(matrix);
	sort_stack_a(&stack_a);
	free_matrix(matrix);
}
