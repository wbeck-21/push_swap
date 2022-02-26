# include "push_swap.h"

void print_list(t_stack *stack_a)
{
    t_stack *current = stack_a;

    while (current != NULL) 
    {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}

int	ft_listsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static void	ft_listadd_back(t_stack **lst, t_stack *new)
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

static t_stack *init_elem(int elem)
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

static t_stack *fill_stack_a(char **elem)
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



int *sort_arr(t_stack *elem, int *array, int size)
{
    int i;
    int j;
    int temp;
    
    i = -1;
	while (++i < size)
	{
        array[i] = elem->nbr;
        elem = elem->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
    return (array);
}

static t_stack *fill_stack_b(t_stack **stack_a)
{
    t_stack *stack_b = NULL;
    int *array;
    int size;
    int min;
    int med;
    int max;

    size = ft_listsize(*stack_a);
    array = (int *)malloc(sizeof(int) * size);
    if (!array)
        return NULL;
    array = sort_arr(*stack_a, array, size); //work
    min = array[0];
    med = array[size / 2];
    max = array[size - 1];

    while (size > 3)
    {
        if ((*stack_a)->nbr == max || (*stack_a)->nbr == med || (*stack_a)->nbr == min)
            ft_ra(stack_a);
        else
        {
            ft_pb(stack_a, &stack_b);
            size--;
        }
    }
    //   triple sort
    
    return stack_b;
}



void parsing(int argc, char **argv)
{
    char *str;
    char **res;
    int i;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_a = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a)
        return ;
    i = 1;
    str = ft_calloc(1, 1);
    if (!str)
    {
        write(1, "Error!\n", 7);
        return ;
    }
    while (i < argc)
    {
        str = ft_strjoin(str, argv[i]);
        str = ft_strjoin(str, " ");
        i++;
    }
    res = ft_split(str, ' '); //work correct!!
    free(str);
    stack_a = fill_stack_a(res);
    stack_b = fill_stack_b(&stack_a);

    // print_list(stack_a); //checking fulling struct
    // print_list(stack_b); //checking fulling struct

    free(res);
    }