# include "push_swap.h"

t_stack	*ft_listlast(t_stack *list)
{
	if (list == NULL)
		return (NULL);
	if (list->next == NULL)
		return (list);
	else
		return (ft_listlast(list->next));
}

// // сколько движений нужно сдлеать, чтобы поднять искомый элемент на вверх стека для дальнейшего перемещени в стек_а
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
		i++;
		stack_b = stack_b->next;
	}
}

// // сколько движений необходимо сделать для перемещения элемента из стека_б в нужное место в стеке_а
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
    		i++;
			last = stack_a->nbr;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

int find_count_moves(t_stack *stack_b, int *move_type) //находим наилучшие возможные комбинации для одного элемента
{
	int profit_total_moves;
	int count_rotates;

	*move_type = 1;
	profit_total_moves = stack_b->count_rb;
	count_rotates = stack_b->count_rra;
	if(stack_b->count_ra >= stack_b->count_rb)
	{
		profit_total_moves = stack_b->count_ra;
		*move_type = 2;
	}
	if(stack_b->count_rrb > count_rotates) // rra? 
		count_rotates = stack_b->count_rrb;
	if(profit_total_moves > count_rotates)
	{
		profit_total_moves = count_rotates;
		if (stack_b->count_rrb >= stack_b->count_rra)
			*move_type = 3;
		else
			*move_type = 4;
	}
	if (profit_total_moves > stack_b->count_rra + stack_b->count_rb)
	{
		profit_total_moves = stack_b->count_rra + stack_b->count_rb;
		*move_type = 5;
	}
	if (profit_total_moves > stack_b->count_ra + stack_b->count_rrb)
	{
		profit_total_moves = stack_b->count_ra + stack_b->count_rrb;
		*move_type = 6;
	}
	return (profit_total_moves);
}

t_stack *find_profit_elem(t_stack *stack_b, int *move_type) // ищем элемент с наилучшей комбинацией 
{
    t_stack	*profit_elem;
	int profit_total_moves;
	int profit_comb_moves;
	int profit_index;

	profit_index = stack_b->index; // написать функцию, которая индексы присваивает 
	profit_total_moves = find_count_moves(stack_b, move_type); // вроде не работает, должна показывать общее колво операций
	profit_comb_moves = *move_type;
	profit_elem = stack_b; // будем считать, что первый элемент лучший
	while(stack_b)
	{
		if (find_count_moves(stack_b, move_type) < profit_total_moves || (find_count_moves(stack_b, move_type) == profit_total_moves && stack_b->index >= profit_index))
		{
			profit_total_moves = find_count_moves(stack_b, move_type);
			profit_comb_moves = *move_type;
			profit_index = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	*move_type = profit_comb_moves;
	while(profit_elem->index != profit_index)
		profit_elem = profit_elem->next;
	return (profit_elem);
}

void moving_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		move_type;
	t_stack *profit_elem;

	count_move_elem_b(*stack_b);
	count_move_elem_a(*stack_a, *stack_b);
	profit_elem = find_profit_elem(*stack_b, &move_type);
	processor(stack_a, stack_b, profit_elem, &move_type);
}
