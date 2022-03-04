# include "push_swap.h"

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

void   	ft_rra(t_stack **stack_a)
{
    t_stack	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = before_last_stack_elem(*stack_a);
		stack_add_front(stack_a, before_last->next);
		before_last->next = NULL;
    }
    write(1, "rra\n", 4);
}

void   	ft_rrb(t_stack **stack_b)
{
    t_stack *new_last_elem;
    t_stack *first_elem;
    
    new_last_elem = NULL;
    first_elem = *stack_b;
    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    while (first_elem->next != NULL)
    {
        new_last_elem = first_elem;
        first_elem = first_elem->next;
    }
    new_last_elem->next = NULL;

    first_elem->next = *stack_b; 

    *stack_b = first_elem;
    write(1, "rrb\n", 4);
}

void    ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
    write(1, "rrr\n", 4);
}


void	ft_listadd_front(t_stack ***lst, t_stack *new)
{
	if (**lst)
	{
		new->next = **lst;
		**lst = new;
	}
	else
		**lst = new;
}

void    ft_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*p_a;
	t_stack	*p_b;

	if (*stack_b)
	{
		p_a = *stack_a;
		p_b = *stack_b;
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = p_b;
		(*stack_a)->next = p_a;
	}
    write(1, "pa\n", 3);
}

void    ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*a;
	t_stack	*b;

	if (*stack_a)
	{
		b = *stack_b;
		a = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = a;
		(*stack_b)->next = b;
	}	

    write(1, "pb\n", 3);
}

