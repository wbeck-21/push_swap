# include "push_swap.h"

void   	ft_ra(t_stack **stack_a)
{
    t_stack *first_elem;
    t_stack *last_elem;
    t_stack *new_head;

    first_elem = *stack_a;
    *stack_a = (*stack_a)->next;
    new_head = *stack_a;
    while (new_head->next)
        new_head = new_head->next;
    last_elem = new_head;
    first_elem->next = NULL;
    last_elem->next = first_elem;
    write(1, "ra\n", 3);
}

void   	ft_rb(t_stack **stack_b)
{
    t_stack *first_elem;
    t_stack *last_elem;
    t_stack *new_head;

    first_elem = *stack_b;
    *stack_b = (*stack_b)->next;
    new_head = *stack_b;
    while (new_head->next)
        new_head = new_head->next;
    last_elem = new_head;
    first_elem->next = NULL;
    last_elem->next = first_elem;
    write(1, "rb\n", 3);
}

void   	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    ft_ra(stack_a);
    ft_rb(stack_b);
}