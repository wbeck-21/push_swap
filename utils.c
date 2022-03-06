/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:25:55 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/06 19:15:49 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}

int	ft_listsize(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	else
		return (1 + ft_listsize(lst->next));
}

t_stack	*before_last_stack_elem(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	if (stack->next->next == NULL)
		return (stack);
	else
		return (before_last_stack_elem(stack->next));
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	free_matrix(char **res)
{
	int	i;

	i = 0;
	while (i > 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}
