#ifndef     PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
    int nbr;
    int	count_ra;
	int	count_rra;
	int	count_rb;
	int	count_rrb;
    int index;
    struct s_stack *next;
} t_stack;

void parsing(int argc, char **argv);
t_stack *fill_stack_a(char **elem);
t_stack *fill_stack_b(t_stack **stack_a);
void print_list(t_stack *stack_a);
void	free_matrix(char **res);
void moving_to_stack_a(t_stack **stack_a, t_stack **stack_b);
int	ft_listsize(t_stack *lst);
void	processor(t_stack **stack_a, t_stack **stack_b, t_stack *profit_elem, int *move_type);
int *sort_arr(t_stack *elem, int *array, int size);
int	find_values(t_stack **stack_a, int *min, int *max, int *med);
void	ft_listadd_back(t_stack **lst, t_stack *new_elem);
t_stack	*ft_listlast(t_stack *list);

void   	ft_sa(t_stack **stack_a);
void   	ft_sb(t_stack **stack_b);
void    ft_ss(t_stack **stack_a, t_stack **stack_b);
void   	ft_ra(t_stack **stack_a);
void   	ft_rb(t_stack **stack_b);
void   	ft_rr(t_stack **stack_a, t_stack **stack_b);
void   	ft_rra(t_stack **stack_a);
void   	ft_rrb(t_stack **stack_b);
void    ft_rrr(t_stack **stack_a, t_stack **stack_b);
void    ft_pa(t_stack **stack_a, t_stack **stack_b);
void    ft_pb(t_stack **stack_a, t_stack **stack_b);

#endif