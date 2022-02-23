# include "push_swap.h"
 
void swap(int* a, int* b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void   	ft_sa(t_stack **stack_a)
{
   t_stack *temp = *stack_a;

    if (temp != NULL && temp->next != NULL)
    {
        swap(&temp->nbr, &temp->next->nbr);
        temp = temp->next->next;
        write(1, "sa\n", 3);
    }
    else
        return ;
}

void   	ft_sb(t_stack **stack_b)
{
   t_stack *temp = *stack_b;

    if (temp != NULL && temp->next != NULL)
    {
        swap(&temp->nbr, &temp->next->nbr);
        temp = temp->next->next;
        write(1, "sb\n", 3);
    }
    else
        return ;
}

void    ft_ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_sa(stack_a);
    ft_sb(stack_b);

    write(1, "ss\n", 3);
}
