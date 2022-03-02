#ifndef     PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
    int nbr;
    struct s_stack *next;
    int	count_ra;
	int	count_rra;
	int	count_rb;
	int	count_rrb;
} t_stack;

void parsing(int argc, char **argv);
t_stack *fill_stack_a(char **elem);
t_stack *fill_stack_b(t_stack **stack_a);
void print_list(t_stack *stack_a);
void	free_matrix(char **res);
void moving_to_stack_a(t_stack **stack_a, t_stack **stack_b);
int	ft_listsize(t_stack *lst);

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