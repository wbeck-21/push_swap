# include "push_swap.h"

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

void	sort_triple(t_stack **stack_a)
{
	int	elem_0;
	int	elem_1;
	int	elem_2;
	int	size;

	size = ft_listsize(*stack_a);
	if (size == 3)
	{
		elem_0 = (*stack_a)->nbr;
		elem_1 = (*stack_a)->next->nbr;
		elem_2 = (*stack_a)->next->next->nbr;
		if (elem_0 > elem_2 && elem_0 > elem_1 && elem_1 > elem_2)
			ft_sa(stack_a);
		if (elem_1 > elem_2 && elem_1 > elem_0 && elem_2 > elem_0)
			ft_sa(stack_a);
		if (elem_2 > elem_0 && elem_2 > elem_1 && elem_0 > elem_1)
			ft_sa(stack_a);
	}
}

t_stack *fill_stack_b(t_stack **stack_a)
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
    sort_triple(stack_a);

    return stack_b;
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

    
    elem_stack = (t_stack *)malloc(sizeof(t_stack));
    if (!elem_stack)
        return NULL;
    elem_stack->nbr = elem;
    elem_stack->next = NULL;

    return (elem_stack);
}

t_stack *fill_stack_a(char **elem)
{
    (void) elem;
    int i;
    t_stack *stack_a;

    stack_a = NULL;
    i = 0;
    while (elem[i])
    {
        ft_listadd_back(&stack_a, init_elem(ft_atoi(elem[i])));
        i++;
    }
    return stack_a;
}