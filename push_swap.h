#ifndef     PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
    int nbr;
    struct s_stack *next;
} t_stack;

void parsing(int argc, char **argv);

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