/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:54:30 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/07 18:35:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				nbr;
	int				count_ra;
	int				count_rra;
	int				count_rb;
	int				count_rrb;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*fill_stack_a(char **elem);
t_stack	*fill_stack_b(t_stack **stack_a);
t_stack	*ft_listlast(t_stack *list);
t_stack	*before_last_stack_elem(t_stack *stack);
t_stack	*find_profit_elem(t_stack *stack_b, int *move_type);

void	parsing(int argc, char **argv);
void	print_list(t_stack *stack_a);
void	free_matrix(char **res);
void	moving_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void	ft_listadd_front(t_stack ***lst, t_stack *new);
void	ft_listadd_back(t_stack **lst, t_stack *new_elem);
void	processor(t_stack **stack_a, t_stack **stack_b,
			t_stack *profit_elem, int *move_type);
void	stack_add_front(t_stack **stack, t_stack *new);
void	ft_listadd_back(t_stack **lst, t_stack *new_list);
void	final_sort(t_stack **stack_a);
void	sort_three(t_stack **stack_a);

int		*sort_arr(t_stack *elem, int *array, int size);
int		find_values(t_stack **stack_a, int *min, int *max, int *med);
int		ft_listsize(t_stack *lst);
int		find_count_moves(t_stack *stack_b, int *move_type);

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

// void	print_list(t_stack *stack_a);

#endif