# include "push_swap.h"

void print_list(t_stack *stack_a)
{
    t_stack *current = stack_a;
    printf("\n\n\nstack_b\n");
    while (current != NULL) 
    {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}

void	free_matrix(char **res)
{
    int i;

    i = 0;
	while (i > 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}

int	ft_listsize(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	else
		return (1 + ft_listsize(lst->next));
}