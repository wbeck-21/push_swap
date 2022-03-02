# include "push_swap.h"

// void check_res(char **res)
// {
//     int i = 0;
//     int j;

//     while(res[i])
//     {
//         j = 0;
//         while(res[i][j])
//         {
//             printf("%s\n", res[i]);
//             j++;
//         }
//         i++;
//     }
// }


int	is_sorted(t_stack *stack_a)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = stack_a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr && flag)
			return (0);
		if (stack_a->nbr > stack_a->next->nbr)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (stack_a && stack_a->nbr > temp->nbr && flag)
		return (0);
	return (1);
}


void parsing(int argc, char **argv)
{
    char *str;
    char **res;
    int i;
    t_stack *stack_a;
    t_stack *stack_b;
   
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
    res = ft_split(str, ' ');
    free(str);

    stack_a = fill_stack_a(res);
    stack_b = fill_stack_b(&stack_a);
    if (stack_b)
        moving_to_stack_a(&stack_a, &stack_b);

    
    // print_list(stack_a); //checking fulling struct
    print_list(stack_b); //checking fulling struct

    free_matrix(res);
}