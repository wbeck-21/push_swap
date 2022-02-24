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

// void full_array(int **array, t_stack **elem)
// {
//     int i;

//     i = 0;
  



static t_stack *fill_stack_b(t_stack **elem)
{
    t_stack *stack_b = NULL;
    int *array;
    int size;
    // int max;
    // int mim;
    // int med;

    size = ft_listsize(*elem);
    array = (int *)malloc(sizeof(int) * size);
    if (!array)
        return NULL;

    int i = 0; //checking
    while (size > 0)
    {
        array[i++] = (*elem)->nbr;
        (*elem) = (*elem)->next;
        size--;
    }
    i = 0;
    while(array[i])
        printf("%d,", array[i++]);
    // full_array(&array)
    // if (size > 3)
    // {

    // }
    // else 
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
    free(res);

   
    }