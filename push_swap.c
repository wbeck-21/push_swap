# include "push_swap.h"

// parsing char* -> char** -> list
//         ft_strjoin -> ft_split -> ft_lstpush_back

void print_list(t_stack *stack_a)
{
    t_stack *current = stack_a;

    while (current != NULL) 
    {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}

void	ft_listadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

t_stack *init_elem(int elem)
{
    t_stack *elem_stack;

    elem_stack = NULL;
    elem_stack = (t_stack *)malloc(sizeof(t_stack));
    if (!elem_stack)
        return NULL;
    elem_stack->nbr = elem;
    elem_stack->next = NULL;

    return (elem_stack);
}

 t_stack *fill_stack(char **elem)
{
    t_stack *stack_a;
    int i;

    i = 0;
    while (elem[i])
    {
        ft_listadd_back(&stack_a, init_elem(ft_atoi(elem[i])));
        i++;
    }

    return stack_a;
}

int main(int argc, char **argv)
{
    char *str;
    char **res;
    int i;
    t_stack *stack_a;

    stack_a = NULL;
    stack_a = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a)
        return 0;
    i = 1;
    if (argc > 1)
    {
        str = ft_calloc(1, 1);
        if (!str)
        {
            write(1, "Error!\n", 7);
            return 0;
        }
        while (i < argc)
        {
            str = ft_strjoin(str, argv[i]);
            str = ft_strjoin(str, " ");
            i++;
        }
        res = ft_split(str, ' '); //work correct!!
        free(str);

        stack_a = fill_stack(res);
        // print_list(stack_a); checking fulling struct

        free(res);
    }
    else
        write(1, "Error!\n", 7);
    return 0;
}