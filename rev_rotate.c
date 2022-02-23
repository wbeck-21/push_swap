# include "push_swap.h"

void   	ft_rra(t_stack **stack_a)
{
    t_stack *new_last_elem;
    t_stack *first_elem;
    
    new_last_elem = NULL;
    first_elem = *stack_a;
    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    while (first_elem->next != NULL)
    {
        new_last_elem = first_elem;
        first_elem = first_elem->next;
    }
    new_last_elem->next = NULL;

    first_elem->next = *stack_a; 

    *stack_a = first_elem;
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


void	ft_lstadd_front(t_list ***lst, t_list *new)
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
    t_stack *new_firts_elem;

    new_firts_elem = *stack_b;
    ft_lstadd_front(&stack_a,  new_firts_elem);
}

void    ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *new_firts_elem;

    new_firts_elem = *stack_a;
    ft_lstadd_front(&stack_b,  new_firts_elem);
}
