# include "push_swap.h"
 
// void swap(int* a, int* b)
// {
//     int temp;
    
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

void   	ft_sa(t_stack **stack_a)
{
    t_stack	*p;
	t_stack	*next;

	p = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		next = (*stack_a)->next;
		(*stack_a)->next = next->next;
		next->next = p;
		(*stack_a) = next;
        write(1, "sa\n", 3);
    }
    else
        return ;
}

void   	ft_sb(t_stack **stack_b)
{
 	t_stack	*p;
	t_stack	*next;

	p = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		next = (*stack_b)->next;
		(*stack_b)->next = next->next;
		next->next = p;
		(*stack_b) = next;
        write(1, "sa\n", 3);
    }
    else
        return ;
}

// void    ft_ss(t_stack **stack_a, t_stack **stack_b)
// {
//     ft_sa(stack_a);
//     ft_sb(stack_b);

//     write(1, "ss\n", 3);
// }
