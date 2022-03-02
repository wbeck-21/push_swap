# include "push_swap.h"

t_stack	*ft_listlast(t_stack *list)
{
	if (list)
		while (list->next)
			list = list->next;
	return (list);
}

// сколько движений нужно сдлеать, чтобы поднять искомый элемент на вверх стека для дальнейшего перемещени в стек_а
void	count_move_elem_b(t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_listsize(stack_b);
	i = 0;
	while (stack_b)
	{

		stack_b->count_rb = i;
		stack_b->count_rrb = size - i;
        // printf("elem - %d: nbr - %d, rb - %d, rrb - %d\n", i, stack_b->nbr, stack_b->count_rb, stack_b->count_rrb);
		i++;
		stack_b = stack_b->next;

	}
}

// сколько движений необходимо сделать для перемещения элемента из стека_б в нужное место в стеке_а
void	count_move_elem_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack	*temp;
	int		size;
	int		i;
	int		last;

	size = ft_listsize(stack_a);
	temp = stack_a;
	while (stack_b)
	{
		stack_a = temp;
		i = 0;
		last = ft_listlast(stack_a)->nbr;
		while (stack_a)
		{
			if (last < stack_b->nbr && stack_a->nbr > stack_b->nbr)
			{
				stack_b->count_ra = i;
				stack_b->count_rra = size - i;
			}
    	    printf("elem - %d: nbr - %d, ra - %d, rra - %d\n", i, stack_b->nbr, stack_b->count_rb, stack_b->count_rrb);

			i++;
			last = stack_a->nbr;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

void moving_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    // t_stack	*profit_elem;
	// int		move_type;

	count_move_elem_b(*stack_b);
	count_move_elem_a(*stack_a, *stack_b);
}
